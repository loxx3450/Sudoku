#include "Solution.h"

bool Solution::lastInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    if (this->methods1.lastInField(map, temp, temp_i, temp_j))
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
    return this->methods4.nakedTripletsInField(map, temp, temp_i, temp_j);
}

bool Solution::nakedTripletsInRow(Cell* row)
{
    return this->methods4.nakedTripletsInRow(row);
}

bool Solution::nakedFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    return this->methods4.nakedFoursomeInField(map, temp, temp_i, temp_j);
}

bool Solution::nakedFoursomeInRow(Cell* row)
{
    return this->methods4.nakedFoursomeInRow(row);
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

bool Solution::hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    if (this->methods5.hiddenCouplesInField(map, temp, temp_i, temp_j))
    {
        return true;
    }

    return false;
}

bool Solution::hiddenCouplesInRow(Cell* row)
{
    if (this->methods5.hiddenCouplesInRow(row))
    {
        return true;
    }

    return false;
}

bool Solution::hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    if (this->methods5.hiddenTripletsInField(map, temp, temp_i, temp_j))
    {
        return true;
    }

    return false;
}

bool Solution::hiddenTripletsInRow(Cell* row)
{
    if (this->methods5.hiddenTripletsInRow(row))
    {
        return true;
    }

    return false;
}

bool Solution::hiddenFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j)
{
    if (this->methods5.hiddenFoursomeInField(map, temp, temp_i, temp_j))
    {
        return true;
    }

    return false;
}

bool Solution::hiddenFoursomeInRow(Cell* row)
{
    if (this->methods5.hiddenFoursomeInRow(row))
    {
        return true;
    }

    return false;
}

bool Solution::pointingGroupInField(Map* map, Field* temp, int temp_i, int temp_j, int size)
{
    if (this->methods5.pointingGroupInField(map, temp, temp_i, temp_j, size))
    {
        return true;
    }

    return false;
}

bool Solution::pointingGroupInString(Map* map, Cell* string, int temp_i, int string_i, int size)
{
    if (this->methods5.pointingGroupInString(map, string, temp_i, string_i, size))
    {
        return true;
    }

    return false;
}

bool Solution::pointingGroupInColumn(Map* map, Cell* string, int temp_j, int column_j, int size)
{
    if (this->methods5.pointingGroupInColumn(map, string, temp_j, column_j, size))
    {
        return true;
    }

    return false;
}
