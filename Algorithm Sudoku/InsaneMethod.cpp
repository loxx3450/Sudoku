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

bool InsaneMethod::pointingGroupInField(Map* map, Field* temp, int temp_i, int temp_j, int size)
{
	if (this->pointingGroup->PointingGroupInField(map, temp, temp_i, temp_j, size))
	{
		return true;
	}

	return false;
}

bool InsaneMethod::pointingGroupInString(Map* map, Cell* string, int temp_i, int string_i, int size)
{
	if (this->pointingGroup->PointingGroupInString(map, string, temp_i, string_i, size))
	{
		return true;
	}

	return false;
}

bool InsaneMethod::pointingGroupInColumn(Map* map, Cell* string, int temp_j, int column_j, int size)
{
	if (this->pointingGroup->PointingGroupInColumn(map, string, temp_j, column_j, size))
	{
		return true;
	}

	return false;
}
