#include <iostream>
#include "Map.h"
#include "Solution.h"
#include "LevelCreation.h"
#include <fstream>


void recroding(LevelCreation* a, Map* temp, Map* map)
{
    std::ofstream out;
    out.open("C:\\Users\\egork\\source\\repos\\Algorithm Sudoku\\Kozachok.txt", std::ios::app);

    switch (a->getComplexity())
    {
    case 0:
        out << "easy\n\n";
        break;

    case 1:
        out << "normal\n\n";
        break;

    case 2:
        out << "hard\n\n";
        break;
    }

    for (int i{}; i < 9; ++i)
    {
        for (int j{}; j < 9; ++j)
        {
            out << temp->getArr()[i][j] << " ";
        }

        out << "\n";
    }

    out << "\n\n\n";

    for (int i{}; i < 9; ++i)
    {
        for (int j{}; j < 9; ++j)
        {
            out << map->getArr()[i][j] << " ";
        }

        out << "\n";
    }

    out << "\n\n\n";
}


int main()
{
    srand(time(NULL));
    rand();

    

    /*Map map{};
    while (true)
    {
        map.generate();
        if (map.isMade())
        {
            map.show();

            break;
        }
    }

    map.check();*/
    
    /*Field* field = new Field{};

    field->generate();
    field->setNum(0, 2, 2);

    Solution sol;
    sol.lastInField(field);
    field->show();*/

    /*int** arr = new int* [9]{
        new int[9]{ 1, 2, 0, 4, 0, 6, 7, 8, 9 },
        new int[9]{ 0, 5, 6, 7, 8, 9, 1, 2, 3 },
        new int[9]{ 7, 8, 9, 1, 2, 3, 4, 0, 6 },
        new int[9]{ 2, 3, 4, 0, 6, 7, 8, 9, 1 },
        new int[9]{ 5, 6, 7, 8, 9, 1, 2, 3, 0},
        new int[9]{ 8, 0, 1, 2, 3, 4, 5, 6, 7 },
        new int[9]{ 3, 4, 0, 6, 7, 8, 9, 1, 2 },
        new int[9]{ 6, 7, 8, 9, 1, 2, 3, 0, 5 },
        new int[9]{ 9, 1, 2, 3, 0, 5, 0, 7, 8 }
    };*/

    /*int** arr = new int* [9]{
        new int[9]{ 9, 8, 4, 0, 3, 1, 0, 7, 2 },
        new int[9]{ 6, 1, 0, 0, 0, 7, 0, 0, 0 },
        new int[9]{ 2, 5, 7, 0, 0, 9, 8, 0, 0 },
        new int[9]{ 3, 0, 0, 0, 6, 0, 0, 1, 0 },
        new int[9]{ 0, 0, 0, 3, 7, 0, 9, 2, 0 },
        new int[9]{ 0, 0, 9, 0, 0, 5, 0, 0, 0 },
        new int[9]{ 0, 3, 0, 0, 0, 6, 0, 0, 0 },
        new int[9]{ 0, 4, 5, 0, 1, 8, 0, 9, 6 },
        new int[9]{ 1, 9, 6, 7, 0, 0, 2, 8, 0 },
    };*/

    /*int** arr = new int* [9]{
        new int[9]{ 2, 5, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 3, 0, 9, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 1, 0, 0, 6, 0, 0, 0 },
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 3 },
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 6, 0, 3, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 1, 3, 2, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
        new int[9]{ 0, 6, 4, 0, 0, 0, 0, 0, 0 },
    };*/

    /**/

    /*int** arr = new int* [9]{         //Level 3
        new int[9]{ 2, 0, 0, 4, 0, 6, 0, 0, 9 },
        new int[9]{ 0, 0, 1, 0, 0, 0, 7, 0, 8 },
        new int[9]{ 0, 3, 5, 0, 9, 8, 0, 0, 4 },
        new int[9]{ 0, 4, 9, 6, 5, 0, 0, 0, 0 },
        new int[9]{ 0, 6, 0, 1, 0, 4, 0, 2, 0 },
        new int[9]{ 0, 0, 0, 0, 8, 3, 4, 7, 0 },
        new int[9]{ 9, 0, 0, 5, 2, 0, 6, 3, 0 },
        new int[9]{ 3, 0, 7, 0, 0, 0, 5, 0, 0 },
        new int[9]{ 1, 0, 0, 3, 0, 7, 0, 0, 2 },
    };*/

    //int** arr = new int* [9]{         //Level 4
    //    new int[9]{ 9, 2, 3, 0, 0, 0, 0, 1, 6 },
    //    new int[9]{ 0, 0, 0, 0, 5, 0, 0, 0, 0 },
    //    new int[9]{ 5, 0, 0, 1, 0, 0, 8, 0, 7 },
    //    new int[9]{ 6, 1, 0, 0, 0, 8, 7, 0, 0 },
    //    new int[9]{ 0, 0, 0, 2, 1, 9, 0, 0, 0 },
    //    new int[9]{ 0, 0, 9, 3, 0, 0, 0, 8, 2 },
    //    new int[9]{ 3, 0, 1, 0, 0, 6, 0, 0, 4 },
    //    new int[9]{ 0, 0, 0, 0, 3, 0, 0, 0, 0 },
    //    new int[9]{ 8, 4, 0, 0, 0, 0, 2, 3, 1 },
    //};

    //int** arr = new int* [9]{         //Level 5
    //    new int[9]{ 5, 0, 0, 0, 0, 0, 6, 2, 0 },
    //    new int[9]{ 1, 0, 6, 0, 0, 4, 5, 0, 0 },
    //    new int[9]{ 0, 9, 0, 2, 0, 0, 0, 0, 0 },
    //    new int[9]{ 0, 8, 0, 0, 2, 0, 0, 1, 6 },
    //    new int[9]{ 0, 0, 0, 5, 0, 3, 0, 0, 0 },
    //    new int[9]{ 9, 1, 0, 0, 8, 0, 0, 3, 0 },
    //    new int[9]{ 0, 0, 0, 0, 0, 2, 0, 8, 0 },
    //    new int[9]{ 0, 0, 9, 8, 0, 0, 7, 0, 2 },
    //    new int[9]{ 0, 3, 8, 0, 0, 0, 0, 0, 1 },
    //};

    //int** arr = new int* [9]{         //Level 0
    //    new int[9]{ 0, 0, 0, 0, 0, 0, 5, 0, 0 },
    //    new int[9]{ 0, 7, 0, 9, 0, 0, 0, 0, 2 },
    //    new int[9]{ 0, 4, 0, 6, 8, 0, 1, 0, 0 },
    //    new int[9]{ 0, 0, 0, 0, 3, 2, 0, 0, 0 },
    //    new int[9]{ 0, 0, 6, 0, 9, 0, 0, 0, 4 },
    //    new int[9]{ 5, 0, 3, 0, 0, 4, 0, 0, 0 },
    //    new int[9]{ 0, 0, 0, 0, 0, 1, 0, 0, 6 },
    //    new int[9]{ 7, 0, 0, 0, 0, 0, 0, 0, 1 },
    //    new int[9]{ 0, 0, 9, 0, 0, 0, 0, 7, 0 },
    //};

    //Map* map = new Map{ arr };

    //LevelCreation a{ map };

    ///*while (true)
    //{
    //    if (!a.check1())
    //    {
    //        break;
    //    }
    //}*/
    //

    //map->show();
    //map->check();
    
    
    Map* map = new Map{};

    map->generate();

    Map* temp;

    LevelCreation* a = new LevelCreation {map};

    int value;

    for (int i{}; i < 10; ++i)
    {
        temp = a->generate(i % 3);

        recroding(a, temp, map);

        std::cout << i + 1 << "\n";
    }

    //int** arr = new int* [9]{         //Level 0
    //    new int[9]{ 0, 0, 0, 0, 0, 1, 4, 7, 0 },
    //    new int[9]{ 0, 0, 9, 0, 3, 2, 0, 8, 0 },
    //    new int[9]{ 6, 0, 0, 0, 0, 0, 0, 0, 0 },
    //    new int[9]{ 0, 0, 0, 3, 8, 0, 0, 0, 4 },
    //    new int[9]{ 0, 8, 0, 6, 0, 0, 0, 0, 2 },
    //    new int[9]{ 0, 0, 0, 2, 0, 5, 3, 0, 0 },
    //    new int[9]{ 0, 3, 7, 0, 4, 0, 6, 0, 9 },
    //    new int[9]{ 2, 0, 0, 0, 0, 0, 0, 0, 0 },
    //    new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    //};

    //Map* map = new Map{ arr };

    //CheckDifficult a{ map };

    //a.checkComplexity();
    //

    //map->show();
    //map->check();
    

    
    //delete a;
    
    
    
}