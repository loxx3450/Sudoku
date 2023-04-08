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

    bool exceptionInField(Cell** arr, Field* temp, int temp_i, int temp_j);

    bool exceptionInString(Cell** arr, Cell* string, int str_index);

    bool exceptionInColumn(Cell** arr, Cell* column, int col_index);

   
};

