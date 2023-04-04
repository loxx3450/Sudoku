#pragma once
#include "Map.h"
#include "EasyMethods.h"
#include "NormalMethods.h"
#include "HardMethods.h"

class Solution
{
private:
    const int field_size = 3;
    const int map_size = 9;

    int* numbers;
    EasyMethods methods1;
    NormalMethods methods2;
    HardMethods methods3;

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
            delete[] this->numbers;   
        }
    }
};