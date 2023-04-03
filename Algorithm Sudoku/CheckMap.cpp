#include "CheckMap.h"


void CheckMap::clearNumbers(int* numbers)
{
    for (int i{}; i < this->map_size; ++i)
    {
        numbers[i] = 0;
    }
}

bool CheckMap::checkFields(int** arr)
{
    Field* temp = new Field{};
    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            temp->generate(arr, i * this->field_size, j * this->field_size);

            if (!temp->check())
            {
                delete temp;

                return false;
            }
        }
    }

    delete temp;

    return true;
}

bool CheckMap::checkStrings(int** arr, int* numbers)
{
    this->clearNumbers(numbers);

    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            numbers[arr[i][j] - 1]++;
        }

        for (int i{}; i < this->map_size; ++i)
        {
            if (numbers[i] > 1)
            {
                return false;
            }

            numbers[i] = 0;
        }
    }

    return true;
}

bool CheckMap::checkColumns(int** arr, int* numbers)
{
    this->clearNumbers(numbers);

    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            numbers[arr[j][i] - 1]++;
        }

        for (int i{}; i < this->map_size; ++i)
        {
            if (numbers[i] > 1)
            {
                return false;
            }

            numbers[i] = 0;
        }
    }

    return true;
}
