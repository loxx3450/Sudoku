#pragma once
#include "Field.h"

class Solution
{
private:
    const int field_count = 3;
    const int map_count = 9;

    int* numbers;

    void func(int** arr, int** temp_field, Field* temp, int value, int temp_i, int temp_j)
    {
        for (int i{ temp_i }; i < temp_i + 3; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                if (arr[i][j] == value)
                {
                    for (int field_j{}; field_j < 3; ++field_j)
                    {
                        temp_field[i % 3][field_j] = 10;
                    }
                }
            }
        }

        for (int i{  }; i < 9; ++i)
        {
            for (int j{ temp_j }; j < temp_j + 3; ++j)
            {
                if (arr[i][j] == value)
                {
                    for (int field_i{}; field_i < 3; ++field_i)
                    {
                        temp_field[field_i][j] = 10;
                    }
                }
            }
        }

        int* arr2 = new int[9]{};

        int count{};

        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                if (temp_field[i][j] != 0)
                {
                    ++count;
                }
            }
        }

        if (count == 8)
        {
            for (int i{}; i < 3; ++i)
            {
                for (int j{}; j < 3; ++j)
                {
                    if (temp_field[i][j] == 0)
                    {
                        arr[temp_i * 3 + i][temp_j * 3 + j] = value;
                    }
                }
            }
        }

    }

    int checkCountInField(Field* temp);

    int checkCountInRow(int* arr);

    void clearNumbers();

    bool isFull(int* arr);

public:
    Solution():
        numbers{new int [this->map_count]{}}
    {}

    bool lastInField(Field* temp);

    bool lastInRow(int* arr);

    void exceptcionInField(int** arr, Field* temp, int temp_i, int temp_j)
    {
        int* arr2 = new int[9]{};

        int** temp_field = new int* [3];

        for (int i{}; i < 3; ++i)
        {
            temp_field[i] = new int[3];
        }

        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                temp_field[i][j] = temp->getNum(i, j);
            }
        }

        int count{}, value{};

        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                arr2[temp->getNum(i, j) - 1]++;
            }
        }


        for (int i{}; i < 9; ++i)
        {
            if (arr2[i] == 0)
            {
                func(arr, temp_field, temp, i + 1, temp_i, temp_j);
            }
        }
    }
};