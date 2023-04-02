#pragma once
#include "Field.h"

class Map
{
private:
    const int field_size = 3;
    const int map_size = 9;

    int** arr;
    int* map_numbers;

    bool checkFields();

    bool checkStrings();

    bool checkColumns();

    void clear();

    void clearNumbers();

public:
    Map() :
        arr{ new int* [this->map_size] },
        map_numbers{ new int[this->map_size]{} }
    {
        for (int i{}; i < this->map_size; ++i)
        {
            arr[i] = new int[this->map_size]{};
        }
    }

    Map(int** arr) :
        arr{ new int* [this->map_size] },
        map_numbers{ new int[this->map_size]{} }
    {
        for (int i{}; i < this->map_size; ++i)
        {
            this->arr[i] = new int[this->map_size]{};
            for (int j{}; j < this->map_size; ++j)
            {
                this->arr[i][j] = arr[i][j];
            }
        }
    }

    bool isMade();

    void tryToGenerate();

    void generate();

    void show();

    bool check();

    void takeField(Field* field, int tmp_i, int tmp_j);

    int getNum(int i, int j);

    void setNum(int value, int i, int j);

    int** getArr();

    void setArr(int** arr);

    int* getString(int i);

    int* getColumn(int index);

    void setColumn(int* tmp, int index);

    ~Map()
    {
        if (this->arr != nullptr)
        {
            for (int i{}; i < this->map_size; ++i)
            {
                if (this->arr[i] != nullptr)
                {
                    delete[] this->arr[i];
                }
            }

            delete[] this->arr;
        }

        if (this->map_numbers != nullptr)
        {
            //delete[] this->map_numbers;       //!!!!!!!!!!!!!
        }
    }
};