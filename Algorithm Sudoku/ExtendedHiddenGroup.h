#pragma once
#include "HiddenGroup.h"
#include "Point.h"

class ExtendedHiddenGroup : public HiddenGroup
{
protected:
	bool isNewPoint(int* array, int size, int i);

	bool isNewPoint(Point* array, int size, int i, int j);

	bool ifOtherCellsNotHaveHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size);

	bool ifOtherCellsNotHaveHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size);

	bool ifHiddenNoteMeetTwice(Cell* row, int* hiddenNumbers, int* array, int size);

	bool ifHiddenNoteMeetTwice(Field* temp, int* hiddenNumbers, Point* array, int size);

	bool ifCellHasSomeOfHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1, int tmp_size2);

	bool ifCellHasSomeOfHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1, int tmp_size2);

	bool ifPassRulesForHiddenTriplets(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1 = 2, int tmp_size2 = 2);

	bool ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1 = 2, int tmp_size2 = 2);

};

