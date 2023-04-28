#pragma once
#include "common.h"
#include "Map.h"
#include "HiddenGroup.h"
#include "Point.h"

class HiddenCouple : public HiddenGroup
{
private:
	bool ifPassRulesForHiddenCouples(Field* temp, int* hiddenNumbers, Point* array);

	bool ifPassRulesForHiddenCouples(Cell* row, int* hiddenNumbers, int* array);

	bool findPossibleHiddenCoupleInField(Field* temp, int count);

	bool findPossibleHiddenCoupleInRow(Cell* row, int count);

public:

	virtual bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool hiddenCouplesInRow(Cell* row) override;

};

