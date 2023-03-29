#include "Field.h"

void Field::numbersInField()
{
    for (int i{}; i < this->count; ++i)
    {
        for (int j{}; j < this->count; ++j)
        {
            if (arr[i][j] != 0)
            {
                this->numbers[arr[i][j] - 1]++;
            }
        }
    }
}

void Field::generate(int** tmp_arr, int i, int j)
{
    for (int string{ i }, index1{}; string < i + this->count; ++string, ++index1)
    {
        for (int column{ j }, index2{}; column < j + this->count; ++column, ++index2)
        {
            this->arr[index1][index2] = tmp_arr[string][column];
        }
    }
}

void Field::show()
{
    for (int i{}; i < this->count; ++i)
    {
        for (int j{}; j < this->count; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Field::isFull()
{
    for (int i{}; i < this->count; ++i)
    {
        for (int j{}; j < this->count; ++j)
        {
            if (this->arr[i][j] >= 1 && this->arr[i][j] <= 9)
            {
                continue;
            }

            return false;
        }
    }

    return true;
}

bool Field::check()
{
    this->numbersInField();

    for (int i{}; i < this->numbers_count; ++i)
    {
        if (this->numbers[i] > 1)
        {
            return false;
        }

        this->numbers[i] = 0;
    }
    return true;
}

int Field::getNum(int i, int j)
{
    return this->arr[i][j];
}

void Field::setNum(int value, int i, int j)
{
    this->arr[i][j] = value;
}