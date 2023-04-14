#pragma once
#include "Map.h"
#include "Point.h"

enum Groups
{
	Couple = 2,
	Triplet = 3
};

class NakedGroup
{
protected:
	const int field_size = 3;
	const int map_size = 9;

public:
	virtual bool nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{

		return false;
	}

	virtual bool nakedCouplesInRow(Cell* row)
	{

		return false;
	}

	virtual bool nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{

		return false;
	}

	virtual bool nakedTripletsInRow(Cell* row)
	{

		return false;
	}
};

