#pragma once
#include "iostream"
class Field
{
private:
    int id = 1;

    int** arr;
    int* arr2;

public:
    Field() :
        arr{ new int* [3] },
        arr2{ new int[9]{} }
    {
        for (int i{}; i < 3; ++i)
        {
            arr[i] = new int[3];
        }

        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                arr[i][j] = this->id++;
            }
        }
    }

    void generate(int** tmp_arr, int i, int j)
    {
        for (int string{ i }, index1{}; string < i + 3; ++string, ++index1)
        {
            for (int column{ j }, index2{}; column < j + 3; ++column, ++index2)
            {
                this->arr[index1][index2] = tmp_arr[string][column];
            }
        }
        std::cout << i << " " << j << "\n";
    }


    void show()
    {
        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    }


    bool check()
    {
        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                arr2[arr[i][j] - 1]++;
            }
        }


        for (int i{}; i < 9; ++i)
        {
            if (arr2[i] > 1)
            {
                return false;
            }

            arr2[i] = 0;
        }

        std::cout << "True\n";
        return true;
    }

};

