#include <iostream>
#include "Map.h"
#include "Solution.h"
#include "LevelCreation.h"
#include "sqlite/sqlite3.h"
#include <sstream>

#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

const std::string server = "127.0.0.1:3306";
const std::string username = "root";


int callback(void* NotUsed, int argc, char** argv, char** azColName) {

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for (int i = 0; i < argc; i++) {

        // Show column name, value, and newline
        std::cout << azColName[i] << ": " << argv[i] << std::endl;

    }

    // Insert a newline
    std::cout << std::endl;

    // Return successful
    return 0;
}

void record(sqlite3* db, std::string Difficulty, int value)
{
    Map* map = new Map{};

    Map* temp = new Map{};

    LevelCreation* a = new LevelCreation{ map };

    const char* data = "Callback function called";
    char* zErrMsg = 0;

    for (int i{}; i < 3; ++i)
    {
        std::string level{}, solution{};

        temp = a->generate(value);

        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                level += std::to_string(temp->getArr()[i][j].getNum());
                solution += std::to_string(map->getArr()[i][j].getNum());
            }
        }
        std::stringstream ss;
        ss << "INSERT INTO " << Difficulty << "('id', 'level', 'solution', 'isplayed') VALUES(" << i << ", '" << level << "', '" << solution << "', 0); ";
        sqlite3_exec(db, ss.str().c_str(), callback, (void*)data, &zErrMsg);

        std::cout << i << std::endl;
    }

    std::stringstream ss;
    ss << "SELECT * from " << Difficulty << ";";
    sqlite3_exec(db, ss.str().c_str(), callback, (void*)data, &zErrMsg);

    //delete temp;
    //delete a;
}



int main()
{
    srand(time(NULL));
    rand();

    sqlite3* db;
    char* err_message = 0;

    sqlite3_open("MyDb.db", &db);
    sqlite3_exec(db, "DROP TABLE IF EXISTS EASY;", 0, 0, &err_message);
    sqlite3_exec(db, "DROP TABLE IF EXISTS MEDIUM;", 0, 0, &err_message);
    sqlite3_exec(db, "DROP TABLE IF EXISTS HARD;", 0, 0, &err_message);
    sqlite3_exec(db, "DROP TABLE IF EXISTS EXTREME;", 0, 0, &err_message);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS EASY(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS MEDIUM(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS HARD(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS EXTREME(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);

    
    record(db, "EASY", 0);
    record(db, "MEDIUM", 1);
    record(db, "HARD", 2);
    record(db, "EXTREME", 3);


    //int** arr1 = new int* [9]{         //Level 0
    //    new int[9]{ 5, 3, 4, 6, 7, 8, 9, 1, 2 },
    //    new int[9]{ 6, 7, 2, 1, 9, 5, 3, 4, 8 },
    //    new int[9]{ 1, 9, 8, 3, 4, 2, 5, 6, 7 },
    //    new int[9]{ 8, 5, 9, 7, 6, 1, 4, 2, 3 },
    //    new int[9]{ 4, 2, 6, 8, 5, 3, 7, 9, 1 },
    //    new int[9]{ 7, 1, 3, 9, 2, 4, 8, 5, 6 },
    //    new int[9]{ 9, 6, 1, 5, 3, 7, 2, 8, 4 },
    //    new int[9]{ 2, 8, 7, 4, 1, 9, 6, 3, 5 },
    //    new int[9]{ 3, 4, 5, 2, 8, 6, 1, 7, 9 },
    //};

    //int** arr2 = new int* [9]{         //Level 0
    //    new int[9]{ 5,3,4,6,7,8,9,1,2 },
    //    new int[9]{ 6,7,2,1,9,5,3,4,8 },
    //    new int[9]{ 1,9,8,3,4,2,5,6,7 },
    //    new int[9]{ 8,5,9,7,6,1,4,2,3 },
    //    new int[9]{ 4,2,6,8,5,3,7,9,1 },
    //    new int[9]{ 7,1,3,9,2,4,8,5,6 },
    //    new int[9]{ 9,6,1,5,3,7,2,8,4 },
    //    new int[9]{ 2,8,7,4,1,9,6,3,5 },
    //    new int[9]{ 3,4,5,2,8,6,1,7,9 },
    //};

    //int** arr1 = new int* [9]{         //Level 0
    //    new int[9]{ 5,3,0,0,7,0,0,0,0 },
    //    new int[9]{ 6,0,0,1,9,5,0,0,0 },
    //    new int[9]{ 0,9,8,0,0,0,0,6,0 },
    //    new int[9]{ 8,0,0,0,6,0,0,0,3 },
    //    new int[9]{ 4,0,0,8,0,3,0,0,1 },
    //    new int[9]{ 7,0,0,0,2,0,0,0,6 },
    //    new int[9]{ 0,6,0,0,0,0,2,8,0 },
    //    new int[9]{ 0,0,0,4,1,9,0,0,5 },
    //    new int[9]{ 0,0,0,0,8,0,0,7,9 },
    //};

    //Map* map2 = new Map{ arr2};
    //Map* map1 = new Map{ arr1 };

    //LevelCreation a{ map2 };

    //std::cout << a.isOnlyOneSolution(map2, map1, 3);

    /*CheckDifficult temp{ map2 };

    temp.checkComplexity(3);
    map2->show();
    map2->check();*/

}