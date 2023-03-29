#include "Map.h"

bool Map::checkFields()
{
    Field* temp = new Field{};
    for (int i{}; i < this->field_count; ++i)
    {
        for (int j{}; j < this->field_count; ++j)
        {
            temp->generate(this->arr, i * this->field_count, j * this->field_count);

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

    for (int i{}; i < this->map_count; ++i)
    {
        for (int j{}; j < this->map_count; ++j)
        {
            this->numbers[this->arr[i][j] - 1]++;
        }

        for (int i{}; i < this->map_count; ++i)
        {
            if (this->numbers[i] > 1)
            {
                return false;
            }

            this->numbers[i] = 0;
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
            this->numbers[this->arr[j][i] - 1]++;
        }

        for (int i{}; i < 9; ++i)
        {
            if (this->numbers[i] > 1)
            {
                return false;
            }

            this->numbers[i] = 0;
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

        numbers[i] = 0;
    }
}

void Map::clearNumbers()
{
    for (int i{}; i < 9; ++i)
    {
        numbers[i] = 0;
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

void Map::generate()
{
    this->clear();

    int value{};

    for (int i{}; i < this->map_count; ++i)
    {
        for (int j{}; j < this->map_count; ++j)
        {
            while (true)
            {
                this->arr[i][j] = rand() % this->map_count + 1;

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

void Map::show()
{
    for (int i{}; i < 9; ++i)
    {
        for (int j{}; j < 9; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}

bool Map::check()
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

int* Map::getString(int i)
{
    return this->arr[i];
}

int* Map::getColumn(int index)
{
    int* tmp = new int[this->map_count]{};

    for (int i{}; i < this->map_count; ++i)
    {
        tmp[i] = this->arr[i][index];
    }

    return tmp;
}

void Map::setColumn(int* tmp, int index)
{
    for (int i{}; i < this->map_count; ++i)
    {
        this->arr[i][index] = tmp[i];
    }
}