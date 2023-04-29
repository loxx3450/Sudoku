#include <iostream>
#include "Map.h"
#include "Solution.h"
#include "LevelCreation.h"
#include "Database.h"


int main()
{
    srand(time(NULL));
    rand();

    Database* db = new Database{};

    db->createTables();

    db->record(1, "EASY", 0);
    db->record(1, "MEDIUM", 1);
    db->record(1, "HARD", 2);
    db->record(1, "EXTREME", 3);
    db->record(1, "INSANE", 4);


    //int** arr = new int* [9]{         //Level 0
    //    new int[9]{ 0,0,6,0,0,0,1,0,0 },
    //    new int[9]{ 2,0,0,7,0,0,3,0,0 },
    //    new int[9]{ 0,5,3,0,0,0,0,4,8 },
    //    new int[9]{ 0,0,0,0,0,0,0,0,0 },
    //    new int[9]{ 0,3,1,0,8,0,0,2,0 },
    //    new int[9]{ 8,0,0,0,0,0,0,9,4 },
    //    new int[9]{ 0,0,0,5,0,1,0,0,0 },
    //    new int[9]{ 0,0,0,0,0,9,0,0,6 },
    //    new int[9]{ 9,6,2,0,0,0,0,0,0 },
    //};

    //Map* map = new Map{arr};

    //CheckDifficult temp{ map };

    //temp.checkComplexity(4);

    //map->show();
    //map->check();
    //map->showNotes();

}