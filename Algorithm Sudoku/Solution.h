#pragma once
#include "Map.h"

class Solution
{
private:
    const int field_size = 3;
    const int map_size = 9;

    int* numbers;

    void resetTempField(Field* temp);

    int* createGhostArray(int* arr);

    int findExceptValue();

    int findExceptIndex(int* arr);

    bool findValueInField(Field* temp, int value);

    void checkException_Strings(int** arr, Field* temp_field, int value, int temp_i);

    void checkException_Columns(int** arr, Field* temp_field, int value, int temp_j);

    bool checkException(int** arr, Field* temp_field, int value, int temp_i, int temp_j);

    bool checkLastNumberInStr_Col_Field(Map* map, Field* temp, int* string, int* column, int temp_i, int temp_j);

    void checkExceptionInString_Field(int** arr, Field* temp, int* ghost_string, int value, int str_index);

    void checkExceptionInString_Columns(int** arr, int* ghost_string, int value);

    bool checkExceptionInString(int** arr, int value, int* string, int str_index);

    void checkExceptionInColumn_Field(int** arr, Field* temp, int* ghost_column, int value, int col_index);

    void checkExceptionInColumn_Strings(int** arr, int* ghost_column, int value);

    bool checkExceptionInColumn(int** arr, int value, int* column, int col_index);

    void overrideNumbersWithField(Field* temp);

    int checkCountInNumbers();

    int checkCount(int* arr);

    int checkCountInField(Field* temp);

    void overrideNumbersWithRow(int* arr);

    void clearNumbers();

    bool isRowFull(int* arr);

public:
    Solution():
        numbers{new int [this->map_size]{}}
    {}

    bool lastInField(Field* temp);

    bool lastInRow(int* arr);

    bool exceptionInField(int** arr, Field* temp, int temp_i, int temp_j);

    bool exceptionInString(int** arr, int* string, int str_index);

    bool exceptionInColumn(int** arr, int* column, int col_index);

    bool lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j);

    ~Solution()
    {
        if (this->numbers != nullptr)
        {
            //delete[] this->numbers;   //!!!!!!!!!!!!!
        }
    }
};