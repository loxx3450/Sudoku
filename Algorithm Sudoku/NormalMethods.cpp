#include "NormalMethods.h"

bool NormalMethods::exceptionInField(Cell** arr, Field* temp, int temp_i, int temp_j)           //!!!!!!!!!!!!!!!!!!!!!!!!
{
    this->clearNumbers();

    this->overrideNumbersWithField(temp);

    for (int i{}; i < this->map_size; ++i)
    {
        if (this->numbers[i] == 0)
        {
            if (this->exception.checkException(arr, temp, i + 1, temp_i, temp_j))
            {
                return true;
            }
        }
    }

    return false;
}

bool NormalMethods::exceptionInString(Cell** arr, Cell* string, int str_index)
{
    this->clearNumbers();

    this->overrideNumbersWithRow(string);

    for (int i{}; i < this->map_size; ++i)
    {
        if (numbers[i] == 0)
        {
            if (this->exception.checkExceptionInString(arr, i + 1, string, str_index))
            {
                return true;
            }
        }
    }

    return false;
}

bool NormalMethods::exceptionInColumn(Cell** arr, Cell* column, int col_index)
{
    this->clearNumbers();

    this->overrideNumbersWithRow(column);

    for (int i{}; i < this->map_size; ++i)
    {
        if (numbers[i] == 0)
        {
            if (this->exception.checkExceptionInColumn(arr, i + 1, column, col_index))
            {
                return true;
            }
        }
    }

    return false;
}