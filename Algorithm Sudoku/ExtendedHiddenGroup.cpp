#include "ExtendedHiddenGroup.h"


bool ExtendedHiddenGroup::isNewPoint(int* array, int size, int i)
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

bool ExtendedHiddenGroup::isNewPoint(Point* array, int size, int i, int j)
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

bool ExtendedHiddenGroup::ifOtherCellsNotHaveHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size)
{
	for (int i{}; i < this->map_size; ++i)
	{
		if (row[i].getNum() == 0 && this->isNewPoint(array, size, i))
		{
			for (int index{}; index < size; ++index)
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

bool ExtendedHiddenGroup::ifOtherCellsNotHaveHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size)
{
	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (temp->getNum(i, j) == 0 && this->isNewPoint(array, size, i, j))
			{
				for (int index{}; index < size; ++index)
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

bool ExtendedHiddenGroup::ifHiddenNoteMeetTwice(Cell* row, int* hiddenNumbers, int* array, int size)
{
	int count{};

	for (int i{}; i < size; ++i)
	{
		for (int j{}; j < size; ++j)
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

	return true;
}

bool ExtendedHiddenGroup::ifHiddenNoteMeetTwice(Field* temp, int* hiddenNumbers, Point* array, int size)
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

bool ExtendedHiddenGroup::ifCellHasSomeOfHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1, int tmp_size2)
{
	int count{}, tmp_count{};

	for (int i{}; i < this->map_size; ++i)
	{
		for (int index{}; index < size; ++index)
		{
			if (row[i].inNotes(hiddenNumbers[index]))
			{
				++tmp_count;
			}
		}

		if (tmp_count == size || tmp_count == tmp_size1 || tmp_count == tmp_size2)
		{
			array[count++] = i;

			if (count == size)
			{
				return true;
			}
		}

		tmp_count = 0;
	}

	return false;
}

bool ExtendedHiddenGroup::ifCellHasSomeOfHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1, int tmp_size2)
{
	int count{}, tmp_count{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			for (int index{}; index < size; ++index)
			{
				if (temp->getCell(i, j)->inNotes(hiddenNumbers[index]))
				{
					++tmp_count;
				}
			}

			if (tmp_count == size || tmp_count == tmp_size1 || tmp_count == tmp_size2)
			{
				array[count++].set(i, j);

				if (count == size)
				{
					return true;
				}
			}

			tmp_count = 0;
		}
	}

	return false;
}

bool ExtendedHiddenGroup::ifPassRulesForHiddenTriplets(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1, int tmp_size2)
{
	if (this->ifCellHasSomeOfHiddenNumbers(row, hiddenNumbers, array, size, tmp_size1, tmp_size2))
	{
		if (this->ifHiddenNoteMeetTwice(row, hiddenNumbers, array, size))
		{
			if (this->ifOtherCellsNotHaveHiddenNumbers(row, hiddenNumbers, array, size))
			{
				return true;
			}
		}
	}

	return false;
}

bool ExtendedHiddenGroup::ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1, int tmp_size2)
{
	if (this->ifCellHasSomeOfHiddenNumbers(temp, hiddenNumbers, array, size, tmp_size1, tmp_size2))
	{
		if (this->ifHiddenNoteMeetTwice(temp, hiddenNumbers, array, size))
		{
			if (this->ifOtherCellsNotHaveHiddenNumbers(temp, hiddenNumbers, array, size))
			{
				return true;
			}
		}
	}

	return false;
}

