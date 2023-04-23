#include "NakedTriplet.h"



bool NakedTriplet::findPossibleTripletsInField(Field* tempField)
{
	int size{ tempField->countOfEmptyCells() };

	Cell* arrayCells = new Cell[size]{};
	Point* arrayPoints = new Point[size]{};

	int count = this->fillArraysForField(tempField, arrayCells, arrayPoints, Groups::Triplet);

	if (count >= Groups::Triplet)
	{
		Cell* temp_arrayCells = new Cell[Groups::Triplet];
		Point* temp_arrayPoints = new Point[Groups::Triplet];

		for (int i{}; i < count - 2; ++i)
		{
			for (int j{ i + 1 }; j < count - 1; ++j)
			{
				for (int g{ j + 1 }; g < count; ++g)
				{
					temp_arrayCells[0].setCell(arrayCells[i].getCell());
					temp_arrayCells[1].setCell(arrayCells[j].getCell());
					temp_arrayCells[2].setCell(arrayCells[g].getCell());

					if (this->ifPassRulesForNakedTriplets(temp_arrayCells, Groups::Triplet))
					{
						temp_arrayPoints[0].set(arrayPoints[i].getX(), arrayPoints[i].getY());
						temp_arrayPoints[1].set(arrayPoints[j].getX(), arrayPoints[j].getY());
						temp_arrayPoints[2].set(arrayPoints[g].getX(), arrayPoints[g].getY());
						if (this->editNotesInField(tempField, temp_arrayCells, temp_arrayPoints, Groups::Triplet))
						{
							delete[] temp_arrayCells;
							delete[] temp_arrayPoints;
							delete[] arrayCells;
							delete[] arrayPoints;

							return true;
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

	return false;
}

bool NakedTriplet::findPossibleTripletsInRow(Cell* row, int size)
{
	Cell* arrayCells = new Cell[size]{};
	int* arrayIndexes = new int[size] {};

	int count = this->fillArraysForString(row, arrayCells, arrayIndexes, Groups::Triplet);

	if (count >= Groups::Triplet)
	{
		Cell* temp_arrayCells = new Cell[Groups::Triplet];
		int* temp_arrayIndexes = new int[Groups::Triplet];

		for (int i{}; i < count - 2; ++i)
		{
			for (int j{ i + 1 }; j < count - 1; ++j)
			{
				for (int g{ j + 1 }; g < count; ++g)
				{
					temp_arrayCells[0].setCell(arrayCells[i].getCell());
					temp_arrayCells[1].setCell(arrayCells[j].getCell());
					temp_arrayCells[2].setCell(arrayCells[g].getCell());

					if (this->ifPassRulesForNakedTriplets(temp_arrayCells, Groups::Triplet))
					{
						temp_arrayIndexes[0] = arrayIndexes[i];
						temp_arrayIndexes[1] = arrayIndexes[j];
						temp_arrayIndexes[2] = arrayIndexes[g];
						if (this->editNotesInRow(row, temp_arrayCells, temp_arrayIndexes, Groups::Triplet))
						{
							delete[] temp_arrayCells;
							delete[] temp_arrayIndexes;
							delete[] arrayCells;
							delete[] arrayIndexes;

							return true;
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

	return false;
}

bool NakedTriplet::nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (temp->countOfEmptyCells() < Groups::Triplet)
	{
		return false;
	}

	if (this->findPossibleTripletsInField(temp))
	{
		map->takeField(temp, temp_i * this->field_size, temp_j * this->field_size);

		return true;
	}

	return false;
}

bool NakedTriplet::nakedTripletsInRow(Cell* row)
{
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
		return true;
	}

	return false;
}
