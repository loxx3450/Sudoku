#pragma once
#include "Map.h"
#include "LevelCreation.h"
#include <sstream>

class Creator
{
private:
	static int index;

	Map* solution;
	Map* level;
	LevelCreation* creator;
	std::string levelStr;
	std::string solutionStr;


public:
	Creator() :
		level{ new Map{} },
		solution{ new Map{} },
		creator{ new LevelCreation{solution} },
		levelStr{""},
		solutionStr{""}
	{}
	
	void create(int value)
	{
		level = creator->generate(value);

		for (int i{}; i < 9; ++i)
		{
			for (int j{}; j < 9; ++j)
			{
				levelStr += std::to_string(level->getArr()[i][j].getNum());
				solutionStr += std::to_string(solution->getArr()[i][j].getNum());
			}
		}

		++index;
	}

	int getIndex()
	{
		return this->index;
	}

	std::string getLevel()
	{
		return this->levelStr;
	}

	std::string getSolution()
	{
		return this->solutionStr;
	}

	void resetIndex()
	{
		this->index = 0;
	}

	~Creator()
	{
		if (this->creator != nullptr)
		{
			delete this->creator;
		}
		if (this->level != nullptr)
		{
			delete this->level;
		}
	}

};

int Creator::index = 0;