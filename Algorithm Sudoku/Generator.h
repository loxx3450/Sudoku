#pragma once
#include "Map.h"

class Generator
{
public:
	void generation(Map* map)
	{
		int temp = 0, index1 = 0, index2 = 0, multiply = 0;

		for (int i{}; i < 1000; ++i)
		{
			temp = rand() % 7 + 1;

			switch (temp)
			{
				case 1:
					map->changeStrToCol();
					break;
				case 2:
					map->arrMirror();
					break;
				case 3:
					map->upsideDown();
					break;
				case 4:
					multiply = rand() % 2 + 1;
					map->changeFieldStr(0, multiply);
					break;
				case 5:
					multiply = rand() % 2 + 1;
					map->changeFieldCol(0, multiply);
					break;
				case 6:
					index1 = rand() % 8 + 0;
					index2 = rand() % 8 + 0;
					map->swapStrings(index1, index2);
					break;
				case 7:
					index1 = rand() % 8 + 0;
					index2 = rand() % 8 + 0;
					map->swapColumns(index1, index2);
					break;
			}


		}
		
	}


};