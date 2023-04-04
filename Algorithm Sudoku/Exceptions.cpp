#include "Exceptions.h"

void Exceptions::resetTempField(Field* temp)
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

int* Exceptions::createGhostArray(int* arr)
{
    int* newarr = new int[this->map_size];

    for (int i{}; i < this->map_size; ++i)
    {
        newarr[i] = arr[i];
    }

    return newarr;
}


int Exceptions::findExceptIndex(int* arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (arr[i] == 0)
        {
            return i;
        }
    }
}

int Exceptions::checkCountInArr(int* arr)
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

int Exceptions::checkCountInField(Field* temp)
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

bool Exceptions::IsValueInField(Field* temp, int value)
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

void Exceptions::checkException_Strings(int** arr, Field* temp_field, int value, int temp_i)
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

void Exceptions::checkException_Columns(int** arr, Field* temp_field, int value, int temp_j)
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

bool Exceptions::checkException(int** arr, Field* temp_field, int value, int temp_i, int temp_j)
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

void Exceptions::checkExceptionInString_Field(int** arr, Field* temp, int* ghost_string, int value, int str_index)
{
    for (int i{}; i < this->field_size; ++i)
    {
        temp->generate(arr, (int)(str_index / 3) * 3, i * 3);

        if (this->IsValueInField(temp, value))
        {
            for (int j{}; j < this->field_size; ++j)
            {
                ghost_string[i * 3 + j] = 10;
            }
        }
    }
}

void Exceptions::checkExceptionInString_Columns(int** arr, int* ghost_string, int value)
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (ghost_string[i] == 0)
        {
            for (int j{}; j < this->map_size; ++j)
            {
                if (arr[j][i] == value)
                {
                    ghost_string[i] = 10;
                }
            }
        }
    }
}

bool Exceptions::checkExceptionInString(int** arr, int value, int* string, int str_index)
{
    Field* temp = new Field{};

    int* ghost_string = this->createGhostArray(string);

    int count;

    this->checkExceptionInString_Field(arr, temp, ghost_string, value, str_index);

    count = this->checkCountInArr(ghost_string);

    if (count == 8)
    {
        int index = this->findExceptIndex(ghost_string);

        string[index] = value;

        delete[] ghost_string;

        delete temp;

        return true;
    }

    this->checkExceptionInString_Columns(arr, ghost_string, value);

    count = this->checkCountInArr(ghost_string);

    if (count == 8)
    {
        int index = this->findExceptIndex(ghost_string);

        string[index] = value;

        delete[] ghost_string;

        delete temp;

        return true;
    }

    delete[] ghost_string;

    delete temp;

    return false;
}

void Exceptions::checkExceptionInColumn_Field(int** arr, Field* temp, int* ghost_column, int value, int col_index)
{
    for (int i{}; i < this->field_size; ++i)
    {
        temp->generate(arr, i * 3, (int)(col_index / 3) * 3);

        if (this->IsValueInField(temp, value))
        {
            for (int j{}; j < this->field_size; ++j)
            {
                ghost_column[i * 3 + j] = 10;
            }
        }
    }
}

void Exceptions::checkExceptionInColumn_Strings(int** arr, int* ghost_column, int value)
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (ghost_column[i] == 0)
        {
            for (int j{}; j < this->map_size; ++j)
            {
                if (arr[i][j] == value)
                {
                    ghost_column[i] = 10;
                }
            }
        }
    }
}

bool Exceptions::checkExceptionInColumn(int** arr, int value, int* column, int col_index)
{
    Field* temp = new Field{};

    int* ghost_column = this->createGhostArray(column);

    int count;

    this->checkExceptionInColumn_Field(arr, temp, ghost_column, value, col_index);

    count = this->checkCountInArr(ghost_column);

    if (count == 8)
    {
        int index = this->findExceptIndex(ghost_column);

        column[index] = value;

        delete[] ghost_column;

        delete temp;

        return true;
    }

    this->checkExceptionInColumn_Strings(arr, ghost_column, value);

    count = this->checkCountInArr(ghost_column);

    if (count == 8)
    {
        int index = this->findExceptIndex(ghost_column);

        column[index] = value;

        delete[] ghost_column;

        delete temp;

        return true;
    }

    delete[] ghost_column;

    delete temp;

    return false;
}