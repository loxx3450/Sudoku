#pragma once
#include "Map.h"

class NakedGroup
{
private:
	const int field_size = 3;
	const int map_size = 9;

	void editNotesInField(Field* tempField, Cell* tempCell, int firstCell_i, int firstCell_j, int secondCell_i, int secondCell_j)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if ((tempField->getNum(i, j) == 0) && ((i != firstCell_i || j != firstCell_j) && (i != secondCell_i || j != secondCell_j)))
				{
					tempField->getCell(i, j)->editNotes(tempCell->getNotes());
				}
			}
		}
	}

	void editNotesInRow(Cell* row, Cell* tempCell, int firstCell_index, int secondCell_index)
	{
		for (int index{}; index < this->map_size; ++index)
		{
			if ((row[index].getNum() == 0) && (index != firstCell_index) && (index != secondCell_index))
			{
				row[index].getCell()->editNotes(tempCell->getNotes());
			}
		}
	}

	void findPossibleCouplesInField(Field* tempField, Cell* tempCell, int cell_i, int cell_j)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if ((tempField->getNum(i, j) == 0) && (*(tempField->getCell(i, j)) == tempCell->getNotes()) && (i != cell_i || j != cell_j))
				{
					this->editNotesInField(tempField, tempCell, cell_i, cell_j, i, j);
				}
			}
		}
	}

	void findPossibleCouplesInRow(Cell* row, Cell* tempCell, int tempCell_index)
	{
		for (int index{}; index < this->map_size; ++index)
		{
			if ((row[index].getNum() == 0) && (*(row[index].getCell()) == tempCell->getNotes()) && (index != tempCell_index))
			{
				this->editNotesInRow(row, tempCell, tempCell_index, index);
			}
		}
	}

public:
	void nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				if (temp->getCell(i, j)->countOfNotes() == 2 && temp->getNum(i, j) == 0)
				{
					this->findPossibleCouplesInField(temp, temp->getCell(i, j), i, j);
				}
			}
		}

		map->takeField(temp, temp_i * 3, temp_j * 3);
	}

	void nakedCouplesInRow(Cell* row)
	{
		for (int index{}; index < this->map_size; ++index)
		{
			if (row[index].countOfNotes() == 2 && row[index].getNum() == 0)
			{
				this->findPossibleCouplesInRow(row, row[index].getCell(), index);
			}
		}
	}
};

