#pragma once
#include "common.h"
#include "Map.h"
#include "HiddenGroup.h"
#include "Point.h"

class HiddenCouple : public HiddenGroup
{
private:
	bool ifPassRulesForHiddenCouples(Field* temp, int* hiddenNumbers, Point* array);

	bool ifPassRulesForHiddenCouples(Cell* row, int* hiddenNumbers, int* array);

	bool findPossibleHiddenCoupleInField(Field* temp, int count);

	bool findPossibleHiddenCoupleInRow(Cell* row, int count);

public:
	
	bool isNewPoint(int* array, int size, int i) = delete;

	bool isNewPoint(Point* array, int size, int i, int j) = delete;

	bool ifOtherCellsNotHaveHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size) = delete;

	bool ifOtherCellsNotHaveHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size) = delete;

	bool ifHiddenNoteMeetTwice(Cell* row, int* hiddenNumbers, int* array, int size) = delete;

	bool ifHiddenNoteMeetTwice(Field* temp, int* hiddenNumbers, Point* array, int size) = delete;

	bool ifCellHasSomeOfHiddenNumbers(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1, int tmp_size2) = delete;

	bool ifCellHasSomeOfHiddenNumbers(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1, int tmp_size2) = delete;

	bool ifPassRulesForHiddenTriplets(Cell* row, int* hiddenNumbers, int* array, int size, int tmp_size1 = 2, int tmp_size2 = 2) = delete;

	bool ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array, int size, int tmp_size1 = 2, int tmp_size2 = 2) = delete;



	virtual bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool hiddenCouplesInRow(Cell* row) override;

};

