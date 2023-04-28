#include "HiddenGroup.h"

bool HiddenGroup::editNotesInField(Field* temp, int* hiddenNumbers, Point* array, int size)
{
	bool flag{ false };

	for (int i{}; i < size; ++i)
	{
		if (temp->getCell(array[i].getX(), array[i].getY())->editNotes(hiddenNumbers, size))
		{
			flag = true;
		}
	}

	return flag;
}

bool HiddenGroup::editNotesInRow(Cell* row, int* hiddenNumbers, int* array, int size)
{
	bool flag{ false };

	for (int i{}; i < size; ++i)
	{
		if (row[array[i]].editNotes(hiddenNumbers, size))
		{
			flag = true;
		}
	}

	return flag;
}
