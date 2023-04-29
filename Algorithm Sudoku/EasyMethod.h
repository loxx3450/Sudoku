#pragma once
#include "Map.h"
#include "Method.h"

class EasyMethod : private Method
{
private:

	int checkCountInNumbers();

	bool isRowFull(Cell* arr);

	int findExceptValue();

public:

	EasyMethod():
		Method{}
	{}

	bool lastInField(Map* map, Field* temp, int temp_i, int temp_j);

	bool lastInRow(Cell* arr);

	
};

