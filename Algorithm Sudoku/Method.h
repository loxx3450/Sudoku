#pragma once
#include "Field.h"
#include "Cell.h"


class Method
{
protected:
	const int map_size = 9;
	const int field_size = 3;

	int* numbers;

	void clearNumbers();

	void overrideNumbersWithField(Field* temp);

	void overrideNumbersWithRow(Cell* arr);

public:
	Method():
		numbers{new int[this->map_size]{}}
	{}

	~Method()
	{
		if (this->numbers != nullptr)
		{
			//delete[] this->numbers;
		}
	}
};