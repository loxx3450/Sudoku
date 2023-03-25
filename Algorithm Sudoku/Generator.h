#pragma once
#include "Map.h"

class Generator
{
public:
	void generation(Map* map)
	{
		int temp = 0, index1 = 0, index2 = 0, multiply = 0, part = 0;

		map->changeStrToCol();
		map->arrMirror();
		map->upsideDown();

		for (int i{}; i < 100000; ++i)
		{
			temp = rand() % 4 + 1;

			switch (temp)
			{
				
				case 1:
					multiply = rand() % 2 + 1;
					map->changeFieldStr(0, multiply);
					break;
				case 2:
					multiply = rand() % 2 + 1;
					map->changeFieldCol(0, multiply);
					break;
				case 3:
					part = rand() % 3 + 1;
					index1 = rand() % 3 + 3 * (part - 1);
					index2 = rand() % 3 + 3 * (part - 1);
					map->swapStrings(index1, index2);
					break;
				case 4:
					part = rand() % 3 + 1;
					index1 = rand() % 3 + 3 * (part - 1);
					index2 = rand() % 3 + 3 * (part - 1);
					map->swapColumns(index1, index2);
					break;
			}


		}
		
	}


};