#pragma once
#include "common.h"
#include "Map.h"
#include "HiddenGroup.h"
#include "Point.h"

class HiddenCouple : public HiddenGroup
{
private:
	int* fillHiddenNumbersWithNumbers(int size);

	bool editNotesInField_HiddenGroups(Field* temp, int* hiddenNumbers, Point* array);

	bool editNotesInRow_HiddenGroups(Cell* row, int* hiddenNumbers, int* array);

	bool ifPassRulesForHiddenCouples(Field* temp, int* hiddenNumbers, Point* array);

	bool ifPassRulesForHiddenCouples(Cell* row, int* hiddenNumbers, int* array);

	bool findPossibleHiddenGroupInField(Field* temp, int count);

	bool findPossibleHiddenGroupInRow(Cell* row, int count);

public:
	virtual bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool hiddenCouplesInRow(Cell* row) override;

};

