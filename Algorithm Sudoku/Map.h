#pragma once
#include "Field.h"
#include "CheckMap.h"
#include "Cell.h"

class Map
{
private:
    const int field_size = 3;
    const int map_size = 9;

    Cell** arr;
    int* map_numbers;
    CheckMap checking;

    void clear();

    void clearNumbers();

    void tryToGenerate();

public:
    Map() :
        arr{ new Cell* [this->map_size] },
        map_numbers{ new int[this->map_size]{} },
        checking{}
    {
        for (int i{}; i < this->map_size; ++i)
        {
            arr[i] = new Cell[this->map_size]{};
        }
    }

    Map(int** arr) :
        arr{ new Cell* [this->map_size] },
        map_numbers{ new int[this->map_size]{} },
        checking{}
    {
        for (int i{}; i < this->map_size; ++i)
        {
            this->arr[i] = new Cell[this->map_size]{};
            for (int j{}; j < this->map_size; ++j)
            {
                this->arr[i][j].setNum(arr[i][j]);
            }
        }
    }

    Map(Cell** arr) :
        arr{ new Cell * [this->map_size] },
        map_numbers{ new int[this->map_size]{} },
        checking{}
    {
        for (int i{}; i < this->map_size; ++i)
        {
            this->arr[i] = new Cell[this->map_size]{};
            for (int j{}; j < this->map_size; ++j)
            {
                this->arr[i][j].setNum(arr[i][j].getNum());
            }
        }
    }

    bool isMade();

    bool isEqualArr(Cell** arr);

    void generate();

    void show();

    void showNotes();

    bool check();



    void takeField(Field* field, int tmp_i, int tmp_j);

    int getNum(int i, int j);

    void setNum(int value, int i, int j);

    Cell** getArr();

    void setArr(Cell** arr);

    Cell* getString(int i);

    Cell* getColumn(int index);

    void setColumn(Cell* tmp, int index);

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
            delete[] this->map_numbers;
        }
    }
};