#include "Map.h"

void Map::clear()
{
    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            arr[i][j].setNum(0);

            arr[i][j].clearNotes();
        }

        this->map_numbers[i] = 0;
    }
}

void Map::clearNumbers()
{
    for (int i{}; i < this->map_size; ++i)
    {
        this->map_numbers[i] = 0;
    }
}

bool Map::isMade()
{
    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            if (this->arr[i][j].getNum() == 0)
            {
                return false;
            }
        }
    }

    return true;
}

bool Map::isEqualArr(Cell** temp_arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            if (this->arr[i][j].getNum() != temp_arr[i][j].getNum())
            {
                return false;
            }
        }
    }

    return true;
}

void Map::generate()
{
    this->clear();

    int value{};

    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            while (true)
            {
                this->arr[i][j].setNum(rand() % this->map_size + 1);

                if (value >= 18)
                {
                    return this->generate();
                }

                if (this->checking.checkColumns(this->getArr(), this->map_numbers) && this->checking.checkStrings(this->getArr(), this->map_numbers) && this->checking.checkFields(this->getArr()))
                {
                    break;
                }

                ++value;
            }

            value = 0;
        }
    }
}

void Map::show()
{
    std::cout << "----------------------\n";

    for (int i{}; i < 9; ++i)
    {
        for (int j{}; j < 9; ++j)
        {
            if (j == 0 || j == 3 || j == 6)
            {
                std::cout << "|";
            }

            std::cout << this->arr[i][j].getNum() << " ";

            if (j == 8)
            {
                std::cout << "|";
            }
        }

        std::cout << "\n";

        if ((i + 1) % 3 == 0)
        {
            std::cout << "----------------------\n";
        }
    }
    std::cout << "\n\n\n";
}

void Map::showNotes()
{
    for (int i{}; i < 9; ++i)
    {
        for (int j{}; j < 9; ++j)
        {
            this->arr[i][j].showNotes(i, j);
        }

        std::cout << "\n";
    }
}

bool Map::check()
{
    if (this->checking.checkFields(this->getArr()))
    {
        //std::cout << "Etap 1" << "\n";

        if (this->checking.checkStrings(this->getArr(), this->map_numbers))
        {
           //std::cout << "Etap 2" << "\n";

            if (this->checking.checkColumns(this->getArr(), this->map_numbers))
            {
                //std::cout << "Etap 3" << "\n";

                if (isMade())
                {
                    return true;
                }
            }
        }
    }

    //std::cout << "Etap 0" << "\n";

    return false;
}

void Map::takeField(Field* field, int tmp_i, int tmp_j)
{
    for (int i{ tmp_i }, field_i{}; i < tmp_i + 3; ++i, ++field_i)
    {
        for (int j{ tmp_j }, field_j{}; j < tmp_j + 3; ++j, ++field_j)
        {
            this->arr[i][j].setCell(field->getCell(field_i, field_j));
        }
    }
}

int Map::getNum(int i, int j)
{
    return this->arr[i][j].getNum();
}

void Map::setNum(int value, int i, int j)
{
    this->arr[i][j].setNum(value);
}

Cell** Map::getArr()
{
    return this->arr;
}

void Map::setArr(Cell** arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            this->arr[i][j].setNum(arr[i][j].getNum());
        }
    }
}

Cell* Map::getString(int i)
{
    return this->arr[i];
}

Cell* Map::getColumn(int index)
{
    Cell* tmp = new Cell[this->map_size]{};

    for (int i{}; i < this->map_size; ++i)
    {
        tmp[i] = this->arr[i][index];
    }

    return tmp;
}

void Map::setColumn(Cell* tmp, int index)
{
    for (int i{}; i < this->map_size; ++i)
    {
        this->arr[i][index].setCell(tmp[i].getCell());
    }
}
