#pragma once
#include "NakedGroup.h"

class NakedCouple : public NakedGroup
{
private:

	bool editNotesForCouplesInField(Field* tempField, Cell* tempCell, int firstCell_i, int firstCell_j, int secondCell_i, int secondCell_j);

	bool editNotesForCouplesInRow(Cell* row, Cell* tempCell, int firstCell_index, int secondCell_index);

	bool findPossibleCouplesInField(Field* tempField, Cell* tempCell, int cell_i, int cell_j);

	bool findPossibleCouplesInRow(Cell* row, Cell* tempCell, int tempCell_index);

public:

	int fillRemainingNotes(Cell* array, int* remainingNotes, int size) = delete;

	bool ifPassRulesForNakedTriplets(Cell* array, int size) = delete;

	int fillArraysForString(Cell* row, Cell* arrayCells, int* arrayIndexes, int max_size) = delete;

	int fillArraysForField(Field* temp, Cell* arrayCells, Point* arrayPoints, int max_size) = delete;

	bool isNewIndex(int* array, int size, int index) = delete;

	bool isNewPoint(Point* array, int size, int x, int y) = delete;

	bool editNotesInRow(Cell* row, Cell* array, int* arr, int size) = delete;

	bool editNotesInField(Field* tempField, Cell* array, Point* arr, int size) = delete;

	virtual bool nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool nakedCouplesInRow(Cell* row) override;
};

