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