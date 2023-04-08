#pragma once
#include "Field.h"

class CheckMap
{
private:
    const int field_size = 3;
    const int map_size = 9;

    void clearNumbers(int* numbers);

public:
    bool checkFields(Cell** arr);

    bool checkStrings(Cell** arr, int* numbers);

    bool checkColumns(Cell** arr, int* numbers);
};

