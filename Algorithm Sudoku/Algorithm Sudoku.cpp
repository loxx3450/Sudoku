#include <iostream>
#include <map>

class Field
{
private:
    int id = 1;

    int** arr;
    int* arr2;

public:
    Field():
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
        this->show();
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
        this->show();
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
        }

        std::cout << "True\n";
        return true;
    }

};

class Map
{
private:
    int** arr;

public:
    Map():
        arr{ new int* [9] }
    {
        for (int i{}; i < 9; ++i)
        {
            arr[i] = new int[9]{};
        }
    }

    void generate()
    {
        int id = 1;
        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                arr[i][j] = id++;
            }

            id = 1;
        }
    }

    void show()
    {
        for (int i{}; i < 9; ++i)   //одна третья строки
        {
            for (int j{}; j < 9; ++j)   //3 числа строки
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        } 
    }

    bool checkFields()
    {
        Field temp{};
        for (int i{}; i < 3; ++i)
        {
            for (int j{}; j < 3; ++j)
            {
                temp.generate(this->arr, i * 3, j * 3);
                if (!temp.check())
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool checkStrings()
    {
        int* arr2 = new int[9]{};
        for (int i{}; i < 9; ++i)   //одна третья строки
        {
            for (int j{}; j < 9; ++j)   //3 числа строки
            {
                arr2[this->arr[i][j] - 1]++;
            }

            for (int i{}; i < 9; ++i)
            {
                if (arr2[i] > 1)
                {
                    return false;
                }

                arr2[i] = 0;
            }
        }

        


        return true;
    }

    bool checkColumns()
    {
        int* arr2 = new int[9]{};
        for (int i{}; i < 9; ++i)   //одна третья строки
        {
            for (int j{}; j < 9; ++j)   //3 числа строки
            {
                arr2[this->arr[j][i] - 1]++;
            }

            for (int i{}; i < 9; ++i)
            {
                if (arr2[i] > 1)
                {
                    return false;
                }

                arr2[i] = 0;
            }
        }

        return true;
    }

    bool check()
    {
        if (checkFields())
        {
            if (checkStrings())
            {
                if (checkColumns())
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    srand(time(NULL));
    rand();

    Map map{};
    while (true)
    {
        map.generate();
        map.show();
        if (map.check())
        {
            map.show();
            break;
        }
    }

    
}