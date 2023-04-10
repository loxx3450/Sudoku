#pragma once
#include "Solution.h"
#include "Map.h"

class CheckDifficult
{
private:
	const int map_size = 9;
	const int field_size = 3;

	Map* map;
	Solution solution;
	bool isNotes = 0;
	int complexity = 0;

	bool checkFields();

	bool checkStrings();

	bool checkColumns()
	{
		Cell* tmp;

		for (int i{}; i < this->map_size; ++i)
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

	bool checkExceptInField();

	bool checkExceptInString();

	bool checkExceptInColumn();

	bool checkExceptInStr_Col_Field();

	void makeNotes();

	void checkNakedCouples();

	void checkNakedTriplets();

	bool isOnlyOneNote();

	bool check();

public:
	CheckDifficult(Map* map)
	{
		this->map = new Map{ *map };
	}

	bool checkComplexity();

	int getComplexity();

	~CheckDifficult()
	{
		if (this->map != nullptr) {
			delete this->map;
		}
	}
};

