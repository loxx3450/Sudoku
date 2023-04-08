#pragma once
#include "Field.h"
#include "Cell.h"

class Exceptions
{
private:
	const int map_size = 9;
	const int field_size = 3;

	void resetTempField(Field* temp);

	Cell* createGhostArray(Cell* arr);

	int findExceptIndex(Cell* arr);

	int checkCountInArr(Cell* arr);

	int checkCountInField(Field* temp);

	bool IsValueInField(Field* temp, int value);

	void checkException_Strings(Cell** arr, Field* temp_field, int value, int temp_i);

	void checkException_Columns(Cell** arr, Field* temp_field, int value, int temp_j);

	void checkExceptionInString_Field(Cell** arr, Field* temp, Cell* ghost_string, int value, int str_index);

	void checkExceptionInString_Columns(Cell** arr, Cell* ghost_string, int value);

	void checkExceptionInColumn_Field(Cell** arr, Field* temp, Cell* ghost_column, int value, int col_index);

	void checkExceptionInColumn_Strings(Cell** arr, Cell* ghost_column, int value);

public:

	bool checkException(Cell** arr, Field* temp_field, int value, int temp_i, int temp_j);

	bool checkExceptionInString(Cell** arr, int value, Cell* string, int str_index);

	bool checkExceptionInColumn(Cell** arr, int value, Cell* column, int col_index);
};

