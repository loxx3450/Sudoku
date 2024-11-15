#include "Exception.h"

void Exception::resetTempField(Field* temp)
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

Cell* Exception::createGhostArray(Cell* arr)
{
    Cell* newarr = new Cell[this->map_size];

    for (int i{}; i < this->map_size; ++i)
    {
        newarr[i] = arr[i];
    }

    return newarr;
}

int Exception::findExceptIndex(Cell* arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (arr[i].getNum() == 0)
        {
            return i;
        }
    }
}

int Exception::checkCountInArr(Cell* arr)
{
    int count{};

    for (int i{}; i < this->map_size; ++i)
    {
        if (arr[i].getNum() != 0)
        {
            ++count;
        }
    }

    return count;
}

int Exception::checkCountInField(Field* temp)
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

bool Exception::IsValueInField(Field* temp, int value)
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

void Exception::checkException_Strings(Cell** arr, Field* temp_field, int value, int temp_i)
{
    for (int i{ temp_i }; i < temp_i + this->field_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            if (arr[i][j].getNum() == value)
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

void Exception::checkException_Columns(Cell** arr, Field* temp_field, int value, int temp_j)
{
    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{ temp_j }; j < temp_j + this->field_size; ++j)
        {
            if (arr[i][j].getNum() == value)
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

bool Exception::checkException(Cell** arr, Field* temp_field, int value, int temp_i, int temp_j)
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
                    arr[temp_i * this->field_size + i][temp_j * this->field_size + j].setNum(value);

                    return true;
                }
            }
        }
    }

    return false;
}

void Exception::checkExceptionInString_Field(Cell** arr, Field* temp, Cell* ghost_string, int value, int str_index)
{
    for (int i{}; i < this->field_size; ++i)
    {
        temp->generate(arr, (int)(str_index / 3) * 3, i * 3);

        if (this->IsValueInField(temp, value))
        {
            for (int j{}; j < this->field_size; ++j)
            {
                ghost_string[i * 3 + j].setNum(10);
            }
        }
    }
}

void Exception::checkExceptionInString_Columns(Cell** arr, Cell* ghost_string, int value)
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (ghost_string[i].getNum() ==  0)
        {
            for (int j{}; j < this->map_size; ++j)
            {
                if (arr[j][i].getNum() == value)
                {
                    ghost_string[i].setNum(10);
                }
            }
        }
    }
}

bool Exception::checkExceptionInString(Cell** arr, int value, Cell* string, int str_index)
{
    Field* temp = new Field{};

    Cell* ghost_string = this->createGhostArray(string);

    int count;

    this->checkExceptionInString_Field(arr, temp, ghost_string, value, str_index);

    this->checkExceptionInString_Columns(arr, ghost_string, value);

    count = this->checkCountInArr(ghost_string);

    if (count == 8)
    {
        int index = this->findExceptIndex(ghost_string);

        string[index].setNum(value);

        delete[] ghost_string;

        delete temp;

        return true;
    }

    delete[] ghost_string;

    delete temp;

    return false;
}

void Exception::checkExceptionInColumn_Field(Cell** arr, Field* temp, Cell* ghost_column, int value, int col_index)
{
    for (int i{}; i < this->field_size; ++i)
    {
        temp->generate(arr, i * 3, (int)(col_index / 3) * 3);

        if (this->IsValueInField(temp, value))
        {
            for (int j{}; j < this->field_size; ++j)
            {
                ghost_column[i * 3 + j].setNum(10);
            }
        }
    }
}

void Exception::checkExceptionInColumn_Strings(Cell** arr, Cell* ghost_column, int value)
{
    for (int i{}; i < this->map_size; ++i)
    {
        if (ghost_column[i].getNum() == 0)
        {
            for (int j{}; j < this->map_size; ++j)
            {
                if (arr[i][j].getNum() == value)
                {
                    ghost_column[i].setNum(10);
                }
            }
        }
    }
}

bool Exception::checkExceptionInColumn(Cell** arr, int value, Cell* column, int col_index)
{
    Field* temp = new Field{};

    Cell* ghost_column = this->createGhostArray(column);

    int count;

    this->checkExceptionInColumn_Field(arr, temp, ghost_column, value, col_index);

    this->checkExceptionInColumn_Strings(arr, ghost_column, value);

    count = this->checkCountInArr(ghost_column);

    if (count == 8)
    {
        int index = this->findExceptIndex(ghost_column);

        column[index].setNum(value);

        delete[] ghost_column;

        delete temp;

        return true;
    }

    delete[] ghost_column;

    delete temp;

    return false;
}