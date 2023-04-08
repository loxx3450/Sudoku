#pragma once
#include "Field.h"
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
	
	bool lastInField(Field* temp);

	bool lastInRow(Cell* arr);
};

