#pragma once
#include "HiddenGroup.h"
#include "common.h"
#include "Point.h"

class HiddenTriplet : public HiddenGroup
{
private:

	int getCountOfHiddenNumbers()
	{
		int count{};

		for (int i{}; i < this->map_size; ++i)
		{
			if (this->numbers[i] == Groups::Couple || this->numbers[i] == Groups::Triplet)
			{
				++count;
			}
		}

		return count;
	}

	int* fillHiddenNumbersWithNumbers(int size)
	{
		int* hiddenNumbers = new int[size] {};

		for (int i{}, index{}; i < this->map_size; ++i)
		{
			if (this->numbers[i] == Groups::Couple || this->numbers[i] == Groups::Triplet)
			{
				hiddenNumbers[index++] = i + 1;
			}
		}

		return hiddenNumbers;
	}

	bool addPoint(Cell* row, int* hiddenNumbers, Cell* cell, int* array, int size, int id, int i)
	{
		int count{};

		if (cell->getNotes() != nullptr)
		{
			for (int index{}; index < size; ++index)
			{
				if (cell->inNotes(hiddenNumbers[index]))
				{
					++count;
				}
			}

			if (count >= 2)
			{
				array[id++] = i;

				return true;
			}
		}

		return false;
	}

	bool addPoint(Field* temp, int* hiddenNumbers, Cell* cell, Point* array, int size, int id, int i, int j)
	{
		int count{};

		if (cell->getNotes() != nullptr)
		{
			for (int index{}; index < size; ++index)
			{
				if (cell->inNotes(hiddenNumbers[index]))
				{
					++count;
				}
			}

			if (count >= 2)
			{
				array[id++].set(i, j);

				return true;
			}
		}

		return false;
	}

	int* fillPointsArrayWithNumbers(Cell* row, int* hiddenNumbers, int size)
	{
		int* array = new int[this->map_size];

		for (int i{}; i < this->map_size; ++i)
		{
			array[i] = -1;
		}

		int id{};

		for (int i{}; i < this->map_size; ++i)
		{
			if (this->addPoint(row, hiddenNumbers, row[i].getCell(), array, size, id, i))
			{
				++id;
			}
		}

		return array;
	}

	Point* fillPointsArrayWithNumbers(Field* temp, int* hiddenNumbers, int size)
	{
		Point* array = new Point[this->map_size] {};

		int id{};

		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (this->addPoint(temp, hiddenNumbers, temp->getCell(i, j), array, size, id, i, j))
				{
					++id;
				}
			}
		}

		return array;
	}

	bool isNewPoint(int* array, int size, int i)
	{
		for (int index{}; index < size; ++index)
		{
			if (array[index] == i)
			{
				return false;
			}
		}

		return true;
	}

	bool isNewPoint(Point* array, int size, int i, int j)
	{
		for (int index{}; index < size; ++index)
		{
			if (array[index].getX() == i && array[index].getY() == j)
			{
				return false;
			}
		}

		return true;
	}

	bool ifPassRulesForHiddenTriplets(Cell* row, int* hiddenNumbers, int* array)
	{
		int count{};

		for (int i{}; i < Groups::Triplet; ++i)
		{
			for (int j{}; j < Groups::Triplet; ++j)
			{
				if (row[array[j]].inNotes(hiddenNumbers[i]))
				{
					++count;
				}
			}

			if (count < 2)
			{
				return false;
			}

			count = 0;
		}

		for (int i{}; i < this->map_size; ++i)
		{
			if (row[i].getNum() == 0 && row[i].getNotes() != nullptr && this->isNewPoint(array, Groups::Triplet, i))
			{
				for (int index{}; index < Groups::Triplet; ++index)
				{
					if (row[i].inNotes(hiddenNumbers[index]))
					{
						return false;
					}
				}
			}
		}

		return true;
	}

	bool ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array)
	{
		int count{};

		for (int i{}; i < Groups::Triplet; ++i)
		{
			for (int j{}; j < Groups::Triplet; ++j)
			{
				if (temp->getCell(array[j].getX(), array[j].getY())->inNotes(hiddenNumbers[i]))
				{
					++count;
				}
			}

			if (count < 2)
			{
				return false;
			}

			count = 0;
		}

		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (temp->getNum(i, j) == 0 && this->isNewPoint(array, Groups::Triplet, i, j))
				{
					for (int index{}; index < Groups::Triplet; ++index)
					{
						if (temp->getCell(i, j)->inNotes(hiddenNumbers[index]))
						{
							return false;
						}
					}
				}
			}
		}

		return true;
	}

	int getArraySize(int* array, int count)
	{
		int size{};

		for (int i{}; i < count; ++i)
		{
			if (array[i] == -1)
			{
				break;
			}

			++size;
		}

		return size;
	}

	int getArraySize(Point* array, int count)
	{
		int size{};

		for (int i{}; i < count; ++i)
		{
			if (array[i].getX() == -1 && array[i].getY() == -1)
			{
				break;
			}
			
			++size;
		}

		return size;
	}

	bool findHiddenTripletInRow(Cell* row, int count, int* array, int* hiddenNumbers)
	{
		int size = this->getArraySize(array, count);

		int* tempArray = new int[Groups::Triplet]{};
		int* tempHiddenNumbers = new int[Groups::Triplet]{};

		for (int i{}; i < size - 2; ++i)
		{
			for (int j{ i + 1 }; j < size - 1; ++j)
			{
				for (int g{ j + 1 }; g < size; ++g)
				{
					tempArray[0] = array[i];
					tempArray[1] = array[j];
					tempArray[2] = array[g];

					for (int indexI{}; indexI < count - 2; ++indexI)
					{
						for (int indexJ{ indexI + 1 }; indexJ < count - 1; ++indexJ)
						{
							for (int indexG{ indexJ + 1 }; indexG < count; ++indexG)
							{
								tempHiddenNumbers[0] = hiddenNumbers[indexI];
								tempHiddenNumbers[1] = hiddenNumbers[indexJ];
								tempHiddenNumbers[2] = hiddenNumbers[indexG];

								if (this->ifPassRulesForHiddenTriplets(row, tempHiddenNumbers, tempArray))
								{
									if (this->editNotesInRow(row, tempHiddenNumbers, tempArray, Groups::Triplet))
									{
										delete[] tempHiddenNumbers;
										delete[] tempArray;

										return true;
									}
								}
							}
						}
					}
				}
			}
		}

		delete[] tempHiddenNumbers;
		delete[] tempArray;

		return false;
	}

	bool findHiddenTripletInField(Field* temp, int count, Point* array, int* hiddenNumbers)
	{
		int size = this->getArraySize(array, count);

		Point* tempArray = new Point[Groups::Triplet]{};
		int* tempHiddenNumbers = new int[Groups::Triplet]{};

		for (int i{}; i < size - 2; ++i)
		{
			for (int j{ i + 1 }; j < size - 1; ++j)
			{
				for (int g{ j + 1 }; g < size; ++g)
				{
					tempArray[0] = array[i];
					tempArray[1] = array[j];
					tempArray[2] = array[g];

					for (int indexI{}; indexI < count - 2; ++indexI)
					{
						for (int indexJ{ indexI + 1 }; indexJ < count - 1; ++indexJ)
						{
							for (int indexG{ indexJ + 1 }; indexG < count; ++indexG)
							{
								tempHiddenNumbers[0] = hiddenNumbers[indexI];
								tempHiddenNumbers[1] = hiddenNumbers[indexJ];
								tempHiddenNumbers[2] = hiddenNumbers[indexG];

								if (this->ifPassRulesForHiddenTriplets(temp, tempHiddenNumbers, tempArray))
								{
									if (this->editNotesInField(temp, tempHiddenNumbers, tempArray, Groups::Triplet))
									{
										delete[] tempHiddenNumbers;
										delete[] tempArray;

										return true;
									}
								}
							}
						}
					}
				}
			}
		}

		delete[] tempHiddenNumbers;
		delete[] tempArray;

		return false;
	}

	bool findPossibleHiddenTripletInRow(Cell* row, int count)
	{
		int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count);
		int* array = this->fillPointsArrayWithNumbers(row, hiddenNumbers, count);

		if (this->findHiddenTripletInRow(row, count, array, hiddenNumbers))
		{
			delete[] array;
			delete[] hiddenNumbers;

			return true;
		}

		delete[] array;
		delete[] hiddenNumbers;

		return false;
	}

	bool findPossibleHiddenTripletInField(Field* temp, int count)
	{
		int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count);
		Point* array = this->fillPointsArrayWithNumbers(temp, hiddenNumbers, count);

		if (this->findHiddenTripletInField(temp, count, array, hiddenNumbers))
		{
			delete[] array;
			delete[] hiddenNumbers;

			return true;
		}

		delete[] array;
		delete[] hiddenNumbers;

		return false;
	}

public:
	virtual bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j) override
	{
		if (temp->countOfEmptyCells() < Groups::Triplet)
		{
			return false;
		}

		this->clearNumbers();

		this->overrideNumbersWithFieldNotes(temp);

		int count = this->getCountOfHiddenNumbers();

		if (count < Groups::Triplet)
		{
			return false;
		}

		if (this->findPossibleHiddenTripletInField(temp, count))
		{
			map->takeField(temp, temp_i * 3, temp_j * 3);

			return true;
		}

		return false;
	}

	virtual bool hiddenTripletsInRow(Cell* row) override
	{
		this->clearNumbers();

		this->overrideNumbersWithRowNotes(row);

		int count = this->getCountOfHiddenNumbers();

		if (count < Groups::Triplet)
		{
			return false;
		}

		if (this->findPossibleHiddenTripletInRow(row, count))
		{
			return true;
		}

		return false;
	}
};

