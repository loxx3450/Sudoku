#include "ExtremeMethod.h"

void ExtremeMethod::editCellsAround(Map* map, int value, int i, int j)
{
	Field* tempField = new Field{};

	tempField->generate(map->getArr(), (int)(i / 3), (int)(j / 3));

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (tempField->getCell(i, j)->getNotes() != nullptr && tempField->getNum(i, j) == 0)
			{
				tempField->removeCellNote(value, i, j);
			}
		}
	}

	delete tempField;

	Cell* string = map->getString(i);

	for (int i{}; i < this->map_size; ++i)
	{
		if (string[i].getNotes() == nullptr && string[i].getNum() == 0)
		{
			string[i].removeNote(value);
		}
	}

	Cell* column = map->getColumn(j);

	for (int i{}; i < this->map_size; ++i)
	{
		if (column[i].getNotes() == nullptr && column[i].getNum() == 0)
		{
			column[i].removeNote(value);
		}
	}

	map->setColumn(column, j);

	delete[] column;

}

void ExtremeMethod::makeNoteOnCell(Map* map, Field* temp, Cell* string, Cell* column, int temp_i, int temp_j)
{
	this->clearNumbers();

	this->overrideNumbersWithField(temp);

	this->overrideNumbersWithRow(string);

	this->overrideNumbersWithRow(column);

	map->getArr()[temp_i][temp_j].clearNotes();

	for (int index{}; index < this->map_size; ++index)
	{
		if (this->numbers[index] == 0)
		{
			map->getArr()[temp_i][temp_j].addNote(index + 1);
		}
	}
}

void ExtremeMethod::fillNumbersWithFieldNotes(Field* temp)
{
	this->clearNumbers();

	bool* notes = new bool[9];

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (temp->getCell(i, j)->getNotes() != nullptr && temp->getNum(i, j) == 0)
			{
				for (int index{}; index < this->map_size; ++index)
				{
					notes[index] = temp->getCell(i, j)->inNotes(index + 1);
				}

				for (int g{}; g < this->map_size; ++g)
				{
					if (notes[g] == true)
					{
						numbers[g]++;
					}
				}
			}
		}
	}

	delete[] notes;
}

bool ExtremeMethod::findPossibleHiddenNote(Field* temp, Map* map, int map_i, int map_j, int index)
{
	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (temp->getCell(i, j)->getNotes() != nullptr && temp->getNum(i, j) == 0 && temp->getCell(i, j)->inNotes(index + 1))
			{
				temp->setNum(index + 1, i, j);
				temp->getCell(i, j)->deleteNotes();
				this->editCellsAround(map, index + 1, i, j);

				return true;
			}
		}
	}
}

void ExtremeMethod::makeNotes(Map* map, Field* temp, int temp_i, int temp_j)
{
	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (temp->getNum(i, j) == 0)
			{
				this->makeNoteOnCell(map, temp, map->getString(temp_i * 3 + i), map->getColumn(temp_j * 3 + j), temp_i * 3 + i, temp_j * 3 + j);
			}
		}
	}
}

bool ExtremeMethod::nakedCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (this->nakedGroup != nullptr)
	{
		delete nakedGroup;
	}
	this->nakedGroup = new NakedCouple{};

	return nakedGroup->nakedCouplesInField(map, temp, temp_i, temp_j);
}

bool ExtremeMethod::nakedCouplesInRow(Cell* row)
{
	return nakedGroup->nakedCouplesInRow(row);
}

bool ExtremeMethod::nakedtripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (this->nakedGroup != nullptr)
	{
		delete nakedGroup;
	}
	this->nakedGroup = new NakedTriplet{};
	return this->nakedGroup->nakedTripletsInField(map, temp, temp_i, temp_j);
}

bool ExtremeMethod::nakedTripletsInRow(Cell* row)
{
	return this->nakedGroup->nakedTripletsInRow(row);
}

bool ExtremeMethod::isOnlyOneNote(Map* map)
{
	for (int i{}; i < this->map_size; ++i)
	{
		for (int j{}; j < this->map_size; ++j)
		{
			if (map->getArr()[i][j].countOfNotes() == 1)
			{
				for (int index{}; index < this->map_size; ++index)
				{
					if (map->getArr()[i][j].inNotes(index + 1))
					{
						map->setNum(index + 1, i, j);
						map->getArr()[i][j].deleteNotes();
						this->editCellsAround(map, index + 1, i, j);

						return true;
					}
				}
			}
		}
	}



	return false;
}

bool ExtremeMethod::hiddenNote(Map* map)
{
	Field* temp = new Field{};

	for (int map_i{}; map_i < this->field_size; ++map_i)
	{
		for (int map_j{}; map_j < this->field_size; ++map_j)
		{
			temp->generate(map->getArr(), map_i * 3, map_j * 3);

			this->fillNumbersWithFieldNotes(temp);

			for (int index{}; index < this->map_size; ++index)
			{
				if (numbers[index] == 1)
				{
					if (this->findPossibleHiddenNote(temp, map, map_i, map_j, index))
					{
						map->takeField(temp, map_i, map_j);

						delete temp;

						return true;
					}
				}
			}
		}

	}

	delete temp;

	return false;

}
