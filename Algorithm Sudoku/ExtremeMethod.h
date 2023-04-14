#pragma once
#include "Map.h"
#include "Method.h"
#include "Point.h"
#include "NakedGroup.h"
#include "NakedCouple.h"
#include "NakedTriplet.h"

class ExtremeMethod : public Method
{
private:
	NakedGroup* nakedGroup = nullptr;

	void editCellsAround(Map* map, int value, int i, int j);

	void makeNoteOnCell(Map* map, Field* temp, Cell* string, Cell* column, int temp_i, int temp_j);

	void fillNumbersWithFieldNotes(Field* temp);

	bool findPossibleHiddenNote(Field* temp, Map* map, int map_i, int map_j, int index);

public:
	ExtremeMethod() :
		Method{}
	{}

	void makeNotes(Map* map, Field* temp, int temp_i, int temp_j);

	bool nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j);
	
	bool nakedCouplesInRow(Cell* row);

	bool nakedtripletsInField(Map* map, Field* temp, int temp_i, int temp_j);

	bool nakedTripletsInRow(Cell* row);

	bool isOnlyOneNote(Map* map);

	bool hiddenNote(Map* map);

	~ExtremeMethod()
	{
		if (this->nakedGroup != nullptr)
		{
			delete this->nakedGroup;
		}
	}

};

