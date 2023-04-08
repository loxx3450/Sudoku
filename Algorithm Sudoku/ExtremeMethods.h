#pragma once
#include "Map.h"
#include "Methods.h"

class ExtremeMethods : public Methods
{
private:

	void editNotes(Field* tempField, int tempFirstCell_i, int tempFirstCell_j, int tempSecondCell_i, int tempSecondCell_j, Cell* tempCell)
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
					this->editNotes(tempField, tempCell_i, tempCell_j, i, j, tempCell);
				}
			}
		}
	}

	void makeNoteOnCell(Map* map, Field* temp, Cell* string, Cell* column, int temp_i, int temp_j)
	{
		this->clearNumbers();

		this->overrideNumbersWithField(temp);

		this->overrideNumbersWithRow(string);

		this->overrideNumbersWithRow(column);

		for (int index{}; index < this->map_size; ++index)
		{
			if (this->numbers[index] == 0)
			{
				map->getArr()[temp_i][temp_j].addNote(index + 1);
			}
		}
	}

public:
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

	void hiddenCouplesInField(Map* map, Field* temp, int count, int temp_i, int temp_j)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (temp->getCell(i, j)->countOfNotes() == 2 && temp->getNum(i, j) == 0)
				{
					this->findPossibleCouples(temp, temp->getCell(i, j), i, j);
				}
			}

			
		}

		map->takeField(temp, temp_i * 3, temp_j * 3);
	}

};

