#include "Map.h"

bool Map::checkFields()
{
    Field* temp = new Field{};
    for (int i{}; i < this->field_size; ++i)
    {
        for (int j{}; j < this->field_size; ++j)
        {
            temp->generate(this->arr, i * this->field_size, j * this->field_size);

            if (!temp->check())
            {
                delete temp;

                return false;
            }
        }
    }

    delete temp;

    return true;
}

bool Map::checkStrings()
{
    this->clearNumbers();

    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            this->map_numbers[this->arr[i][j] - 1]++;
        }

        for (int i{}; i < this->map_size; ++i)
        {
            if (this->map_numbers[i] > 1)
            {
                return false;
            }

            this->map_numbers[i] = 0;
        }
    }

    return true;
}

bool Map::checkColumns()
{
    this->clearNumbers();

    for (int i{}; i < 9; ++i)
    {
        for (int j{}; j < 9; ++j)
        {
            this->map_numbers[this->arr[j][i] - 1]++;
        }

        for (int i{}; i < 9; ++i)
        {
            if (this->map_numbers[i] > 1)
            {
                return false;
            }

            this->map_numbers[i] = 0;
        }
    }

    return true;
}

void Map::clear()
{
    for (int i{}; i < 9; ++i)
    {
        for (int j{}; j < 9; ++j)
        {
            arr[i][j] = 0;
        }

        this->map_numbers[i] = 0;
    }
}

void Map::clearNumbers()
{
    for (int i{}; i < 9; ++i)
    {
        this->map_numbers[i] = 0;
    }
}

bool Map::isMade()
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

void Map::tryToGenerate()
{
    this->clear();

    int value{};

    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            while (true)
            {
                this->arr[i][j] = rand() % this->map_size + 1;

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
    }
}

void Map::generate()
{
    this->clear();

    while (true)
    {
        this->tryToGenerate();
        if (this->isMade() && this->check())
        {
            break;
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
            std::cout << arr[i][j] << " ";

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

bool Map::check()
{
    if (checkFields())
    {
        //std::cout << "Etap 1" << "\n";

        if (checkStrings())
        {
            //std::cout << "Etap 2" << "\n";

            if (checkColumns())
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
            this->arr[i][j] = field->getNum(field_i, field_j);
        }
    }
}

int Map::getNum(int i, int j)
{
    return this->arr[i][j];
}

void Map::setNum(int value, int i, int j)
{
    this->arr[i][j] = value;
}

int** Map::getArr()
{
    return this->arr;
}

void Map::setArr(int** arr)
{
    for (int i{}; i < this->map_size; ++i)
    {
        for (int j{}; j < this->map_size; ++j)
        {
            this->arr[i][j] = arr[i][j];
        }
    }
}

int* Map::getString(int i)
{
    return this->arr[i];
}

int* Map::getColumn(int index)
{
    int* tmp = new int[this->map_size]{};

    for (int i{}; i < this->map_size; ++i)
    {
        tmp[i] = this->arr[i][index];
    }

    return tmp;
}

void Map::setColumn(int* tmp, int index)
{
    for (int i{}; i < this->map_size; ++i)
    {
        this->arr[i][index] = tmp[i];
    }
}