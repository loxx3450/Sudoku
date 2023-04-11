#pragma once
#include "Map.h"
#include "Method.h"
#include "Point.h"
#include "NakedGroup.h"
#include "NakedCouple.h"
#include "NakedTriplet.h"

class ExtremeMethod : public Method
{
private:
	NakedGroup* nakedGroup = nullptr;

	/*void countNotes(Field* temp)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				for (int g{}; g < this->map_size; ++g)
				{
					if (temp->getCell(i, j)->inNotes(g + 1))
					{
						this->numbers[g]++;
					}
				}

			}
		}
	}

	bool isNewPoint(Point* array, int count, int x, int y)
	{
		for (int i{}; i < count; ++i)
		{
			if (x == array[i].getX() && y == array[i].getY())
			{
				return false;
			}
		}

		return true;
	}

	void clearPoint(Point* array, int count)
	{
		for (int i{}; i < count; ++i)
		{
			array[i] = 0;
		}
	}

	bool isFullPoint(Point* array, int count)
	{
		for (int i{}; i < count; ++i)
		{
			if (-1 == array[i].getX() && -1 == array[i].getY())
			{
				return false;
			}
		}

		return true;
	}

	void addPoint(Point* array, int count, int x, int y)
	{
		for (int i{}; i < count; ++i)
		{
			if (array[i].getX() == -1 && array[i].getY() == -1)
			{
				array[i].set(x, y);
			}
		}
	}

	void editNotes(Field* tempField, Cell* tempCell, int count, Point* array)
	{
		for (int i{}; i < count; ++i)
		{
			tempField->getCell(array[i].getX(), array[i].getY())->editNotes(hiddenNumbers, count);
		}


		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (tempField->getNum(i, j) == 0 && this->isNewPoint(array, count, i, j))
				{
					tempField->getCell(i, j)->editNotes(tempCell->getNotes());
				}
			}
		}
	}

	bool findHiddenGroup(Map* map, Field* temp, int* hiddenNumbers, int count, int temp_i, int temp_j)
	{
		int tmp_count = 0;
		Point* array = new Point[count]{};

		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				for (int index{}; index < count; ++index)
				{
					if (!temp->getCell(i, j)->inNotes(hiddenNumbers[index]))
					{
						break;
					}

					if (index == count - 1)
					{
						array[tmp_count].set(i, j);

						++tmp_count;

						if (tmp_count == count)
						{
							//this->editNotes(temp, temp->getCell(i, j), hiddenNumbers, count, array);

							delete[] array;

							map->takeField(temp, temp_i * 3, temp_j * 3);

							return true;

						}
					}
				}


			}
		}

		return false;
	}

	void editNotes(Field* tempField, Cell* tempCell, int tempFirstCell_i, int tempFirstCell_j, int tempSecondCell_i, int tempSecondCell_j)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (tempField->getNum(i, j) == 0 && ((i != tempFirstCell_i || j != tempFirstCell_j) && (i != tempSecondCell_i || j != tempSecondCell_j)))
				{
					tempField->getCell(i, j)->editNotes(tempCell->getNotes());
				}


			}
		}
	}

	void findPossibleCouples(Field* tempField, Cell* tempCell, int tempCell_i, int tempCell_j)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (tempField->getNum(i, j) == 0 && *(tempField->getCell(i, j)) == tempCell->getNotes() && (i != tempCell_i || j != tempCell_j))
				{
					this->editNotes(tempField, tempCell, tempCell_i, tempCell_j, i, j);
				}
			}
		}
	}*/

	void makeNoteOnCell(Map* map, Field* temp, Cell* string, Cell* column, int temp_i, int temp_j)
	{
		this->clearNumbers();

		this->overrideNumbersWithField(temp);

		this->overrideNumbersWithRow(string);

		this->overrideNumbersWithRow(column);

		map->getArr()[temp_i][temp_j].clearNotes();

		for (int index{}; index < this->map_size; ++index)
		{
			if (this->numbers[index] == 0)
			{
				map->getArr()[temp_i][temp_j].addNote(index + 1);
			}
		}
	}

public:
	ExtremeMethod() :
		Method{}
	{}

	void makeNotes(Map* map, Field* temp, int temp_i, int temp_j)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (temp->getNum(i, j) == 0)
				{
					this->makeNoteOnCell(map, temp, map->getString(temp_i * 3 + i), map->getColumn(temp_j * 3 + j), temp_i * 3 + i, temp_j * 3 + j);
				}
			}
		}
	}

	/*void hiddenCouplesInField(Map* map, Field* temp, int count, int temp_i, int temp_j)
	{
		this->clearNumbers();

		this->countNotes(temp);

		int tmp_count{};

		for (int i{}; i < this->map_size; ++i)
		{
			if (this->numbers[i] == count)
			{
				++tmp_count;
			}
		}

		int* hiddenNumbers;

		if (tmp_count == count)
		{
			int* hiddenNumbers = new int[count] {};

			for (int i{}, index{}; i < this->map_size; ++i)
			{
				if (this->numbers[i] == count)
				{
					hiddenNumbers[index++] = i + 1;
				}
			}

			if (this->findHiddenGroup(map, temp, hiddenNumbers, count, temp_i, temp_j))
			{
				delete[] hiddenNumbers;

				return;
			}
		}
		/*else if (tmp_count > count)
		{
			hiddenNumbers = new int[count] {};

			int index = 0;

			for (int i{}; i < this->map_size; ++i)
			{
				if (this->numbers[i] == count)
				{
					hiddenNumbers[index] = i + 1;
					++index;
				}

				if (index == count)
				{
					if (this->findHiddenGrupp(map, temp, hiddenNumbers, count, temp_i, temp_j))
					{
						delete[] hiddenNumbers;

						return;
					}
					else
					{
						delete[] hiddenNumbers;

						int* hiddenNumbers = new int[count] {};

						index = 0;

						hiddenNumbers[index++] = i + 1;
					}
					
				}
				
			}

			
		}
		else {
			return;
		}
	}
	*/

	void nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{
		if (this->nakedGroup != nullptr)
		{
			delete nakedGroup;
		}
		this->nakedGroup = new NakedCouple{};

		nakedGroup->nakedCouplesInField(map, temp, temp_i, temp_j);
	}
	
	void nakedCouplesInRow(Cell* row)
	{
		nakedGroup->nakedCouplesInRow(row);
	}

	void nakedtripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{
		if (this->nakedGroup != nullptr)
		{
			delete nakedGroup;
		}
		this->nakedGroup = new NakedTriplet{};
		this->nakedGroup->nakedTripletsInField(map, temp, temp_i, temp_j);
	}

	void nakedTripletsInRow(Cell* row)
	{
		this->nakedGroup->nakedTripletsInRow(row);
	}

	bool isOnlyOneNote(Map* map)
	{
		for (int i{}; i < this->map_size; ++i)
		{
			for (int j{}; j < this->map_size; ++j)
			{
				if (map->getArr()[i][j].countOfNotes() == 1)
				{
					for (int index{}; index < this->map_size; ++index)
					{
						if (map->getArr()[i][j].inNotes(index + 1))
						{
							map->setNum(index + 1, i, j);
							map->getArr()[i][j].deleteNotes();

							return true;
						}
					}
				}
			}
		}

		

		return false;
	}

	~ExtremeMethod()
	{
		if (this->nakedGroup != nullptr)
		{
			delete this->nakedGroup;
		}
	}

};

