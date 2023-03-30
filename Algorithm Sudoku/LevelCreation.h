#pragma once
#include "Solution.h"
#include "Map.h"

class LevelCreation
{
private:
	const int map_count = 9;
	const int field_count = 3;

	Map* map;
    Solution solution;

	bool checkFields();

	bool checkStrings();

	bool checkColumns()
	{
		int* tmp;

		for (int i{}; i < this->map_count; ++i)
		{
			tmp = this->map->getColumn(i);

			if (solution.lastInRow(tmp))
			{
				this->map->setColumn(tmp, i);

				return true;
			}
		}

		//delete tmp;	!!!!!!!!!!

		return false;
	}

	bool checkFieldsExceptions();

public:
	LevelCreation(Map* map)
	{
		this->map = new Map{ *map };
	}

	bool check1();

	~LevelCreation()
	{
		if (this->map != nullptr){
			delete this->map;
		}
	}
};