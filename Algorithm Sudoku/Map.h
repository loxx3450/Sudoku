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

    void clear()
    {
        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                arr[i][j] = 0;
            }


        }
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

    Map(int** arr) :
        arr{ new int* [9] },
        change{ new Change{} }
    {
        for (int i{}; i < 9; ++i)
        {
            this->arr[i] = new int[9]{};
            for (int j{}; j < 9; ++j)
            {
                this->arr[i][j] = arr[i][j];
            }
        }
    }

    bool isMade()
    {
        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                if (this->arr[i][j] == 0)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void generate()
    {
        /*int id = 1;
        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                arr[i][j] = (i * 3 + i / 3 + j) % 9 + 1;
            }
        }*/

        this->clear();

        int value{};

        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                while (true)
                {
                    arr[i][j] = rand() % 9 + 1;//изменить

                    if (value >= 30)
                    {
                        return;
                    }

                    if (checkFields() && checkColumns() && checkStrings())
                    {
                        break;
                    }

                    ++value;
                }

                value = 0;
            }

            value = 0;
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
                    if (isMade())
                    {
                        return true;
                    }
                }
            }
        }
        std::cout << "Etap 0" << "\n";
        return false;
    }

    void takeField(Field* field, int tmp_i, int tmp_j)
    {
        for (int i{ tmp_i }, field_i{}; i < tmp_i + 3; ++i, ++field_i)
        {
            for (int j{ tmp_j }, field_j{}; j < tmp_j + 3; ++j, ++field_j)
            {
                this->arr[i][j] = field->getNum(field_i, field_j);
            }
        }
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

    int** getArr()
    {
        return this->arr;
    }

    int* getString(int i)
    {
        return this->arr[i];
    }

    int* getColumn(int index)
    {
        int* tmp = new int[9]{};

        for (int i{}; i < 9; ++i)
        {
            tmp[i] = this->arr[i][index];
        }

        return tmp;
    }

    void setColumn(int* tmp, int index)
    {
        for (int i{}; i < 9; ++i)
        {
            this->arr[i][index] = tmp[i];
        }
    }
};