#pragma once
#include "Creator.h"
#include "sqlite/sqlite3.h"

int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		std::cout << azColName[i] << ": " << argv[i] << std::endl;
	}

	std::cout << std::endl;

	return 0;
}

class Database
{
private:
	Creator* creator;
	sqlite3* db;

	void dropTables()
	{
		char* err_message = 0;

		sqlite3_exec(db, "DROP TABLE IF EXISTS EASY;", 0, 0, &err_message);
		sqlite3_exec(db, "DROP TABLE IF EXISTS MEDIUM;", 0, 0, &err_message);
		sqlite3_exec(db, "DROP TABLE IF EXISTS HARD;", 0, 0, &err_message);
		sqlite3_exec(db, "DROP TABLE IF EXISTS EXTREME;", 0, 0, &err_message);
		sqlite3_exec(db, "DROP TABLE IF EXISTS INSANE;", 0, 0, &err_message);
	}

public:
	Database() :
		creator{ new Creator{} }
	{}

	void createTables()
	{
		char* err_message = 0;

		sqlite3_open("MyDb.db", &db);
		this->dropTables();
		sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS EASY(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
		sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS MEDIUM(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
		sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS HARD(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
		sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS EXTREME(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
		sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS INSANE(id INT PRIMARY KEY, level varchar(81), solution varchar(81), isplayed BOOLEAN NOT NULL CHECK (isplayed IN (0, 1)));", 0, 0, &err_message);
	}

	void record(int times, std::string complexity, int value)
	{
		const char* data = "Callback function called";
		char* zErrMsg = 0;

		for (int i{}; i < times; ++i)
		{
			this->creator->create(value);

			std::stringstream ss;
			ss << "INSERT INTO " << complexity << "('id', 'level', 'solution', 'isplayed') VALUES(" << this->creator->getIndex() << ", '" << this->creator->getLevel() << "', '" << this->creator->getSolution() << "', 0); ";
			sqlite3_exec(db, ss.str().c_str(), callback, (void*)data, &zErrMsg);
		
			std::cout << this->creator->getIndex() << "\n";
		}

		this->creator->resetIndex();
	}

	~Database()
	{
		if (this->creator != nullptr)
		{
			delete this->creator;
		}
		if (this->db != nullptr)
		{
			delete this->db;
		}
	}

};

