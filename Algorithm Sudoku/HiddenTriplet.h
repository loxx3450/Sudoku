#pragma once
#include "HiddenGroup.h"
#include "common.h"
#include "Point.h"

class HiddenTriplet : public HiddenGroup
{
private:

	int getCountOfHiddenNumbers();

	int* fillHiddenNumbersWithNumbers(int size);

	bool addPoint(int* hiddenNumbers, Cell* cell, int* array, int size, int id, int i);

	bool addPoint(int* hiddenNumbers, Cell* cell, Point* array, int size, int id, int i, int j);

	int* fillPointsArrayWithNumbers(Cell* row, int* hiddenNumbers, int size);

	Point* fillPointsArrayWithNumbers(Field* temp, int* hiddenNumbers, int size);

	bool isNewPoint(int* array, int size, int i);

	bool isNewPoint(Point* array, int size, int i, int j);

	bool ifHiddenNoteMeetTwice(Cell* row, int* hiddenNumbers, int* array);

	bool ifHiddenNoteMeetTwice(Field* temp, int* hiddenNumbers, Point* array);

	bool ifPassRulesForHiddenTriplets(Cell* row, int* hiddenNumbers, int* array);

	bool ifPassRulesForHiddenTriplets(Field* temp, int* hiddenNumbers, Point* array);

	int getArraySize(int* array, int count);

	int getArraySize(Point* array, int count);

	bool tryAllVariants(Cell* row, int count, int size, int* array, int* hiddenNumbers);

	bool tryAllVariants(Field* temp, int count, int size, Point* array, int* hiddenNumbers);

	bool findHiddenTripletInRow(Cell* row, int count, int* array, int* hiddenNumbers);

	bool findHiddenTripletInField(Field* temp, int count, Point* array, int* hiddenNumbers);

	bool findPossibleHiddenTripletInRow(Cell* row, int count);

	bool findPossibleHiddenTripletInField(Field* temp, int count);

public:
	virtual bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool hiddenTripletsInRow(Cell* row) override;
};