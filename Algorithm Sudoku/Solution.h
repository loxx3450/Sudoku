#pragma once
#include "Map.h"

class Solution
{
private:
    const int field_size = 3;
    const int map_size = 9;

    int* numbers;

    void resetTempField(Field* temp);

    int findExceptValue();

    int findExceptIndex(int* arr);

    bool findValueInField(Field* temp, int value);

    void checkException_Strings(int** arr, Field* temp_field, int value, int temp_i);

    void checkException_Columns(int** arr, Field* temp_field, int value, int temp_j);

    bool checkException(int** arr, Field* temp_field, int value, int temp_i, int temp_j);

    bool checkLastNumberInStr_Col_Field(Map* map, Field* temp, int* string, int* column, int temp_i, int temp_j);

    bool checkExceptionInRow(int** arr, int value, int* string, int str_index)
    {
        Field* temp = new Field{};

        int* ghost_string = new int[this->map_size];

        for (int i{}; i < this->map_size; ++i)
        {
            ghost_string[i] = string[i];
        }

        int count;

        for (int i{}; i < this->field_size; ++i)
        {
            temp->generate(arr, (int)(str_index / 3) * 3, i * 3);

            if (this->findValueInField(temp, value))
            {
                for (int j{}; j < this->field_size; ++j)
                {
                    ghost_string[i * 3 + j] = 10;
                }
            }
        }

        count = this->checkCount(ghost_string);

        if (count == 8)
        {
            int index = this->findExceptIndex(ghost_string);

            string[index] = value;

            delete[] ghost_string;

            delete temp;

            return true;
        }

        for (int i{}; i < this->map_size; ++i)
        {
            if (ghost_string[i] == 0)
            {
                for (int j{}; j < this->map_size; ++j)
                {
                    if (arr[j][i] == value)
                    {
                        ghost_string[i] = 10;
                    }
                }
            }
        }

        count = this->checkCount(ghost_string);

        if (count == 8)
        {
            int index = this->findExceptIndex(ghost_string);

            string[index] = value;

            delete[] ghost_string;

            delete temp;

            return true;
        }

        delete[] ghost_string;

        delete temp;

        return false;
    }

    void overrideNumbersWithField(Field* temp);

    int checkCountInNumbers();

    int checkCount(int* arr);

    int checkCountInField(Field* temp);

    void overrideNumbersWithRow(int* arr);

    void clearNumbers();

    bool isRowFull(int* arr);

public:
    Solution():
        numbers{new int [this->map_size]{}}
    {}

    bool lastInField(Field* temp);

    bool lastInRow(int* arr);

    bool exceptionInField(int** arr, Field* temp, int temp_i, int temp_j);

    bool exceptionInRow(int** arr, int* string, int str_index)
    {
        this->clearNumbers();

        this->overrideNumbersWithRow(string);

        for (int i{}; i < this->map_size; ++i)
        {
            if (numbers[i] == 0)
            {
                if (checkExceptionInRow(arr, i + 1, string, str_index))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j);

    ~Solution()
    {
        if (this->numbers != nullptr)
        {
            //delete[] this->numbers;   //!!!!!!!!!!!!!
        }
    }
};