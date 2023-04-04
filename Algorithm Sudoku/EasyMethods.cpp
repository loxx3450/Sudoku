#include "EasyMethods.h"

int EasyMethods::checkCountInNumbers()
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

bool EasyMethods::isRowFull(int* arr)
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

int EasyMethods::findExceptValue()
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (this->numbers[i] == 0)
        {
            return i + 1;
        }
    }
}

bool EasyMethods::lastInField(Field* temp)
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

                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool EasyMethods::lastInRow(int* arr)
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
                if (arr[i] == 0)
                {
                    arr[i] = value;

                    return true;
                }
            }
        }
    }

    return false;

}