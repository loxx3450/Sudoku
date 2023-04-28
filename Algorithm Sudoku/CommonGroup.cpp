#include "CommonGroup.h"

int CommonGroup::getCountOfHiddenNumbers(int tmp_size1, int tmp_size2, int tmp_size3)
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

int* CommonGroup::fillHiddenNumbersWithNumbers(int size, int tmp_size1, int tmp_size2, int tmp_size3)
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

void CommonGroup::clearNumbers()
{
	for (int i{}; i < this->map_size; ++i)
	{
		this->numbers[i] = 0;
	}
}

void CommonGroup::overrideNumbersWithFieldNotes(Field* temp)
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

void CommonGroup::overrideNumbersWithRowNotes(Cell* row)
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
