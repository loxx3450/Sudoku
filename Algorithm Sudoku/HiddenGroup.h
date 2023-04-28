#pragma once
#include "CommonGroup.h"
#include "Point.h"

class HiddenGroup : public CommonGroup
{
protected:
	bool editNotesInField(Field* temp, int* hiddenNumbers, Point* array, int size);

	bool editNotesInRow(Cell* row, int* hiddenNumbers, int* array, int size);

public:
	virtual bool hiddenCouplesInRow(Cell* row)
	{


		return false;
	}

	virtual bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}

	virtual bool hiddenTripletsInRow(Cell* row)
	{


		return false;
	}

	virtual bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}

	virtual bool hiddenFoursomeInRow(Cell* row)
	{


		return false;
	}

	virtual bool hiddenFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}
};

