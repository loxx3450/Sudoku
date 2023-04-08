#pragma once
#include "Map.h"
#include "Method.h"

class HardMethod : private Method
{
private:
	int checkCountInNumbers();

	bool checkLastNumberInStr_Col_Field(Map* map, Field* temp, Cell* string, Cell* column, int temp_i, int temp_j);

public:
	HardMethod() :
		Method{}
	{}

	bool lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j);

};

