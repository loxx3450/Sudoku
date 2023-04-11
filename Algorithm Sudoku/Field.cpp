#include "Field.h"

void Field::overrideNumbersInField()
{
    for (int i{}; i < this->size; ++i)
    {
        for (int j{}; j < this->size; ++j)
        {
            if (arr[i][j].getNum() != 0)
            {
                this->field_numbers[arr[i][j].getNum() - 1]++;
            }
        }
    }
}

void Field::generate(Cell** tmp_arr, int i, int j)
{
    for (int string{ i }, index1{}; string < i + this->size; ++string, ++index1)
    {
        for (int column{ j }, index2{}; column < j + this->size; ++column, ++index2)
        {
            this->arr[index1][index2].setCell(tmp_arr[string][column].getCell());
        }
    }
}

void Field::show()
{
    for (int i{}; i < this->size; ++i)
    {
        for (int j{}; j < this->size; ++j)
        {
            std::cout << arr[i][j].getNum() << " ";
        }
        std::cout << "\n";
    }
}

void Field::showNotes()
{
    for (int i{}; i < this->size; ++i)
    {
        for (int j{}; j < this->size; ++j)
        {
            arr[i][j].showNotes();
        }
    }
}

bool Field::isFull()
{
    for (int i{}; i < this->size; ++i)
    {
        for (int j{}; j < this->size; ++j)
        {
            if (this->arr[i][j].getNum() >= 1 && this->arr[i][j].getNum() <= 9)
            {
                continue;
            }

            return false;
        }
    }

    return true;
}

bool Field::check()
{
    this->overrideNumbersInField();

    for (int i{}; i < this->numbers_size; ++i)
    {
        if (this->field_numbers[i] > 1)
        {
            return false;
        }

        this->field_numbers[i] = 0;
    }
    return true;
}

int Field::getNum(int i, int j)
{
    return this->arr[i][j].getNum();
}

Cell Field::getCell(int i, int j)
{
    return this->arr[i][j].getCell();
}

void Field::editCellNotes(bool* notes, int i, int j)
{
    this->arr[i][j].editNotes(notes);
}

void Field::setNum(int value, int i, int j)
{
    this->arr[i][j].setNum(value);
}

int Field::countOfEmptyCells()
{
    int count{};

    for (int i{}; i < this->size; ++i)
    {
        for (int j{}; j < this->size; ++j)
        {
            if (this->arr[i][j].getNum() == 0)
            {
                ++count;
            }
        }
    }

    return count;
}