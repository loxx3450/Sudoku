#pragma once
#include "Field.h"
#include "Exception.h"
#include "Method.h"

class NormalMethod : private Method
{
private:
    Exception exception;

public:
    NormalMethod() :
        Method{}
    {}

    bool exceptionInField(Cell** arr, Field* temp, int temp_i, int temp_j);

    bool exceptionInString(Cell** arr, Cell* string, int str_index);

    bool exceptionInColumn(Cell** arr, Cell* column, int col_index);

   
};

