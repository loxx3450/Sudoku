#pragma once


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

	void addNote(int value)
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

	void setNum(int temp_num)
	{
		this->number = temp_num;
	}

	void setCell(Cell* temp)
	{
		this->number = temp->number;

		if (temp->notes != nullptr)
		{
			if (this->notes != nullptr)
			{
				delete[] notes;
			}

			this->notes = new bool[9]{};

			for (int i{}; i < 9; ++i)
			{
				this->notes[i] = temp->notes[i];
			}
		}
	}

	Cell* getCell()
	{
		return this;
	}

	int getNum()
	{
		return this->number;
	}

	void showNotes(int i = 0, int j = 0)
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

	int countOfNotes()
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

	bool* getNotes()
	{
		if (this->notes != nullptr)
		{
			return this->notes;
		}
		return nullptr;
	}

	void editNotes(bool* notes)
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

	bool operator==(bool* notes)
	{
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

	void operator-(bool* notes)
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

	~Cell()
	{
		if (this->notes != nullptr)
		{
			delete[] notes;
		}
	}

};