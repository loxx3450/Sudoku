#pragma once
#include "Field.h"
#include "Exceptions.h"
#include "Methods.h"

class NormalMethods : private Methods
{
private:
    Exceptions exception;

public:
    NormalMethods() :
        Methods{}
    {}

    bool exceptionInField(int** arr, Field* temp, int temp_i, int temp_j);

    bool exceptionInString(int** arr, int* string, int str_index);

    bool exceptionInColumn(int** arr, int* column, int col_index);

   
};

