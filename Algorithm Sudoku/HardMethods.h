#pragma once
#include "Map.h"
#include "Methods.h"

class HardMethods : private Methods
{
private:
	int checkCountInNumbers();

	bool checkLastNumberInStr_Col_Field(Map* map, Field* temp, Cell* string, Cell* column, int temp_i, int temp_j);

public:
	HardMethods() :
		Methods{}
	{}

	bool lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j);

};

