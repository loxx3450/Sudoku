#pragma once
#include "NakedGroup.h"

class NakedTriplet : public NakedGroup
{
private:

	bool isNewPoint(Point* array, int count, int x, int y);

	bool isNewIndex(int* array, int count, int index);

	int fillRemainingNotes(Cell* array, int* remainingNotes);

	bool ifPassRulesForNakedTriplets(Cell* array);

	bool editNotesForTripletsInField(Field* tempField, Cell* array, Point* arr, int count);

	bool editNotesForTripletsInRow(Cell* row, Cell* array, int* arr, int count);

	int fillArraysForField(Field* tempField, Cell* arrayCells, Point* arrayPoints);

	bool findPossibleTripletsInField(Field* tempField);

	int fillArraysForString(Cell* row, Cell* arrayCells, int* arrayIndexes);

	bool findPossibleTripletsInRow(Cell* row, int size);

public:
	virtual bool nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool nakedTripletsInRow(Cell* row) override;
};

