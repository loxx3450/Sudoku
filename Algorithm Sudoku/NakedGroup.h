#pragma once
#include "Map.h"
#include "Point.h"
#include "common.h"

class NakedGroup
{
protected:
	const int field_size = 3;
	const int map_size = 9;

	int fillRemainingNotes(Cell* array, int* remainingNotes, int size);

	bool ifPassRulesForNakedTriplets(Cell* array, int size);

	int fillArraysForString(Cell* row, Cell* arrayCells, int* arrayIndexes, int max_size);

	int fillArraysForField(Field* temp, Cell* arrayCells, Point* arrayPoints, int max_size);

	bool isNewIndex(int* array, int size, int index);

	bool isNewPoint(Point* array, int size, int x, int y);

	bool editNotesInRow(Cell* row, Cell* array, int* arr, int size);

	bool editNotesInField(Field* tempField, Cell* array, Point* arr, int size);

public:
	virtual bool nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{

		return false;
	}

	virtual bool nakedCouplesInRow(Cell* row)
	{

		return false;
	}

	virtual bool nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{

		return false;
	}

	virtual bool nakedTripletsInRow(Cell* row)
	{

		return false;
	}

	virtual bool nakedFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j)
	{

		return false;
	}

	virtual bool nakedFoursomeInRow(Cell* row)
	{

		return false;
	}
};

