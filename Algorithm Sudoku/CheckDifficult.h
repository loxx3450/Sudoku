#pragma once
#include "Solution.h"
#include "Map.h"

class CheckDifficult
{
private:
	const int map_size = 9;
	const int field_size = 3;

	Map* map;
	Solution* solution;
	int complexity = 0;

	bool methodForField(Solution* obj, bool(Solution::* func)(Map*, Field*, int, int));

	bool methodForString(Solution* obj, bool(Solution::* func)(Cell*));

	bool methodForColumn(Solution* obj, bool(Solution::* func)(Cell*));

	bool checkFields();

	bool checkStrings();

	bool checkColumns();

	bool checkExceptInField();

	bool checkExceptInString();

	bool checkExceptInColumn();

	bool checkExceptInStr_Col_Field();

	void extremeMethodForNotes();

	void insaneMethodForNotes();

	void makeNotes();

	bool checkNakedCouples();

	bool checkNakedTriplets();

	bool checkNakedFoursome();

	bool isOnlyOneNote();

	bool checkHiddenCouples();

	bool checkHiddenTriplets();

	bool checkHiddenFoursome();

	bool checkPointingGroup(int size);

	bool hiddenNote();


	bool checkEasy();

	bool checkMedium();

	bool checkHard();

	bool checkExtreme();

	bool checkInsane();

public:
	CheckDifficult(Map* map)
	{
		this->map = new Map{ *map };
		this->solution = new Solution{};
	}

	bool checkComplexity(int complexity);

	int getComplexity();

	~CheckDifficult()
	{
		if (this->map != nullptr) {
			delete this->map;
		}
		if (this->solution != nullptr) {
			delete this->solution;
		}
	}
};

