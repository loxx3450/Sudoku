#pragma once
#include "Field.h"


class Methods
{
protected:
	const int map_size = 9;
	const int field_size = 3;

	int* numbers;

	void clearNumbers();

	void overrideNumbersWithField(Field* temp);

	void overrideNumbersWithRow(int* arr);

public:
	Methods():
		numbers{new int[this->map_size]{}}
	{}

	~Methods()
	{
		if (this->numbers != nullptr)
		{
			//delete[] this->numbers;
		}
	}
};