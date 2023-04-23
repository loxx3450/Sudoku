#pragma once
#include "NakedGroup.h"


class NakedFoursome : public NakedGroup
{
private:

	bool findPossibleFoursomeInField(Field* temp)
	{
		int size{ temp->countOfEmptyCells() };

		Cell* arrayCells = new Cell[size]{};
		Point* arrayPoints = new Point[size]{};

		int count = this->fillArraysForField(temp, arrayCells, arrayPoints, Groups::Foursome);
		
		if (count >= Groups::Foursome)
		{
			Cell* temp_arrayCells = new Cell[Groups::Foursome];
			Point* temp_arrayPoints = new Point[Groups::Foursome];

			for (int i{}; i < count - 3; ++i)
			{
				for (int j{ i + 1 }; j < count - 2; ++j)
				{
					for (int g{ j + 1 }; g < count - 1; ++g)
					{
						for (int h{ g + 1 }; h < count; ++h)
						{
							temp_arrayCells[0].setCell(arrayCells[i].getCell());
							temp_arrayCells[1].setCell(arrayCells[j].getCell());
							temp_arrayCells[2].setCell(arrayCells[g].getCell());
							temp_arrayCells[3].setCell(arrayCells[h].getCell());

							if (this->ifPassRulesForNakedTriplets(temp_arrayCells, Groups::Foursome))
							{
								temp_arrayPoints[0].set(arrayPoints[i].getX(), arrayPoints[i].getY());
								temp_arrayPoints[1].set(arrayPoints[j].getX(), arrayPoints[j].getY());
								temp_arrayPoints[2].set(arrayPoints[g].getX(), arrayPoints[g].getY());
								temp_arrayPoints[3].set(arrayPoints[h].getX(), arrayPoints[h].getY());
								if (this->editNotesInField(temp, temp_arrayCells, temp_arrayPoints, Groups::Foursome))
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
			}
			delete[] temp_arrayCells;
			delete[] temp_arrayPoints;
		}

		delete[] arrayCells;
		delete[] arrayPoints;

		return false;
	}

	bool findPossibleFoursomeInRow(Cell* row, int size)
	{
		Cell* arrayCells = new Cell[size]{};
		int* arrayIndexes = new int[size] {};

		int count = this->fillArraysForString(row, arrayCells, arrayIndexes, Groups::Foursome);
		
		if (count >= Groups::Foursome)
		{
			Cell* temp_arrayCells = new Cell[Groups::Foursome];
			int* temp_arrayIndexes = new int[Groups::Foursome];

			for (int i{}; i < count - 3; ++i)
			{
				for (int j{ i + 1 }; j < count - 2; ++j)
				{
					for (int g{ j + 1 }; g < count - 1; ++g)
					{
						for (int h{ g + 1 }; h < count; ++h)
						{
							temp_arrayCells[0].setCell(arrayCells[i].getCell());
							temp_arrayCells[1].setCell(arrayCells[j].getCell());
							temp_arrayCells[2].setCell(arrayCells[g].getCell());
							temp_arrayCells[3].setCell(arrayCells[h].getCell());

							if (this->ifPassRulesForNakedTriplets(temp_arrayCells, Groups::Foursome))
							{
								temp_arrayIndexes[0] = arrayIndexes[i];
								temp_arrayIndexes[1] = arrayIndexes[j];
								temp_arrayIndexes[2] = arrayIndexes[g];
								temp_arrayIndexes[3] = arrayIndexes[h];
								if (this->editNotesInRow(row, temp_arrayCells, temp_arrayIndexes, Groups::Foursome))
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
			}

			delete[] temp_arrayCells;
			delete[] temp_arrayIndexes;
		}

		delete[] arrayCells;
		delete[] arrayIndexes;

		return false;
	}

public:
	virtual bool nakedFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j) override
	{
		if (temp->countOfEmptyCells() < Groups::Foursome)
		{
			return false;
		}

		if (this->findPossibleFoursomeInField(temp))
		{
			map->takeField(temp, temp_i * this->field_size, temp_j * this->field_size);

			return true;
		}

		return false;
	}

	virtual bool nakedFoursomeInRow(Cell* row) override
	{
		int count{};

		for (int i{}; i < this->map_size; ++i)
		{
			if (row[i].getNum() == 0)
			{
				++count;
			}
		}

		if (count < Groups::Foursome)
		{
			return false;
		}

		if (this->findPossibleFoursomeInRow(row, count))
		{
			return true;
		}

		return false;
	}
};

