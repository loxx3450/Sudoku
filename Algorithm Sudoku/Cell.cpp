#include "Cell.h"

void Cell::addNote(int value)
{
	if (this->number == 0)
	{
		if (this->notes == nullptr)
		{
			this->notes = new bool[9]{ false };
		}

		this->notes[value - 1] = true;
	}
}

void Cell::setNum(int temp_num)
{
	this->number = temp_num;
}

void Cell::setCell(Cell* temp)
{
	if (temp != nullptr)
	{
		this->number = temp->number;

		if (temp->notes != nullptr && temp->number == 0)
		{
			if (this->notes == nullptr)
			{
				this->notes = new bool[9]{ false };
			}

			for (int i{}; i < 9; ++i)
			{
				this->notes[i] = temp->notes[i];
			}
		}
	}
	
}

Cell* Cell::getCell()
{
	return this;
}

int Cell::getNum()
{
	return this->number;
}

void Cell::showNotes(int i, int j)
{
	if (this->notes != nullptr && this->number == 0)
	{
		std::cout << i << "; " << j << ": " << this->countOfNotes() << "\n";
		for (int i{}; i < 9; ++i)
		{
			if (this->notes[i] == true)
			{
				std::cout << i + 1;
			}
		}
		std::cout << "\n";
	}

}

bool Cell::inNotes(int value)
{
	if (this->notes != nullptr && this->number == 0)
	{
		return this->notes[value - 1];
	}

	return false;
}

int Cell::countOfNotes()
{
	if (this->notes != nullptr && this->number == 0)
	{
		int count{};

		for (int i{}; i < 9; ++i)
		{
			if (this->notes[i] == true)
			{
				++count;
			}
		}

		return count;
	}

	return 0;
}

bool* Cell::getNotes()
{
	if (this->notes != nullptr)
	{
		return this->notes;
	}
	return nullptr;
}

void Cell::editNotes(bool* notes)
{
	if (notes != nullptr && this->notes != nullptr)
	{
		for (int i{}; i < 9; ++i)
		{
			if (notes[i] == true && this->notes[i] == true)
			{
				this->notes[i] = false;
			}
		}
	}
}

void Cell::deleteNotes()
{
	if (notes != nullptr)
	{
		delete[] notes;

		notes = nullptr;
	}
}

void Cell::clearNotes()
{
	if (this->notes != nullptr)
	{
		for (int i{}; i < 9; ++i)
		{
			this->notes[i] = false;
		}
	}
	
}

void Cell::editNotes(int* hiddenNumbers, int count)
{
	if (this->notes != nullptr)
	{
		delete[] notes;
		notes = new bool[9]{ false };

		for (int i{}; i < count; ++i)
		{
			notes[hiddenNumbers[i] - 1] = true;
		}
	}
}

bool Cell::operator==(bool* notes)
{
	int chance{};
	if (notes != nullptr && this->notes != nullptr)
	{
		for (int i{}; i < 9; ++i)
		{
			if (this->notes[i] != notes[i])
			{
				return false;
			}
		}

		return true;
	}

	return false;
}