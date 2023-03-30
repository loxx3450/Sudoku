#pragma once
#include "Solution.h"
#include "Map.h"

class LevelCreation
{
private:
	Map* map;
    Solution solution;

	bool checkFields()
	{
		Field* temp = new Field{};
		for (int i{}; i < 3; ++i)
		{
			for (int j{}; j < 3; ++j)
			{
				temp->generate(map->getArr(), i * 3, j * 3);
				if (solution.lastInField(temp))
				{
					this->map->takeField(temp, i * 3, j * 3);

					return true;
				}
			}
		}

		return false;
	}

	bool checkStrings()
	{
		for (int i{}; i < 9; ++i)
		{
			if (solution.lastInRow(this->map->getString(i)))
			{
				return true;
			}
		}

		return false;
	}

	bool checkColumns()
	{
		int* tmp;
		for (int i{}; i < 9; ++i)
		{
			tmp = this->map->getColumn(i);
			if (solution.lastInRow(tmp))
			{
				this->map->setColumn(tmp, i);

				return true;
			}
		}

		return false;
	}

	bool checkFieldsExceptions()
	{
		Field* temp = new Field{};
		for (int i{}; i < 3; ++i)
		{
			for (int j{}; j < 3; ++j)
			{
				temp->generate(this->map->getArr(), i * 3, j * 3);
				if (solution.exceptionInField(this->map->getArr(), temp, i, j))
				{
					return true;
				}
			}
		}

		return false;
	}

public:
	LevelCreation(Map* map)
	{
		this->map = new Map{ *map };
	}

	bool check1()
	{
		if (checkFields())
		{
			std::cout << "LastInField\n";
			return true;
		}
		if (checkStrings())
		{
			std::cout << "LastInString\n";
			return true;
		}
		if (checkColumns())
		{
			std::cout << "LastInColumn\n";
			return true;
		}
		if (checkFieldsExceptions())
		{
			std::cout << "ExceptionInField\n";
			return true;
		}

		return false;
	}
};