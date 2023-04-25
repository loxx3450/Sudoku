#include "HiddenGroup.h"

bool HiddenGroup::isNewPoint(int* array, int size, int i)
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

bool HiddenGroup::isNewPoint(Point* array, int size, int i, int j)
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

int HiddenGroup::getCountOfHiddenNumbers(int tmp_size1, int tmp_size2, int tmp_size3)
{
	int count{};

	for (int i{}; i < this->map_size; ++i)
	{
		if (this->numbers[i] == tmp_size1 || this->numbers[i] == tmp_size2 || this->numbers[i] == tmp_size3)
		{
			++count;
		}
	}

	return count;
}

int* HiddenGroup::fillHiddenNumbersWithNumbers(int size, int tmp_size1, int tmp_size2, int tmp_size3)
{
	int* hiddenNumbers = new int[size] {};

	for (int i{}, index{}; i < this->map_size; ++i)
	{
		if (this->numbers[i] == tmp_size1 || this->numbers[i] == tmp_size2 || this->numbers[i] == tmp_size3)
		{
			hiddenNumbers[index++] = i + 1;
		}
	}

	return hiddenNumbers;
}

void HiddenGroup::clearNumbers()
{
	for (int i{}; i < this->map_size; ++i)
	{
		this->numbers[i] = 0;
	}
}

void HiddenGroup::overrideNumbersWithFieldNotes(Field* temp)
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

void HiddenGroup::overrideNumbersWithRowNotes(Cell* row)
{
	for (int i{}; i < this->map_size; ++i)
	{
		for (int j{}; j < this->map_size; ++j)
		{
			if (row[i].inNotes(j + 1))
			{
				this->numbers[j]++;
			}
		}
	}
}

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

bool HiddenGroup::ifOtherCellsNotHaveHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size)
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

bool HiddenGroup::ifOtherCellsNotHaveHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size)
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

bool HiddenGroup::ifHiddenNoteMeetTwice(Cell* row, int* hiddenNumbers, int* array, int size)
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

bool HiddenGroup::ifHiddenNoteMeetTwice(Field* temp, int* hiddenNumbers, Point* array, int size)
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

bool HiddenGroup::ifCellHasSomeOfHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1, int tmp_size2)
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

bool HiddenGroup::ifCellHasSomeOfHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1, int tmp_size2)
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

bool HiddenGroup::ifPassRulesForHiddenTriplets(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1, int tmp_size2)
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

bool HiddenGroup::ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1, int tmp_size2)
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
