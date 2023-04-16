#include "NakedCouple.h"

bool NakedCouple::editNotesForCouplesInField(Field* tempField, Cell* tempCell, int firstCell_i, int firstCell_j, int secondCell_i, int secondCell_j)
{
	bool flag{ false };

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if ((tempField->getNum(i, j) == 0) && ((i != firstCell_i || j != firstCell_j) && (i != secondCell_i || j != secondCell_j)))
			{
				if (tempField->editCellNotes(tempCell->getNotes(), i, j))
				{
					flag = true;
				}
			}
		}
	}

	return flag;
}

bool NakedCouple::editNotesForCouplesInRow(Cell* row, Cell* tempCell, int firstCell_index, int secondCell_index)
{
	bool flag{ false };

	for (int index{}; index < this->map_size; ++index)
	{
		if ((row[index].getNum() == 0) && (index != firstCell_index) && (index != secondCell_index))
		{
			if (row[index].editNotes(tempCell->getNotes()))
			{
				flag = true;
			}
		}
	}

	return flag;
}

bool NakedCouple::findPossibleCouplesInField(Field* tempField, Cell* tempCell, int cell_i, int cell_j)
{
	bool flag{ false };

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if ((tempField->getNum(i, j) == 0) && (*tempField->getCell(i, j) == tempCell->getNotes()) && (i != cell_i || j != cell_j))
			{
				if (this->editNotesForCouplesInField(tempField, tempCell, cell_i, cell_j, i, j))
				{
					flag = true;
				}
			}
		}
	}

	return flag;
}

bool NakedCouple::findPossibleCouplesInRow(Cell* row, Cell* tempCell, int tempCell_index)
{
	bool flag{ false };

	for (int index{}; index < this->map_size; ++index)
	{
		if ((row[index].getNum() == 0) && (*row[index].getCell() == tempCell->getNotes()) && (index != tempCell_index))
		{
			if (this->editNotesForCouplesInRow(row, tempCell, tempCell_index, index))
			{
				flag = true;
			}
		}
	}

	return flag;
}

bool NakedCouple::nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	bool flag{ false };

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (temp->countOfCellNotes(i, j) == Groups::Couple && temp->getNum(i, j) == 0)
			{
				if (this->findPossibleCouplesInField(temp, temp->getCell(i, j), i, j))
				{
					flag = true;
				}
			}
		}
	}

	map->takeField(temp, temp_i * 3, temp_j * 3);

	return flag;
}

bool NakedCouple::nakedCouplesInRow(Cell* row)
{
	bool flag{ false };

	for (int index{}; index < this->map_size; ++index)
	{
		if (row[index].countOfNotes() == Groups::Couple && row[index].getNum() == 0)
		{
			if (this->findPossibleCouplesInRow(row, row[index].getCell(), index))
			{
				flag = true;
			}
		}
	}

	return flag;
}