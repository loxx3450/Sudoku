#include "LevelCreation.h"

Map* LevelCreation::generate(int value)
{
	this->made_map->generate();			//I need it?

	this->map->setArr(this->made_map->getArr());

	int count = rand() % 6 + 25;

	int x{}, y{}, old_value{}, size{ 81 }, attempts{};

	Map* temp = new Map{ map->getArr() };

	while (true)
	{
		if (attempts == 10 || size == 22)
		{
			delete temp;

			return this->generate(value);
		}

		map->setArr(temp->getArr());

		do
		{
			x = rand() % 9 + 0;
			y = rand() % 9 + 0;
		} while (map->getNum(x, y) == 0);

		old_value = map->getNum(x, y);

		map->setNum(0, x, y);

		if (!d->checkComplexity())
		{
			map->setNum(old_value, x, y);

			++attempts;

			continue;
		}

		attempts = 0;

		temp->setNum(0, x, y);

		this->complexity = d->getComplexity();

		--size;

		if (this->complexity == value && size <= count)
		{
			return temp;
		}
	}


	delete temp;

	return nullptr;
}

int LevelCreation::getComplexity()
{
	return this->complexity;
}