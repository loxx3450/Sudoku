#pragma once
#include "Field.h"

class Exceptions
{
private:
	const int map_size = 9;
	const int field_size = 3;

	void resetTempField(Field* temp);

	int* createGhostArray(int* arr);

	int findExceptIndex(int* arr);

	int checkCountInArr(int* arr);

	int checkCountInField(Field* temp);

	bool IsValueInField(Field* temp, int value);

	void checkException_Strings(int** arr, Field* temp_field, int value, int temp_i);

	void checkException_Columns(int** arr, Field* temp_field, int value, int temp_j);

	void checkExceptionInString_Field(int** arr, Field* temp, int* ghost_string, int value, int str_index);

	void checkExceptionInString_Columns(int** arr, int* ghost_string, int value);

	void checkExceptionInColumn_Field(int** arr, Field* temp, int* ghost_column, int value, int col_index);

	void checkExceptionInColumn_Strings(int** arr, int* ghost_column, int value);

public:

	bool checkException(int** arr, Field* temp_field, int value, int temp_i, int temp_j);

	bool checkExceptionInString(int** arr, int value, int* string, int str_index);

	bool checkExceptionInColumn(int** arr, int value, int* column, int col_index);
};

