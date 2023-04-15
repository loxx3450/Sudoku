#pragma once
#include "Map.h"
#include "CheckDifficult.h"

class LevelCreation
{
private:
	Map* map;
	CheckDifficult* d;
	int complexity = 0;

	

public:
	LevelCreation(Map* map):
		map{new Map{*map}},
		d { new CheckDifficult{map}}
	{}
	
	bool isOnlyOneSolution(Map* solution, Map* level, int temp_complexity);

	Map* generate(int value);

	int getComplexity();

	~LevelCreation()
	{
		if (this->d != nullptr)
		{
			delete d;
		}
	}
};