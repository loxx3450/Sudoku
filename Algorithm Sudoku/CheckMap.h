#pragma once
#include "Field.h"

class CheckMap
{
private:
    const int field_size = 3;
    const int map_size = 9;

    void clearNumbers(int* numbers);

public:
    bool checkFields(int** arr);

    bool checkStrings(int** arr, int* numbers);

    bool checkColumns(int** arr, int* numbers);
};

