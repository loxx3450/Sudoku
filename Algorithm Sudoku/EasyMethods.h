#pragma once
#include "Field.h"
#include "Methods.h"

class EasyMethods : private Methods
{
private:

	int checkCountInNumbers();

	bool isRowFull(Cell* arr);

	int findExceptValue();

public:

	EasyMethods():
		Methods{}
	{}
	
	bool lastInField(Field* temp);

	bool lastInRow(Cell* arr);
};

