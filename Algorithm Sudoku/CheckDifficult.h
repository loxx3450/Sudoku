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
	int complexity = 0;
	bool isNotes = 0;

	bool checkFields();

	bool checkStrings();

	bool checkColumns();

	bool checkExceptInField();

	bool checkExceptInString();

	bool checkExceptInColumn();

	bool checkExceptInStr_Col_Field();

	void makeNotes();

	bool checkNakedCouples();

	bool checkNakedTriplets();

	bool checkNakedFoursome();

	bool isOnlyOneNote();

	bool checkHiddenCouples();

	bool checkHiddenTriplets();

	bool hiddenNote();


	bool checkEasy();

	bool checkMedium();

	bool checkHard();

	bool checkExtreme();

public:
	CheckDifficult(Map* map)
	{
		this->map = new Map{ *map };
	}

	bool checkComplexity(int complexity);

	int getComplexity();

	~CheckDifficult()
	{
		if (this->map != nullptr) {
			delete this->map;
		}
	}
};

