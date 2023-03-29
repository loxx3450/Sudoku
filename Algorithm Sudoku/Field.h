#pragma once
#include "iostream"

class Field
{
private:
    const int count = 3;
    const int numbers_count = 9;

    int** arr;
    int* numbers;

    void numbersInField();

public:
    Field() :
        arr{ new int* [this->count] },
        numbers{ new int[this->numbers_count]{} }
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

        if (this->numbers != nullptr)
        {
            delete[] numbers;
        }
    }
};

