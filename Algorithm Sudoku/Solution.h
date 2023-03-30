#pragma once
#include "Field.h"

class Solution
{
private:
    const int field_count = 3;
    const int map_count = 9;

    int* numbers;

    void resetTempField(int** temp_field);

    void checkException_Strings(int** arr, int** temp_field, int value, int temp_i);

    void checkException_Columns(int** arr, int** temp_field, int value, int temp_j);

    bool checkException(int** arr, int** temp_field, int value, int temp_i, int temp_j);

    int** createTempField(Field* temp);

    int checkCountInField(Field* temp);

    int checkCountInRow(int* arr);

    void clearNumbers();

    bool isFull(int* arr);

public:
    Solution():
        numbers{new int [this->map_count]{}}
    {}

    bool lastInField(Field* temp);

    bool lastInRow(int* arr);

    bool exceptionInField(int** arr, Field* temp, int temp_i, int temp_j);

    ~Solution()
    {
        if (this->numbers != nullptr)
        {
            //delete[] this->numbers;   //!!!!!!!!!!!!!
        }
    }
};