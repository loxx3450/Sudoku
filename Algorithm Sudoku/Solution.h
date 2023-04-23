#pragma once
#include "Map.h"
#include "EasyMethod.h"
#include "NormalMethod.h"
#include "HardMethod.h"
#include "ExtremeMethod.h"
#include "InsaneMethod.h"

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
    InsaneMethod methods5;

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

    bool nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j);

    bool nakedCouplesInRow(Cell* row);

    bool nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j);

    bool nakedTripletsInRow(Cell* row);

    bool nakedFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j);

    bool nakedFoursomeInRow(Cell* row);

    bool onlyOneNote(Map* map);

    bool hiddenNote(Map* map);

    bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j);

    bool hiddenCouplesInRow(Cell* row);

    bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j);

    bool hiddenTripletsInRow(Cell* row);

    ~Solution()
    {
        if (this->numbers != nullptr)
        {
            delete[] this->numbers;   
        }
    }
};