#include "LevelCreation.h"

bool LevelCreation::checkFields()
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_count; ++i)
	{
		for (int j{}; j < this->field_count; ++j)
		{
			temp->generate(map->getArr(), i * this->field_count, j * this->field_count);

			if (solution.lastInField(temp))
			{
				this->map->takeField(temp, i * this->field_count, j * this->field_count);

				delete temp;

				return true;
			}
		}
	}

	delete temp;

	return false;
}

bool LevelCreation::checkStrings()
{
	for (int i{}; i < this->map_count; ++i)
	{
		if (solution.lastInRow(this->map->getString(i)))
		{
			return true;
		}
	}

	return false;
}

bool LevelCreation::checkFieldsExceptions()
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_count; ++i)
	{
		for (int j{}; j < this->field_count; ++j)
		{
			temp->generate(this->map->getArr(), i * this->field_count, j * this->field_count);

			if (solution.exceptionInField(this->map->getArr(), temp, i, j))
			{
				delete temp;

				return true;
			}
		}
	}

	delete temp;

	return false;
}

bool LevelCreation::check1()
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
