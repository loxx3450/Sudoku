#pragma once
#include "Map.h"
#include "Point.h"

class HiddenGroup
{
protected:
	const int map_size = 9;
	const int field_size = 3;
	int* numbers;

	bool isNewPoint(int* array, int size, int i);

	bool isNewPoint(Point* array, int size, int i, int j);

	int getCountOfHiddenNumbers(int tmp_size1, int tmp_size2 = 2, int tmp_size3 = 2);

	int* fillHiddenNumbersWithNumbers(int size, int tmp_size1, int tmp_size2 = 2, int tmp_size3 = 2);

	void clearNumbers();

	void overrideNumbersWithFieldNotes(Field* temp);

	void overrideNumbersWithRowNotes(Cell* row);

	bool editNotesInField(Field* temp, int* hiddenNumbers, Point* array, int size);

	bool editNotesInRow(Cell* row, int* hiddenNumbers, int* array, int size);

	bool ifOtherCellsNotHaveHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size);

	bool ifOtherCellsNotHaveHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size);

	bool ifHiddenNoteMeetTwice(Cell* row, int* hiddenNumbers, int* array, int size);

	bool ifHiddenNoteMeetTwice(Field* temp, int* hiddenNumbers, Point* array, int size);

	bool ifCellHasSomeOfHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1, int tmp_size2);

	bool ifCellHasSomeOfHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1, int tmp_size2);

	bool ifPassRulesForHiddenTriplets(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1 = 2, int tmp_size2 = 2);

	bool ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1 = 2, int tmp_size2 = 2);

public:
	HiddenGroup() :
		numbers{new int[9]}
	{}

	virtual bool hiddenCouplesInRow(Cell* row)
	{


		return false;
	}

	virtual bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}

	virtual bool hiddenTripletsInRow(Cell* row)
	{


		return false;
	}

	virtual bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}

	virtual bool hiddenFoursomeInRow(Cell* row)
	{


		return false;
	}

	virtual bool hiddenFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}

	~HiddenGroup()
	{
		if (this->numbers != nullptr)
		{
			delete[] numbers;
		}
	}
};