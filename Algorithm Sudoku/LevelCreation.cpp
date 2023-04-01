#include "LevelCreation.h"

bool LevelCreation::checkFields()
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			temp->generate(map->getArr(), i * this->field_size, j * this->field_size);

			if (solution.lastInField(temp))
			{
				this->map->takeField(temp, i * this->field_size, j * this->field_size);

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
	for (int i{}; i < this->map_size; ++i)
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

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			temp->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

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

bool LevelCreation::checkExceptInString()
{
	Field* temp = new Field{};

	for (int i{}; i < this->map_size; ++i)
	{
		if (solution.exceptionInString(this->map->getArr(), this->map->getString(i), i))
		{
			delete temp;

			return true;
		}
	}

	delete temp;

	return false;
}

bool LevelCreation::checkExceptInColumn()
{
	Field* temp_field = new Field{};

	int* temp_arr;

	for (int i{}; i < this->map_size; ++i)
	{
		temp_arr = this->map->getColumn(i);

		if (solution.exceptionInColumn(this->map->getArr(), temp_arr, i))
		{
			this->map->setColumn(temp_arr, i);

			delete temp_field;

			//delete[] temp_arr;		//!!!!!!!!!!!!!

			return true;
		}
	}

	delete temp_field;

	return false;
}

bool LevelCreation::checkExceptInStr_Col_Field()
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			temp->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			if (solution.lastNumberInStr_Col_Field(this->map, temp, i, j))
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
	if (checkExceptInString())
	{
		std::cout << "ExceptionInString\n";
		return true;
	}
	if (checkExceptInColumn())
	{
		std::cout << "ExceptionInColumn\n";
		return true;
	}
	if (checkExceptInStr_Col_Field())
	{
		std::cout << "LastNumberInString_Column_Field\n";
		return true;
	}

	return false;
}
