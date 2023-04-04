#include "Solution.h"

bool Solution::lastInField(Field* temp)
{
    if (this->methods1.lastInField(temp))
    {
        return true;
    }

    return false;
}

bool Solution::lastInRow(int* arr)
{
    if (this->methods1.lastInRow(arr))
    {
        return true;
    }

    return false;

}

bool Solution::exceptionInField(int** arr, Field* temp, int temp_i, int temp_j)
{
    if (this->methods2.exceptionInField(arr, temp, temp_i, temp_j))
    {
        return true;
    }

    return false;
}

bool Solution::exceptionInString(int** arr, int* string, int str_index)
{
    if (this->methods2.exceptionInString(arr, string, str_index))
    {
        return true;
    }

    return false;
}

bool Solution::exceptionInColumn(int** arr, int* column, int col_index)
{
    if (this->methods2.exceptionInColumn(arr, column, col_index))
    {
        return true;
    }

    return false;
}

bool Solution::lastNumberInStr_Col_Field(Map* map, Field* temp, int temp_i, int temp_j)
{
    if (this->methods3.lastNumberInStr_Col_Field(map, temp, temp_i, temp_j))
    {
        return true;
    }

    return false;
}