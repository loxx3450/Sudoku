#pragma once
#include "HiddenGroup.h"
#include "common.h"

class HiddenFoursome : public HiddenGroup
{
private:

	bool findHiddenFoursomeInField(Field* temp, int count, int* hiddenNumbers);

	bool findHiddenFoursomeInRow(Cell* row, int count, int* hiddenNumbers);

	bool findPossibleHiddenFoursomeInField(Field* temp, int count);

	bool findPossibleHiddenFoursomeInRow(Cell* row, int count);

public:
	virtual bool hiddenFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool hiddenFoursomeInRow(Cell* row) override;
};

