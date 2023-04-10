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
	
	virtual void nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{

	}

	virtual void nakedCouplesInRow(Cell* row)
	{

	}

	virtual void nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{

	}

	virtual void nakedTripletsInRow(Cell* row)
	{

	}
};

