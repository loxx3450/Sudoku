#include "NakedGroup.h"

int NakedGroup::fillRemainingNotes(Cell* array, int* remainingNotes, int size)
{
	bool* notes = new bool[this->map_size]{ false };

	bool isAlready{ false };

	int index{};

	for (int i{}; i < size; ++i)
	{
		for (int j{}; j < this->map_size; ++j)
		{
			notes[j] = array[i].inNotes(j + 1);

			if (notes[j] == true)
			{
				for (int g{}; g < this->map_size; ++g)
				{
					if (remainingNotes[g] == j + 1)
					{
						isAlready = true;
						break;
					}
				}

				if (!isAlready)
				{
					remainingNotes[index++] = j + 1;
				}

				isAlready = false;
			}
		}
	}

	return index;
}

bool NakedGroup::ifPassRulesForNakedTriplets(Cell* array, int size)
{
	int* remainingNotes = new int[this->map_size]{};

	int count = this->fillRemainingNotes(array, remainingNotes, size);

	if (count != size)
	{
		delete[] remainingNotes;

		return false;
	}

	count = 0;

	for (int i{}; i < size; ++i)
	{
		for (int j{}; j < size; ++j)
		{
			if (array[j].inNotes(remainingNotes[i]) == true)
			{
				++count;
			}
		}

		if (count < 2)
		{
			delete[] remainingNotes;

			return false;
		}

		count = 0;

	}

	delete[] remainingNotes;

	return true;
}

int NakedGroup::fillArraysForString(Cell* row, Cell* arrayCells, int* arrayIndexes, int max_size)
{
	int index{};

	for (int i{}; i < this->map_size; ++i)
	{
		if ((row[i].countOfNotes() >= Groups::Couple && row[i].countOfNotes() <= max_size) && row[i].getNum() == 0)
		{
			arrayCells[index].setCell(row[i].getCell());
			arrayIndexes[index] = i;
			index++;
		}
	}

	return index;
}

int NakedGroup::fillArraysForField(Field* temp, Cell* arrayCells, Point* arrayPoints, int max_size)
{
	int index{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if ((temp->countOfCellNotes(i, j) >= Groups::Couple && temp->countOfCellNotes(i, j) <= max_size) && temp->getNum(i, j) == 0)
			{
				arrayCells[index].setCell(temp->getCell(i, j));
				arrayPoints[index].set(i, j);
				index++;
			}
		}
	}

	return index;
}

bool NakedGroup::isNewIndex(int* array, int size, int index)
{
	for (int i{}; i < size; ++i)
	{
		if (index == array[i])
		{
			return false;
		}
	}

	return true;
}

bool NakedGroup::isNewPoint(Point* array, int size, int x, int y)
{
	for (int i{}; i < size; ++i)
	{
		if (x == array[i].getX() && y == array[i].getY())
		{
			return false;
		}
	}

	return true;
}

bool NakedGroup::editNotesInRow(Cell* row, Cell* array, int* arr, int size)
{
	bool flag{ false };

	for (int i{}; i < this->map_size; ++i)
	{
		if (row[i].getNum() == 0 && this->isNewIndex(arr, size, i))
		{
			for (int j{}; j < size; ++j)
			{
				if (array[j].getNotes() != nullptr && row[i].getNotes() != nullptr)
				{
					if (row[i].editNotes(array[j].getNotes()))
					{
						flag = true;
					}
				}
			}
		}
	}

	return flag;
}

bool NakedGroup::editNotesInField(Field* tempField, Cell* array, Point* arr, int size)
{
	bool flag{ false };

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (tempField->getNum(i, j) == 0 && this->isNewPoint(arr, size, i, j))
			{
				for (int g{}; g < size; ++g)
				{
					if (tempField->editCellNotes(array[g].getNotes(), i, j))
					{
						flag = true;
					}
				}
			}
		}
	}

	return flag;
}
