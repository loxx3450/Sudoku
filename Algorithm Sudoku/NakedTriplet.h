#pragma once
#include "ExtendedNakedGroup.h"

class NakedTriplet : public ExtendedNakedGroup
{
private:

	bool findPossibleTripletsInField(Field* tempField);

	bool findPossibleTripletsInRow(Cell* row, int size);

public:
	virtual bool nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool nakedTripletsInRow(Cell* row) override;
};

