#pragma once
#include "NakedGroup.h"

class NakedCouple : public NakedGroup
{
private:

	bool editNotesForCouplesInField(Field* tempField, Cell* tempCell, int firstCell_i, int firstCell_j, int secondCell_i, int secondCell_j);

	bool editNotesForCouplesInRow(Cell* row, Cell* tempCell, int firstCell_index, int secondCell_index);

	bool findPossibleCouplesInField(Field* tempField, Cell* tempCell, int cell_i, int cell_j);

	bool findPossibleCouplesInRow(Cell* row, Cell* tempCell, int tempCell_index);

public:

	virtual bool nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j) override;

	virtual bool nakedCouplesInRow(Cell* row) override;
};

