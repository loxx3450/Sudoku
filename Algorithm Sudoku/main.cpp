#include <iostream>
#include "Map.h"
#include "Solution.h"
#include "LevelCreation.h"

#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

const std::string server = "127.0.0.1:3306";
const std::string username = "root";
const std::string password = "Logarithm8*";

int main()
{
    srand(time(NULL));
    rand();

    /*sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }
    con->setSchema("sudoku");

    pstmt = con->prepareStatement("INSERT INTO sudoku(Level, Solution, Complexity, isPlayed) VALUES(?,?,?,?)");

    Map* map = new Map{};

    Map* temp;

    LevelCreation* a = new LevelCreation{ map };

    for (int i{}; i < 10; ++i)
    {
        std::string level{}, solution{};

        temp = a->generate(2);

        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                level += std::to_string(temp->getArr()[i][j].getNum());
                solution += std::to_string(map->getArr()[i][j].getNum());
            }
        }

        
        pstmt->setString(1, level);
        pstmt->setString(2, solution);
        pstmt->setInt(3, a->getComplexity());
        pstmt->setBoolean(4, false);
        pstmt->execute();
        std::cout << "Row inserted:" << i << std::endl;
    }

    delete pstmt;
    delete con;*/

    /*stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS inventory");
    std::cout << "Finished dropping table (if existed)" << std::endl;
    stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
    std::cout << "Finished creating table" << std::endl;
    delete stmt;

    pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();
    std::cout << "One row inserted." << std::endl;

    pstmt->setString(1, "orange");
    pstmt->setInt(2, 154);
    pstmt->execute();
    std::cout << "One row inserted." << std::endl;

    pstmt->setString(1, "apple");
    pstmt->setInt(2, 100);
    pstmt->execute();
    std::cout << "One row inserted." << std::endl;

    delete pstmt;
    delete con;
    system("pause");*/
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


   /* Map* map = new Map{};

    map->generate();

    Map* temp;

    LevelCreation* a = new LevelCreation {map};

    int value;

    for (int i{}; i < 10; ++i)
    {
        temp = a->generate(i % 3);

        recording(a, temp, map);

        std::cout << i + 1 << "\n";
    }*/

//'147328596598167342263459871721546983456893217389271654672984135915732468834615729', '2', '0'



    //int** arr = new int* [9]{         //Level 4
    //    new int[9]{ 9,1,3,5,6,8,7,2,4 },
    //    new int[9]{ 6,8,7,0,4,2,0,0,0 },
    //    new int[9]{ 2,5,4,1,0,0,0,8,0 },
    //    new int[9]{ 5,0,0,0,0,9,4,0,0 },
    //    new int[9]{ 1,0,0,7,0,4,0,9,5 },
    //    new int[9]{ 4,0,9,0,0,0,0,3,0 },
    //    new int[9]{ 3,4,5,0,0,6,1,7,8 },
    //    new int[9]{ 7,2,6,8,0,0,9,4,3 },
    //    new int[9]{ 8,9,1,4,0,0,0,0,2 },
    //};

    //int** arr = new int* [9]{         //Level 4
    //        new int[9]{ 0,1,3,0,6,0,7,0,0 },
    //        new int[9]{ 0,0,7,0,0,2,0,0,0 },
    //        new int[9]{ 2,0,4,1,0,0,0,8,0 },
    //        new int[9]{ 5,0,0,0,0,9,4,0,0 },
    //        new int[9]{ 0,0,0,7,0,0,0,9,5 },
    //        new int[9]{ 4,0,0,0,0,0,0,3,0 },
    //        new int[9]{ 0,0,5,0,0,6,1,0,0 },
    //        new int[9]{ 0,2,0,8,0,0,9,0,3 },
    //        new int[9]{ 0,9,1,4,0,0,0,0,2 },
    //};

//int** arr = new int* [9]{         //Level 4
//            new int[9]{ 5,6,0,4,0,0,1,9,3 },
//            new int[9]{ 3,4,0,9,1,5,0,0,7 },
//            new int[9]{ 1,9,0,0,0,3,5,0,0 },
//            new int[9]{ 2,0,9,7,0,0,0,0,0 },
//            new int[9]{ 7,0,4,5,9,8,0,0,0 },
//            new int[9]{ 6,8,5,0,0,0,7,0,9 },
//            new int[9]{ 9,0,6,0,0,0,4,0,0 },
//            new int[9]{ 8,0,1,0,4,9,2,0,0 },
//            new int[9]{ 4,0,3,0,5,0,9,8,0 },
//};

    // int** arr = new int* [9]{         //level 4
    //        new int[9]{ 0,0,0,0,7,0,0,1,5 },
    //        new int[9]{ 1,0,0,0,2,9,7,0,0 },
    //        new int[9]{ 3,0,0,5,0,0,9,0,0 },
    //        new int[9]{ 0,6,0,0,0,0,0,0,7 },
    //        new int[9]{ 0,8,0,7,4,5,0,0,0 },
    //        new int[9]{ 7,0,0,0,0,0,2,8,0 },
    //        new int[9]{ 0,0,0,0,8,0,6,0,0 },
    //        new int[9]{ 6,9,4,0,0,0,0,0,0 },
    //        new int[9]{ 0,0,0,0,1,0,0,4,0 },
    //};

int** arr = new int* [9]{         //level 4
             new int[9]{ 4,0,0,0,9,0,0,0,0 },
             new int[9]{ 0,1,0,0,0,0,3,0,0 },
             new int[9]{ 0,8,0,0,0,0,1,0,7 },
             new int[9]{ 0,0,6,0,0,0,0,0,3 },
             new int[9]{ 0,0,9,0,7,2,0,5,0 },
             new int[9]{ 0,0,0,0,0,4,0,2,6 },
             new int[9]{ 0,0,2,0,0,7,0,8,0 },
             new int[9]{ 5,0,0,0,0,6,0,0,0 },
             new int[9]{ 0,0,0,8,5,0,0,0,0 },
};

    Map* map = new Map{ arr };

    CheckDifficult a{ map };

    a.checkComplexity();

    map->show();
    map->check();

    //std::ofstream out;
    //out.open("C:\\Users\\egork\\source\\repos\\Algorithm Sudoku\\Kozachok.txt", std::ios::app);

    //for (int i{}; i < 9; ++i)
    //{
    //    for (int j{}; j < 9; ++j)
    //    {
    //        out << map->getArr()[i][j];
    //    }
    //}

    //delete a;



}