#pragma once
#include "Field.h"

class Map
{
private:
    const int field_count = 3;
    const int map_count = 9;

    int** arr;
    int* numbers;

    bool checkFields();

    bool checkStrings();

    bool checkColumns();

    void clear();

    void clearNumbers();

public:
    Map() :
        arr{ new int* [this->map_count] },
        numbers{ new int[this->map_count]{} }
    {
        for (int i{}; i < this->map_count; ++i)
        {
            arr[i] = new int[this->map_count]{};
        }
    }

    Map(int** arr) :
        arr{ new int* [this->map_count] },
        numbers{ new int[this->map_count]{} }
    {
        for (int i{}; i < this->map_count; ++i)
        {
            this->arr[i] = new int[this->map_count]{};
            for (int j{}; j < this->map_count; ++j)
            {
                this->arr[i][j] = arr[i][j];
            }
        }
    }

    bool isMade();

    void generate();

    void show();

    bool check();

    void takeField(Field* field, int tmp_i, int tmp_j);

    int getNum(int i, int j);

    void setNum(int value, int i, int j);

    int** getArr();

    int* getString(int i);

    int* getColumn(int index);

    void setColumn(int* tmp, int index);

    ~Map()
    {
        if (this->arr != nullptr)
        {
            for (int i{}; i < this->map_count; ++i)
            {
                if (this->arr[i] != nullptr)
                {
                    delete[] this->arr[i];
                }
            }

            delete[] this->arr;
        }

        if (this->numbers != nullptr)
        {
            delete[] this->numbers;
        }
    }
};