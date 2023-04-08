#pragma once
#include <iostream>


class Cell
{
private:
	int number;
	bool* notes;

public:
	Cell():
		number{0},
		notes{nullptr}
	{}

	Cell(const Cell& temp) :
		number{ temp.number },
		notes{nullptr}
	{
		if (temp.notes != nullptr)
		{
			this->notes = new bool[9];

			for (int i{}; i < 9; ++i)
			{
				this->notes[i] = temp.notes[i];
			}
		}
	}

	void addNote(int value);

	void setNum(int temp_num);

	void setCell(Cell* temp);

	Cell* getCell();

	int getNum();

	void showNotes(int i = 0, int j = 0);

	bool inNotes(int value);

	int countOfNotes();

	bool* getNotes();

	void editNotes(bool* notes);

	void deleteNotes();

	void editNotes(int* hiddenNumbers, int count);

	bool operator==(bool* notes);

	~Cell()
	{
		if (this->notes != nullptr)
		{
			delete[] notes;
		}
	}

};