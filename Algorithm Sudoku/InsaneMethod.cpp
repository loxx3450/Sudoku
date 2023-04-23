#include "InsaneMethod.h"

bool InsaneMethod::hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
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

bool InsaneMethod::hiddenCouplesInRow(Cell* row)
{
	if (hiddenGroup->hiddenCouplesInRow(row))
	{
		return true;
	}

	return false;
}

bool InsaneMethod::hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
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

bool InsaneMethod::hiddenTripletsInRow(Cell* row)
{
	if (hiddenGroup->hiddenTripletsInRow(row))
	{
		return true;
	}

	return false;
}