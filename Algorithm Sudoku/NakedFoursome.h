#pragma once
#include "ExtendedNakedGroup.h"


class NakedFoursome : public ExtendedNakedGroup
{
private:

	bool findPossibleFoursomeInField(Field* temp);

	bool findPossibleFoursomeInRow(Cell* row, int size);

public:
	virtual bool nakedFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool nakedFoursomeInRow(Cell* row) override;
};

