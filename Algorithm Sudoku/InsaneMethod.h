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
	bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{
		if (this->hiddenGroup != nullptr)
		{
			delete this->hiddenGroup;
		}
		this->hiddenGroup = new HiddenCouple{};

		if (hiddenGroup->hiddenCouplesInField(map, temp, temp_i, temp_j))
		{
			return true;
		}

		return false;
	}

	bool hiddenCouplesInRow(Cell* row)
	{
		if(hiddenGroup->hiddenCouplesInRow(row))
		{
			return true;
		}

		return false;
	}

	bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{
		if (this->hiddenGroup != nullptr)
		{
			delete this->hiddenGroup;
		}
		this->hiddenGroup = new HiddenTriplet{};

		if (hiddenGroup->hiddenTripletsInField(map, temp, temp_i, temp_j))
		{
			return true;
		}

		return false;
	}

	bool hiddenTripletsInRow(Cell* row)
	{
		if (this->hiddenGroup != nullptr)
		{
			delete this->hiddenGroup;
		}
		this->hiddenGroup = new HiddenTriplet{};

		if (hiddenGroup->hiddenTripletsInRow(row))
		{
			return true;
		}

		return false;
	}
};

