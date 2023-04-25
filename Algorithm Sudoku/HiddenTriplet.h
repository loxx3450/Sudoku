#pragma once
#include "HiddenGroup.h"
#include "common.h"
#include "Point.h"

class HiddenTriplet : public HiddenGroup
{
private:

	bool findHiddenTripletInRow(Cell* row, int count, int* hiddenNumbers);

	bool findHiddenTripletInField(Field* temp, int count, int* hiddenNumbers);

	bool findPossibleHiddenTripletInRow(Cell* row, int count);

	bool findPossibleHiddenTripletInField(Field* temp, int count);

public:
	virtual bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool hiddenTripletsInRow(Cell* row) override;
};