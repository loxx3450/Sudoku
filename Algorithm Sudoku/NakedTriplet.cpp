#include "NakedTriplet.h"

bool NakedTriplet::isNewPoint(Point* array, int count, int x, int y)
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

bool NakedTriplet::isNewIndex(int* array, int count, int index)
{
	for (int i{}; i < count; ++i)
	{
		if (index == array[i])
		{
			return false;
		}
	}

	return true;
}

int NakedTriplet::fillRemainingNotes(Cell* array, int* remainingNotes)
{
	bool* notes = new bool[this->map_size]{ false };

	bool isAlready{ false };

	int index{};

	for (int i{}; i < Groups::Triplet; ++i)
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

bool NakedTriplet::ifPassRulesForNakedTriplets(Cell* array)
{
	int* remainingNotes = new int[this->map_size]{};

	int count = this->fillRemainingNotes(array, remainingNotes);

	if (count != Groups::Triplet)
	{
		delete[] remainingNotes;

		return false;
	}

	count = 0;

	for (int i{}; i < Groups::Triplet; ++i)
	{
		for (int j{}; j < Groups::Triplet; ++j)
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

bool NakedTriplet::editNotesForTripletsInField(Field* tempField, Cell* array, Point* arr, int count)
{
	bool flag{ false };

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (tempField->getNum(i, j) == 0 && this->isNewPoint(arr, count, i, j))
			{
				for (int g{}; g < count; ++g)
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

bool NakedTriplet::editNotesForTripletsInRow(Cell* row, Cell* array, int* arr, int count)
{
	bool flag{ false };

	for (int i{}; i < this->map_size; ++i)
	{
		if (row[i].getNum() == 0 && this->isNewIndex(arr, count, i))
		{
			for (int j{}; j < count; ++j)
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

int NakedTriplet::fillArraysForField(Field* tempField, Cell* arrayCells, Point* arrayPoints)
{
	int index{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if ((tempField->countOfCellNotes(i, j) >= 2 && tempField->countOfCellNotes(i, j) <= 3) && tempField->getNum(i, j) == 0)
			{
				arrayCells[index].setCell(tempField->getCell(i, j));
				arrayPoints[index].set(i, j);
				index++;
			}
		}
	}

	return index;
}

bool NakedTriplet::findPossibleTripletsInField(Field* tempField)
{
	bool flag{ false };

	int size{ tempField->countOfEmptyCells() };

	Cell* arrayCells = new Cell[size]{};
	Point* arrayPoints = new Point[size]{};

	int count = this->fillArraysForField(tempField, arrayCells, arrayPoints);

	if (count == Groups::Triplet)
	{
		if (this->ifPassRulesForNakedTriplets(arrayCells))
		{
			if (this->editNotesForTripletsInField(tempField, arrayCells, arrayPoints, 3))
			{
				flag = true;
			}
		}
	}
	else if (count > Groups::Triplet)
	{
		Cell* temp_arrayCells = new Cell[Groups::Triplet];
		Point* temp_arrayPoints = new Point[Groups::Triplet];

		for (int i{}; i < count - 2; ++i)
		{
			for (int j{ i + 1 }; j <= count - i + 1; ++j)
			{
				for (int g{ j + 1 }; g < count; ++g)
				{
					temp_arrayCells[0].setCell(arrayCells[i].getCell());
					temp_arrayCells[1].setCell(arrayCells[j].getCell());
					temp_arrayCells[2].setCell(arrayCells[g].getCell());

					if (this->ifPassRulesForNakedTriplets(temp_arrayCells))
					{
						temp_arrayPoints[0].set(arrayPoints[i].getX(), arrayPoints[i].getY());
						temp_arrayPoints[1].set(arrayPoints[j].getX(), arrayPoints[j].getY());
						temp_arrayPoints[2].set(arrayPoints[g].getX(), arrayPoints[g].getY());
						if (this->editNotesForTripletsInField(tempField, temp_arrayCells, temp_arrayPoints, 3))
						{
							flag = true;
						}
					}
				}
			}
		}

		delete[] temp_arrayCells;
		delete[] temp_arrayPoints;
	}
	delete[] arrayCells;
	delete[] arrayPoints;

	return flag;
}

int NakedTriplet::fillArraysForString(Cell* row, Cell* arrayCells, int* arrayIndexes)
{
	int index{};

	for (int i{}; i < this->map_size; ++i)
	{
		if ((row[i].countOfNotes() >= 2 && row[i].countOfNotes() <= 3) && row[i].getNum() == 0)
		{
			arrayCells[index].setCell(row[i].getCell());
			arrayIndexes[index] = i;
			index++;
		}
	}

	return index;
}

bool NakedTriplet::findPossibleTripletsInRow(Cell* row, int size)
{
	bool flag{ false };

	Cell* arrayCells = new Cell[size]{};
	int* arrayIndexes = new int[size] {};

	int count = this->fillArraysForString(row, arrayCells, arrayIndexes);

	if (count == Groups::Triplet)
	{
		if (this->ifPassRulesForNakedTriplets(arrayCells))
		{
			if (this->editNotesForTripletsInRow(row, arrayCells, arrayIndexes, 3))
			{
				flag = true;
			}
		}
	}
	else if (count > Groups::Triplet)
	{
		Cell* temp_arrayCells = new Cell[Groups::Triplet];
		int* temp_arrayIndexes = new int[Groups::Triplet];

		for (int i{}; i < count - 2; ++i)
		{
			for (int j{ i + 1 }; j <= count - i + 1; ++j)
			{
				for (int g{ j + 1 }; g < count; ++g)
				{
					temp_arrayCells[0].setCell(arrayCells[i].getCell());
					temp_arrayCells[1].setCell(arrayCells[j].getCell());
					temp_arrayCells[2].setCell(arrayCells[g].getCell());

					if (this->ifPassRulesForNakedTriplets(temp_arrayCells))
					{
						temp_arrayIndexes[0] = arrayIndexes[i];
						temp_arrayIndexes[1] = arrayIndexes[j];
						temp_arrayIndexes[2] = arrayIndexes[g];
						if (this->editNotesForTripletsInRow(row, temp_arrayCells, temp_arrayIndexes, 3))
						{
							flag = true;
						}
					}
				}
			}
		}

		delete[] temp_arrayCells;
		delete[] temp_arrayIndexes;
	}

	delete[] arrayCells;
	delete[] arrayIndexes;

	return flag;
}

bool NakedTriplet::nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	bool flag{ false };

	if (temp->countOfEmptyCells() < Groups::Triplet)
	{
		return false;
	}

	if (this->findPossibleTripletsInField(temp))
	{
		flag = true;
	}

	if (flag)
	{
		map->takeField(temp, temp_i * this->field_size, temp_j * this->field_size);
	}

	return flag;
}

bool NakedTriplet::nakedTripletsInRow(Cell* row)
{
	bool flag{ false };

	int count{};

	for (int i{}; i < this->map_size; ++i)
	{
		if (row[i].getNum() == 0)
		{
			++count;
		}
	}

	if (count < Groups::Triplet)
	{
		return false;
	}

	if (this->findPossibleTripletsInRow(row, count))
	{
		flag = true;
	}

	return flag;
}
