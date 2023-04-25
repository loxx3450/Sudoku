#include "InsaneMethod.h"

bool InsaneMethod::hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (this->hiddenGroup != nullptr)
	{
		delete this->hiddenGroup;
	}
	this->hiddenGroup = new HiddenCouple{};

	if (this->hiddenGroup->hiddenCouplesInField(map, temp, temp_i, temp_j))
	{
		return true;
	}

	return false;
}

bool InsaneMethod::hiddenCouplesInRow(Cell* row)
{
	if (this->hiddenGroup->hiddenCouplesInRow(row))
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

	if (this->hiddenGroup->hiddenTripletsInField(map, temp, temp_i, temp_j))
	{
		return true;
	}

	return false;
}

bool InsaneMethod::hiddenTripletsInRow(Cell* row)
{
	if (this->hiddenGroup->hiddenTripletsInRow(row))
	{
		return true;
	}

	return false;
}

bool InsaneMethod::hiddenFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (this->hiddenGroup != nullptr)
	{
		delete this->hiddenGroup;
	}
	this->hiddenGroup = new HiddenFoursome{};

	if (this->hiddenGroup->hiddenFoursomeInField(map, temp, temp_i, temp_j))
	{
		return true;
	}

	return false;
}

bool InsaneMethod::hiddenFoursomeInRow(Cell* row)
{
	if (this->hiddenGroup->hiddenFoursomeInRow(row))
	{
		return true;
	}

	return false;
}
