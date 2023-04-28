#pragma once
#include "Map.h"

class CommonGroup
{
protected:
	const int map_size = 9;
	const int field_size = 3;
	int* numbers;

	int getCountOfHiddenNumbers(int tmp_size1, int tmp_size2 = 2, int tmp_size3 = 2);

	int* fillHiddenNumbersWithNumbers(int size, int tmp_size1, int tmp_size2 = 2, int tmp_size3 = 2);

	void clearNumbers();

	void overrideNumbersWithFieldNotes(Field* temp);

	void overrideNumbersWithRowNotes(Cell* row);

public:
	CommonGroup() :
		numbers{ new int[this->map_size]{} }
	{}

	~CommonGroup()
	{
		if (this->numbers != nullptr)
		{
			delete[] this->numbers;
		}
	}
};

