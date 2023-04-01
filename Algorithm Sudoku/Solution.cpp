#include "Solution.h"

void Solution::resetTempField(Field* temp)
{
    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            if (temp->getNum(i, j) == 10)
            {
                temp->setNum(0, i, j);
            }
        }
    }
}

int Solution::findExceptValue()
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (this->numbers[i] == 0)
        {
            return i + 1;
        }
    }
}

int Solution::findExceptIndex(int* arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (arr[i] == 0)
        {
            return i;
        }
    }
}

bool Solution::findValueInField(Field* temp, int value)
{
    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            if (temp->getNum(i, j) == value)
            {
                return true;
            }
        }
    }

    return false;
}

void Solution::checkException_Strings(int** arr, Field* temp_field, int value, int temp_i)
{
    for (int i{ temp_i }; i < temp_i + this->field_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            if (arr[i][j] == value)
            {
                for (int field_j{}; field_j < this->field_size; ++field_j)
                {
                    if (temp_field->getNum(i % this->field_size, field_j) == 0)
                    {
                        temp_field->setNum(10, i % this->field_size, field_j);
                    }
                }
            }
        }
    }
}

void Solution::checkException_Columns(int** arr, Field* temp_field, int value, int temp_j)
{
    for (int i{  }; i < this->map_size; ++i)
    {
        for (int j{ temp_j }; j < temp_j + this->field_size; ++j)
        {
            if (arr[i][j] == value)
            {
                for (int field_i{}; field_i < this->field_size; ++field_i)
                {
                    if (temp_field->getNum(field_i, j % this->field_size) == 0)
                    {
                        temp_field->setNum(10, field_i, j % this->field_size);
                    }
                }
            }
        }
    }
}

bool Solution::checkException(int** arr, Field* temp_field, int value, int temp_i, int temp_j)
{
    this->resetTempField(temp_field);

    this->checkException_Strings(arr, temp_field, value, temp_i * 3);

    this->checkException_Columns(arr, temp_field, value, temp_j * 3);

    int count{};

    count = this->checkCountInField(temp_field);

    if (count == 8)
    {
        for (int i{}; i < this->field_size; ++i)
        {
            for (int j{}; j < this->field_size; ++j)
            {
                if (temp_field->getNum(i, j) == 0)
                {
                    arr[temp_i * this->field_size + i][temp_j * this->field_size + j] = value;

                    return true;
                }
            }
        }
    }

    return false;
}

bool Solution::checkLastNumberInStr_Col_Field(Map* map, Field* temp, int* string, int* column, int temp_i, int temp_j)
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

void Solution::overrideNumbersWithField(Field* temp)
{
    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            this->numbers[temp->getNum(i, j) - 1]++;
        }
    }
}

void Solution::overrideNumbersWithRow(int* arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        this->numbers[arr[i] - 1]++;
    }
}

int Solution::checkCountInNumbers()
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

int Solution::checkCount(int* arr)
{
    int count{};

    for (int i{}; i < this->map_size; ++i)
    {
        if (arr[i] != 0)
        {
            ++count;
        }
    }

    return count;
}

int Solution::checkCountInField(Field* temp)
{
    int count{};

    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            if (temp->getNum(i, j) != 0)
            {
                ++count;
            }
        }
    }

    return count;
}

void Solution::clearNumbers()
{
    for (int i{}; i < this->map_size; ++i)
    {
        this->numbers[i] = 0;
    }
}

bool Solution::isRowFull(int* arr)
{
    this->clearNumbers();

    for (int i{}; i < this->map_size; ++i)
    {
        this->numbers[arr[i] - 1]++;
    }

    for (int i{}; i < this->map_size; ++i)
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

bool Solution::lastInRow(int* arr)
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

bool Solution::exceptionInField(int** arr, Field* temp, int temp_i, int temp_j)
{
    this->clearNumbers();

    Field* temp_field = new Field{*temp};

    int count{}, value{};

    this->overrideNumbersWithField(temp);

    for (int i{}; i < this->map_size; ++i)
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

bool Solution::lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j)
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