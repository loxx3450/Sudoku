#pragma once
#include "Map.h"
#include "Point.h"

class HiddenGroup
{
protected:
	const int map_size = 9;
	const int field_size = 3;
	int* numbers;

	void clearNumbers()
	{
		for (int i{}; i < this->map_size; ++i)
		{
			this->numbers[i] = 0;
		}
	}

	void overrideNumbersWithFieldNotes(Field* temp)
	{
		for (int i{}; i < this->field_size; ++i)
		{
			for (int j{}; j < this->field_size; ++j)
			{
				for (int g{}; g < this->map_size; ++g)
				{
					if (temp->getCell(i, j)->inNotes(g + 1))
					{
						this->numbers[g]++;
					}
				}

			}
		}
	}

	void overrideNumbersWithRowNotes(Cell* row)
	{
		for (int i{}; i < this->map_size; ++i)
		{
			for (int j{}; j < this->map_size; ++j)
			{
				if (row[i].inNotes(j + 1))
				{
					this->numbers[j]++;
				}
			}
		}
	}

	bool editNotesInField(Field* temp, int* hiddenNumbers, Point* array, int size)
	{
		bool flag{ false };

		for (int i{}; i < size; ++i)
		{
			if (temp->getCell(array[i].getX(), array[i].getY())->editNotes(hiddenNumbers, size))
			{
				flag = true;
			}
		}

		return flag;
	}

	bool editNotesInRow(Cell* row, int* hiddenNumbers, int* array, int size)
	{
		bool flag{ false };

		for (int i{}; i < size; ++i)
		{
			if (row[array[i]].editNotes(hiddenNumbers, size))
			{
				flag = true;
			}
		}

		return flag;
	}

public:
	HiddenGroup() :
		numbers{new int[9]}
	{}

	virtual bool hiddenCouplesInRow(Cell* row)
	{


		return false;
	}

	virtual bool hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}

	virtual bool hiddenTripletsInRow(Cell* row)
	{
		return false;
	}

	virtual bool hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
	{


		return false;
	}

	~HiddenGroup()
	{
		if (this->numbers != nullptr)
		{
			delete[] numbers;
		}
	}
};