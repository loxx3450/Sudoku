#pragma once
#include "HiddenGroup.h"
#include "common.h"
#include "Point.h"

class HiddenTriplet : public HiddenGroup
{
private:

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

	Point* fillPointsArrayWithNumbers(Field* temp, int* hiddenNumbers, int size)
	{
		Point* array = new Point[this->map_size] {};

		Cell* tempCell = new Cell{};

		int count{}, id{};

		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (temp->getCell(i, j)->getNotes() != nullptr)
				{
					tempCell->setCell(temp->getCell(i, j));

					for (int index{}; index < size; ++index)
					{
						if (tempCell->inNotes(hiddenNumbers[index]))
						{
							++count;
						}
					}

					if (count >= 2)
					{
						array[id++].set(i, j);
					}
				}

				count = 0;
			}
		}

		return array;
	}

	bool editNotesInField(Field* temp, int* hiddenNumbers, Point* array)
	{
		bool flag{ false };

		for (int i{}; i < Groups::Triplet; ++i)
		{
			if (temp->getCell(array[i].getX(), array[i].getY())->editNotes(hiddenNumbers, Groups::Triplet))
			{
				flag = true;
			}
		}

		return flag;
	}

	bool ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array, int size)
	{
		int count{};

		for (int i{}; i < size; ++i)
		{
			for (int j{}; j < size; ++j)
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

		return true;
	}

	bool findPossibleHiddenTripletInField(Field* temp, int count)
	{
		int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count);
		Point* array = this->fillPointsArrayWithNumbers(temp, hiddenNumbers, count);

		int size{};

		for (int i{}; i < count; ++i)
		{
			if (array[i].getX() == -1 && array[i].getY() == -1)
			{
				break;
			}

			++size;
		}

		Point* tempArray = new Point[size]{};
		int* tempHiddenNumbers = new int[size] {};

		for (int i{}; i < size - 2; ++i)
		{
			for (int j{ i + 1 }; j < size - 1; ++j)
			{
				for (int g{ j + 1 }; g < size; ++g)
				{
					tempArray[0] = array[i];
					tempArray[1] = array[j];
					tempArray[2] = array[g];

					for (int indexI{}; indexI < size - 2; ++indexI)
					{
						for (int indexJ{ indexI + 1 }; indexJ < size - 1; ++indexJ)
						{
							for (int indexG{ indexJ + 1 }; indexG < size; ++indexG)
							{
								tempHiddenNumbers[0] = hiddenNumbers[indexI];
								tempHiddenNumbers[1] = hiddenNumbers[indexJ];
								tempHiddenNumbers[2] = hiddenNumbers[indexG];

								if (this->ifPassRulesForHiddenTriplets(temp, hiddenNumbers, array, count))
								{
									if (this->editNotesInField(temp, hiddenNumbers, array))
									{
										return true;
									}
								}
							}
						}
					}
				}
			}
		}

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

		int count{};

		for (int i{}; i < this->map_size; ++i)
		{
			if (this->numbers[i] == Groups::Couple || this->numbers[i] == Groups::Triplet)
			{
				++count;
			}
		}

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
};

