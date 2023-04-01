#pragma once
#include "Map.h"

class Solution
{
private:
    const int field_size = 3;
    const int map_size = 9;

    int* numbers;

    void resetTempField(int** temp_field);

    void checkException_Strings(int** arr, int** temp_field, int value, int temp_i);

    void checkException_Columns(int** arr, int** temp_field, int value, int temp_j);

    bool checkException(int** arr, int** temp_field, int value, int temp_i, int temp_j);

    int checkLastNumberInStr_Col_Field(Field* temp, int* string, int* column);

    int** createTempField(Field* temp);

    void overrideNumbersWithField(Field* temp);

    int checkCountInNumbers();

    void overrideNumbersWithRow(int* arr);

    void clearNumbers();

    bool isFull(int* arr);

public:
    Solution():
        numbers{new int [this->map_size]{}}
    {}

    bool lastInField(Field* temp);

    bool lastInRow(int* arr);

    bool exceptionInField(int** arr, Field* temp, int temp_i, int temp_j);

    bool lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j);

    ~Solution()
    {
        if (this->numbers != nullptr)
        {
            //delete[] this->numbers;   //!!!!!!!!!!!!!
        }
    }
};