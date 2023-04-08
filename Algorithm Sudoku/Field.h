#pragma once
#include "iostream"
#include "Cell.h"

class Field
{
private:
    const int count = 3;
    const int numbers_size = 9;

    Cell** arr;
    int* field_numbers;

    void overrideNumbersInField();

public:
    Field() :
        arr{ new Cell * [this->count] },
        field_numbers{ new int[this->numbers_size]{} }
    {
        for (int i{}; i < this->count; ++i)
        {
            arr[i] = new Cell[this->count]{};
        }
    }

    void generate(Cell** tmp_arr, int i, int j);

    void show();

    void showNotes();

    bool isFull();

    bool check();

    int getNum(int i, int j);

    Cell* getCell(int i, int j);

    int getCount(int i, int j)
    {
        if (arr[i][j].getNotes() != nullptr)
        {
            int count{};

            for (int i{}; i < 9; ++i)
            {
                if (arr[i][j].getNotes()[i] == true)
                {
                    ++count;
                }
            }

            return count;
        }

        return 0;
        
    }

    void setNum(int value, int i, int j);

    ~Field()
    {
        if (this->arr != nullptr)
        {
            for (int i{}; i < this->count; ++i)
            {
                if(this->arr[i] != nullptr)
                {
                    delete[] this->arr[i];
                }
            }

            delete[] this->arr;
        }

        if (this->field_numbers != nullptr)
        {
            delete[] field_numbers;
        }
    }
};

