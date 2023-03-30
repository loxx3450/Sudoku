#include "Solution.h"

int Solution::checkCountInField(Field* temp)
{
    int count{};

    for (int i{}; i < this->field_count; ++i)
    {
        for (int j{}; j < this->field_count; ++j)
        {
            this->numbers[temp->getNum(i, j) - 1]++;
        }
    }


    for (int i{}; i < this->map_count; ++i)
    {
        if (this->numbers[i] != 0)
        {
            ++count;
        }
    }

    return count;
}

int Solution::checkCountInRow(int* arr)
{
    int count{};

    for (int i{}; i < this->map_count; ++i)
    {
        this->numbers[arr[i] - 1]++;
    }

    for (int i{}; i < this->map_count; ++i)
    {
        if (this->numbers[i] != 0)
        {
            ++count;
        }
    }

    return count;
}

void Solution::clearNumbers()
{
    for (int i{}; i < this->map_count; ++i)
    {
        this->numbers[i] = 0;
    }
}

bool Solution::isFull(int* arr)
{
    this->clearNumbers();

    for (int i{}; i < this->map_count; ++i)
    {
        this->numbers[arr[i] - 1]++;
    }

    for (int i{}; i < this->map_count; ++i)
    {
        if (this->numbers[i] == 0)
        {
            return false;
        }
    }

    return true;
}

bool Solution::lastInField(Field* temp)
{
    if (!temp->isFull())
    {
        this->clearNumbers();

        int value{}, count{};

        count = checkCountInField(temp);

        if (count == 8)
        {
            for (int i{}; i < this->map_count; ++i)
            {
                if (this->numbers[i] == 0)
                {
                    value = i + 1;
                    break;
                }
            }

            for (int i{}; i < this->field_count; ++i)
            {
                for (int j{}; j < this->field_count; ++j)
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

bool Solution::lastInRow(int* arr)
{
    if (!this->isFull(arr))
    {
        int count{}, value{};

        count = this->checkCountInRow(arr);

        if (count == 8)
        {
            for (int i{}; i < this->map_count; ++i)
            {
                if (this->numbers[i] == 0)
                {
                    value = i + 1;

                    break;
                }
            }

            for (int i{}; i < this->map_count; ++i)
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