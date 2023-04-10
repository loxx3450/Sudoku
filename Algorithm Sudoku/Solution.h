#pragma once
#include "Map.h"
#include "EasyMethod.h"
#include "NormalMethod.h"
#include "HardMethod.h"
#include "ExtremeMethod.h"

class Solution
{
private:
    const int field_size = 3;
    const int map_size = 9;

    int* numbers;
    EasyMethod methods1;
    NormalMethod methods2;
    HardMethod methods3;
    ExtremeMethod methods4;

public:
    Solution():
        numbers{new int [this->map_size]{}}
    {}

    bool lastInField(Field* temp);

    bool lastInRow(Cell* arr);

    bool exceptionInField(Cell** arr, Field* temp, int temp_i, int temp_j);

    bool exceptionInString(Cell** arr, Cell* string, int str_index);

    bool exceptionInColumn(Cell** arr, Cell* column, int col_index);

    bool lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j);

    void makeNotes(Map* map, Field* temp, int temp_i, int temp_j);

    void nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j);

    void nakedCouplesInRow(Cell* row);

    void nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j);

    void nakedTripletsInRow(Cell* row);

    bool onlyOneNote(Map* map);

    ~Solution()
    {
        if (this->numbers != nullptr)
        {
            delete[] this->numbers;   
        }
    }
};