#include <iostream>
#include "Map.h"
#include "Solution.h"
#include "LevelCreation.h"






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

    int** arr = new int* [9]{
        new int[9]{ 1, 2, 0, 4, 0, 6, 7, 8, 9 },
        new int[9]{ 0, 5, 6, 7, 8, 9, 1, 2, 3 },
        new int[9]{ 7, 8, 9, 1, 2, 3, 4, 0, 6 },
        new int[9]{ 2, 3, 4, 0, 6, 7, 8, 9, 1 },
        new int[9]{ 5, 6, 7, 8, 9, 1, 2, 3, 0},
        new int[9]{ 8, 0, 1, 2, 3, 4, 5, 6, 7 },
        new int[9]{ 3, 4, 0, 6, 7, 8, 9, 1, 2 },
        new int[9]{ 6, 7, 8, 9, 1, 2, 3, 0, 5 },
        new int[9]{ 9, 1, 2, 3, 0, 5, 0, 7, 8 }
    };

    /*int** arr = new int* [9]{
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 8, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 0, 0, 0, 0, 0, 8, 0, 0, 0 },
        new int[9]{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
        new int[9]{ 9, 6, 1, 0, 0, 0, 0, 0, 0 },
    };*/

    Map* map = new Map{ arr };

    LevelCreation a{ map };

    while (!map->isMade())
    {
        a.check1();
    }
    

    map->show();

    
    
    
}