#pragma once
#include "iostream"

class Field
{
private:
    const int count = 3;
    const int numbers_size = 9;

    int** arr;
    int* field_numbers;

    void overrideNumbersInField();

public:
    Field() :
        arr{ new int* [this->count] },
        field_numbers{ new int[this->numbers_size]{} }
    {
        for (int i{}; i < this->count; ++i)
        {
            arr[i] = new int[this->count]{};
        }
    }

    void generate(int** tmp_arr, int i, int j);

    void show();

    bool isFull();

    bool check();

    int getNum(int i, int j);

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

