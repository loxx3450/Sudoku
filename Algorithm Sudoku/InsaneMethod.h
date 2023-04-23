#pragma once
#include "Method.h"
#include "Point.h"
#include "Map.h"
#include "HiddenGroup.h"
#include "HiddenCouple.h"
#include "HiddenTriplet.h"

class InsaneMethod : public Method
{
private:
	HiddenGroup* hiddenGroup;

public:
	bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j);

	bool hiddenCouplesInRow(Cell* row);

	bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j);

	bool hiddenTripletsInRow(Cell* row);
};

