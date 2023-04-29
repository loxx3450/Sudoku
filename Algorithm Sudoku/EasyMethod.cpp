#include "EasyMethod.h"

int EasyMethod::checkCountInNumbers()
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

bool EasyMethod::isRowFull(Cell* arr)
{
    this->clearNumbers();

    this->overrideNumbersWithRow(arr);

    for (int i{}; i < this->map_size; ++i)
    {
        if (this->numbers[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int EasyMethod::findExceptValue()
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (this->numbers[i] == 0)
        {
            return i + 1;
        }
    }
}

bool EasyMethod::lastInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    if (!temp->isFull())
    {
        this->clearNumbers();

        int value{}, count{};

        this->overrideNumbersWithField(temp);

        count = this->checkCountInNumbers();

        if (count == 8)
        {
            value = this->findExceptValue();

            for (int i{}; i < this->field_size; ++i)
            {
                for (int j{}; j < this->field_size; ++j)
                {
                    if (temp->getNum(i, j) == 0)
                    {
                        temp->setNum(value, i, j);

                        map->takeField(temp, temp_i * 3, temp_j * 3);

                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool EasyMethod::lastInRow(Cell* arr)
{
    if (!this->isRowFull(arr))
    {
        int count{}, value{};

        this->overrideNumbersWithRow(arr);

        count = this->checkCountInNumbers();

        if (count == 8)
        {
            value = this->findExceptValue();

            for (int i{}; i < this->map_size; ++i)
            {
                if (arr[i].getNum() == 0)
                {
                    arr[i].setNum(value);

                    return true;
                }
            }
        }
    }

    return false;

}