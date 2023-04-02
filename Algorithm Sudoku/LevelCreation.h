#pragma once
#include "Map.h"
#include "CheckDifficult.h"


class LevelCreation
{
private:
	Map* made_map;
	Map* map;
	CheckDifficult* d;
	int complexity = 0;

public:
	LevelCreation(Map* made_map):
		made_map{new Map{*made_map}},
		map{new Map{}},
		d { new CheckDifficult{map}}
	{}

	Map* generate(int value);

	int getComplexity();

	~LevelCreation()
	{
		if (this->made_map != nullptr)
		{
			delete made_map;
		}
		if (this->d != nullptr)
		{
			delete d;
		}
	}
};