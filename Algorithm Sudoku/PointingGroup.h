#pragma once
#include "Map.h"
#include "common.h"
#include "Point.h"
#include "CommonGroup.h"

class PointingGroup : public CommonGroup
{
private:
	bool isNewPoint(int* array, int size, int i);

	bool findPossiblePointingGroupInField(Field* temp, int value, Point* array, int size);

	bool findPossiblePointingGroupInRow(Cell* row, int value, int* array, int size);

	bool ifPassRulesForPointingGroupInField_String(Point* array, int size);

	bool ifPassRulesForPointingGroupInField_Column(Point* array, int size);

	bool ifPassRulesForPointingGroupInRow(int* array, int size);

	bool editString(Map* map, Point* array, int value, int temp_i, int temp_j, int size);

	bool editColumn(Map* map, Point* array, int value, int temp_i, int temp_j, int size);

	bool editFieldForString(Map* map, int* array, int value, int temp_i, int string_i);

	bool editFieldForColumn(Map* map, int* array, int value, int temp_j, int column_j);

	bool findPointingGroupInField(Map* map, Field* temp, int count, int temp_i, int temp_j, int size);

	bool findPointingGroupInString(Map* map, Cell* row, int count, int temp_i, int string_i, int size);

	bool findPointingGroupInColumn(Map* map, Cell* row, int count, int temp_j, int column_j, int size);

public:
	bool PointingGroupInField(Map* map, Field* temp, int temp_i, int temp_j, int size);

	bool PointingGroupInString(Map* map, Cell* row, int temp_i, int string_i, int size);

	bool PointingGroupInColumn(Map* map, Cell* row, int temp_j, int column_j, int size);
};

