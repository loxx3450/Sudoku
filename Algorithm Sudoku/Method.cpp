#include "Method.h"

void Method::clearNumbers()
{
    for (int i{}; i < this->map_size; ++i)
    {
        this->numbers[i] = 0;
    }
}

void Method::overrideNumbersWithField(Field* temp)
{
    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            this->numbers[temp->getNum(i, j) - 1]++;
        }
    }
}

void Method::overrideNumbersWithRow(Cell* arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        this->numbers[arr[i].getNum() - 1]++;
    }
}
