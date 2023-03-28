#pragma once
#include "Solution.h"
#include "Map.h"

class LevelCreation
{
private:
	Map* map;
    Solution solution;

	void checkFields()
	{
		Field* temp = new Field{};
		for (int i{}; i < 3; ++i)
		{
			for (int j{}; j < 3; ++j)
			{
				temp->generate(map->getArr(), i * 3, j * 3);
				solution.lastInField(temp);
				this->map->takeField(temp, i * 3, j * 3);
			}
		}
	}

	void checkStrings()
	{
		for (int i{}; i < 9; ++i)
		{
			solution.lastInRow(this->map->getString(i));
		}
	}

	void checkColumns()
	{
		int* tmp;
		for (int i{}; i < 9; ++i)
		{
			tmp = this->map->getColumn(i);
			solution.lastInRow(tmp);
			this->map->setColumn(tmp, i);
		}
	}

	void checkFieldsExceptions()
	{
		Field* temp = new Field{};
		for (int i{}; i < 3; ++i)
		{
			for (int j{}; j < 3; ++j)
			{
				temp->generate(this->map->getArr(), i * 3, j * 3);
				solution.exceptcionInField(this->map->getArr(), temp, i, j);
			}
		}
	}

public:
	LevelCreation(Map* map)
	{
		this->map = new Map{ *map };
	}

	void check1()
	{
		checkFields();
		checkStrings();
		checkColumns();
		checkFieldsExceptions();
	}
};