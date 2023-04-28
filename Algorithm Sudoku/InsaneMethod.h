#pragma once
#include "Method.h"
#include "Point.h"
#include "Map.h"
#include "HiddenGroup.h"
#include "HiddenCouple.h"
#include "HiddenTriplet.h"
#include "HiddenFoursome.h"
#include "PointingGroup.h"

class InsaneMethod : public Method
{
private:
	HiddenGroup* hiddenGroup;
	PointingGroup* pointingGroup;

public:
	InsaneMethod() :
		Method{},
		hiddenGroup{nullptr},
		pointingGroup{new PointingGroup}
	{}

	bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j);

	bool hiddenCouplesInRow(Cell* row);

	bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j);

	bool hiddenTripletsInRow(Cell* row);

	bool hiddenFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j);
	
	bool hiddenFoursomeInRow(Cell* row);

	bool pointingGroupInField(Map* map, Field* temp, int temp_i, int temp_j, int size);

	bool pointingGroupInString(Map* map, Cell* string, int temp_i, int string_i, int size);

	bool pointingGroupInColumn(Map* map, Cell* string, int temp_j, int column_j, int size);

	~InsaneMethod()
	{
		if (this->pointingGroup != nullptr)
		{
			delete this->pointingGroup;
		}
		if (this->hiddenGroup != nullptr)
		{
			delete this->hiddenGroup;
		}
	}
};

