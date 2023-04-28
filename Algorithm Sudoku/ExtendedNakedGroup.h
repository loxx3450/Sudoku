#pragma once
#include "NakedGroup.h"

class ExtendedNakedGroup : public NakedGroup
{
protected:
	int fillRemainingNotes(Cell* array, int* remainingNotes, int size);

	bool ifPassRulesForNakedTriplets(Cell* array, int size);

	int fillArraysForString(Cell* row, Cell* arrayCells, int* arrayIndexes, int max_size);

	int fillArraysForField(Field* temp, Cell* arrayCells, Point* arrayPoints, int max_size);

	bool isNewIndex(int* array, int size, int index);

	bool isNewPoint(Point* array, int size, int x, int y);

	bool editNotesInRow(Cell* row, Cell* array, int* arr, int size);

	bool editNotesInField(Field* tempField, Cell* array, Point* arr, int size);
};
