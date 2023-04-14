#pragma once
#include "iostream"
#include "Cell.h"

class Field
{
private:
    const int size = 3;
    const int numbers_size = 9;

    Cell** arr;
    int* field_numbers;

    void overrideNumbersInField();

public:
    Field() :
        arr{ new Cell * [this->size] },
        field_numbers{ new int[this->numbers_size]{} }
    {
        for (int i{}; i < this->size; ++i)
        {
            arr[i] = new Cell[this->size]{};
        }
    }

    void generate(Cell** tmp_arr, int i, int j);

    void show();

    void showNotes();

    bool isFull();

    bool check();

    int getNum(int i, int j);

    Cell* getCell(int i, int j);

    int countOfCellNotes(int i, int j);

    bool editCellNotes(bool* notes, int i, int j);

    void removeCellNote(int value, int i, int j);

    void setNum(int value, int i, int j);

    int countOfEmptyCells();

    ~Field()
    {
        if (this->arr != nullptr)
        {
            for (int i{}; i < this->size; ++i)
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
            delete[] this->field_numbers;
        }
    }
};

