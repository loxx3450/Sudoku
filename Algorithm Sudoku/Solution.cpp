#include "Solution.h"

void Solution::resetTempField(int** temp_field)
{
    for (int i{}; i < this->field_count; ++i)
    {
        for (int j{}; j < this->field_count; ++j)
        {
            if (temp_field[i][j] == 10)
            {
                temp_field[i][j] = 0;
            }
        }
    }
}

void Solution::checkException_Strings(int** arr, int** temp_field, int value, int temp_i)
{
    for (int i{ temp_i }; i < temp_i + this->field_count; ++i)
    {
        for (int j{}; j < this->map_count; ++j)
        {
            if (arr[i][j] == value)
            {
                for (int field_j{}; field_j < this->field_count; ++field_j)
                {
                    if (temp_field[i % this->field_count][field_j] == 0)
                    {
                        temp_field[i % this->field_count][field_j] = 10;
                    }
                }
            }
        }
    }
}

void Solution::checkException_Columns(int** arr, int** temp_field, int value, int temp_j)
{
    for (int i{  }; i < this->map_count; ++i)
    {
        for (int j{ temp_j }; j < temp_j + this->field_count; ++j)
        {
            if (arr[i][j] == value)
            {
                for (int field_i{}; field_i < this->field_count; ++field_i)
                {
                    if (temp_field[field_i][j % this->field_count] == 0)
                    {
                        temp_field[field_i][j % this->field_count] = 10;
                    }
                }
            }
        }
    }
}

bool Solution::checkException(int** arr, int** temp_field, int value, int temp_i, int temp_j)
{

    this->resetTempField(temp_field);

    checkException_Strings(arr, temp_field, value, temp_i * 3);

    checkException_Columns(arr, temp_field, value, temp_j * 3);

    int count{};

    for (int i{}; i < this->field_count; ++i)
    {
        for (int j{}; j < this->field_count; ++j)
        {
            if (temp_field[i][j] != 0)
            {
                ++count;
            }
        }
    }

    if (count == 8)
    {
        for (int i{}; i < this->field_count; ++i)
        {
            for (int j{}; j < this->field_count; ++j)
            {
                if (temp_field[i][j] == 0)
                {
                    arr[temp_i * this->field_count + i][temp_j * this->field_count + j] = value;

                    return true;
                }
            }
        }
    }

    return false;
}

int** Solution::createTempField(Field* temp)
{
    int** temp_field = new int* [this->field_count];

    for (int i{}; i < this->field_count; ++i)
    {
        temp_field[i] = new int[this->field_count];
    }

    for (int i{}; i < this->field_count; ++i)
    {
        for (int j{}; j < this->field_count; ++j)
        {
            temp_field[i][j] = temp->getNum(i, j);
        }
    }

    return temp_field;
}

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

bool Solution::exceptionInField(int** arr, Field* temp, int temp_i, int temp_j)
{
    this->clearNumbers();

    int** temp_field = this->createTempField(temp);

    int count{}, value{};

    for (int i{}; i < this->field_count; ++i)
    {
        for (int j{}; j < this->field_count; ++j)
        {
            this->numbers[temp->getNum(i, j) - 1]++;
        }
    }

    for (int i{}; i < this->map_count; ++i)
    {
        if (this->numbers[i] == 0)
        {
            if (checkException(arr, temp_field, i + 1, temp_i, temp_j))
            {
                return true;
            }
        }
    }

    return false;
}
