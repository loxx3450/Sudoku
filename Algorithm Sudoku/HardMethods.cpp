#include "HardMethods.h"

int HardMethods::checkCountInNumbers()
{
    int count{};

    for (int i{}; i < this->map_size; ++i)
    {
        if (this->numbers[i] != 0)
        {
            ++count;
        }
    }

    return count;
}

bool HardMethods::checkLastNumberInStr_Col_Field(Map* map, Field* temp, int* string, int* column, int temp_i, int temp_j)
{
    this->clearNumbers();

    this->overrideNumbersWithField(temp);

    this->overrideNumbersWithRow(string);

    this->overrideNumbersWithRow(column);

    int count = this->checkCountInNumbers();

    if (count == 8)
    {
        for (int i{}; i < this->map_size; ++i)
        {
            if (this->numbers[i] == 0)
            {
                map->setNum(i + 1, temp_i, temp_j);

                return true;
            }
        }
    }

    return false;
}

bool HardMethods::lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j)
{
    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            if (temp->getNum(i, j) == 0)
            {
                if (this->checkLastNumberInStr_Col_Field(map, temp, map->getString(temp_i * 3 + i), map->getColumn(temp_j * 3 + j), temp_i * 3 + i, temp_j * 3 + j))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
