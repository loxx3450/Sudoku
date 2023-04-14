#include "Solution.h"

bool Solution::lastInField(Field* temp)
{
    if (this->methods1.lastInField(temp))
    {
        return true;
    }

    return false;
}

bool Solution::lastInRow(Cell* arr)
{
    if (this->methods1.lastInRow(arr))
    {
        return true;
    }

    return false;

}

bool Solution::exceptionInField(Cell** arr, Field* temp, int temp_i, int temp_j)
{
    if (this->methods2.exceptionInField(arr, temp, temp_i, temp_j))
    {
        return true;
    }

    return false;
}

bool Solution::exceptionInString(Cell** arr, Cell* string, int str_index)
{
    if (this->methods2.exceptionInString(arr, string, str_index))
    {
        return true;
    }

    return false;
}

bool Solution::exceptionInColumn(Cell** arr, Cell* column, int col_index)
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

void Solution::makeNotes(Map* map, Field* temp, int temp_i, int temp_j)
{
    this->methods4.makeNotes(map, temp, temp_i, temp_j);
}

bool Solution::nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    return this->methods4.nakedCouplesInField(map, temp, temp_i, temp_j);
}

bool Solution::nakedCouplesInRow(Cell* row)
{
    return this->methods4.nakedCouplesInRow(row);
}

bool Solution::nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    return this->methods4.nakedtripletsInField(map, temp, temp_i, temp_j);
}

bool Solution::nakedTripletsInRow(Cell* row)
{
    return this->methods4.nakedTripletsInRow(row);
}

bool Solution::onlyOneNote(Map* map)
{
    if (this->methods4.isOnlyOneNote(map))
    {
        return true;
    }

    return false;
}

bool Solution::hiddenNote(Map* map)
{
    if (this->methods4.hiddenNote(map))
    {
        return true;
    }

    return false;
}
