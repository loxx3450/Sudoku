#pragma once
#include "Change.h"
#include "Field.h"

class Map
{
private:
    int** arr;
    Change* change;


    bool checkFields()
    {
        Field temp{};
        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                temp.generate(this->arr, i * 3, j * 3);
                if (!temp.check())
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool checkStrings()
    {
        int* arr2 = new int[9]{};
        for (int i{}; i < 9; ++i)   //одна третья строки
        {
            for (int j{}; j < 9; ++j)   //3 числа строки
            {
                arr2[this->arr[i][j] - 1]++;
            }

            for (int i{}; i < 9; ++i)
            {
                if (arr2[i] > 1)
                {
                    return false;
                }

                arr2[i] = 0;
            }
        }




        return true;
    }

    bool checkColumns()
    {
        int* arr2 = new int[9]{};
        for (int i{}; i < 9; ++i)   //одна третья строки
        {
            for (int j{}; j < 9; ++j)   //3 числа строки
            {
                arr2[this->arr[j][i] - 1]++;
            }

            for (int i{}; i < 9; ++i)
            {
                if (arr2[i] > 1)
                {
                    return false;
                }

                arr2[i] = 0;
            }
        }

        return true;
    }

public:
    Map() :
        arr{ new int* [9] },
        change{new Change{}}
    {
        for (int i{}; i < 9; ++i)
        {
            arr[i] = new int[9]{};
        }
    }

    void generate()
    {
        int id = 1;
        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                arr[i][j] = (i * 3 + i / 3 + j) % 9 + 1;
            }
        }
    }

    void show()
    {
        for (int i{}; i < 9; ++i)   //одна третья строки
        {
            for (int j{}; j < 9; ++j)   //3 числа строки
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n\n";
    }

    bool check()
    {
        if (checkFields())
        {
            std::cout << "Etap 1" << "\n";
            if (checkStrings())
            {
                std::cout << "Etap 2" << "\n";
                if (checkColumns())
                {
                    std::cout << "Etap 3" << "\n";
                    return true;
                }
            }
        }
        std::cout << "Etap 0" << "\n";
        return false;
    }

    void changeStrToCol()
    {
        this->arr = change->strToCol(this->arr);
    }

    void arrMirror()
    {
        this->arr = change->Mirror(this->arr);
    }

    void changeFieldStr(int index, int multiply)
    {
        this->arr = change->fieldsByStr(this->arr, index, multiply);
    }

    void changeFieldCol(int index, int multiply)
    {
        this->arr = change->fieldsByCol(this->arr, index, multiply);
    }

    void swapStrings(int index1, int index2)
    {
        if ((index1 - index2) <= 2 && (index2 - index1) <= 2)
        {
            this->arr = change->swapStrs(this->arr, index1, index2);
        }
    }

    void swapColumns(int index1, int index2)
    {
        if ((index1 - index2) <= 2 && (index2 - index1) <= 2)
        {
            this->arr = change->swapColumns(this->arr, index1, index2);
        }
    }

    void upsideDown()
    {
        this->arr = change->upsideDown(this->arr);
    }

    int getNum(int i, int j)
    {
        return this->arr[i][j];
    }

    void setNum(int value, int i, int j)
    {
        this->arr[i][j] = value;
    }
};