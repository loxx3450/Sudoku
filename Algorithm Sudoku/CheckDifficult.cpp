#include "CheckDifficult.h"

bool CheckDifficult::checkFields()
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

bool CheckDifficult::checkStrings()
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

bool CheckDifficult::checkColumns()
{
	Cell* tmp;

	for (int i{}; i < this->map_size; ++i)
	{
		tmp = this->map->getColumn(i);

		if (solution.lastInRow(tmp))
		{
			this->map->setColumn(tmp, i);

			delete[] tmp;

			return true;
		}

		delete[] tmp;
	}

	return false;
}

bool CheckDifficult::checkExceptInField()
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

bool CheckDifficult::checkExceptInString()
{
	for (int i{}; i < this->map_size; ++i)
	{
		if (solution.exceptionInString(this->map->getArr(), this->map->getString(i), i))
		{
			return true;
		}
	}


	return false;
}

bool CheckDifficult::checkExceptInColumn()
{
	Cell* temp_arr;

	for (int i{}; i < this->map_size; ++i)
	{
		temp_arr = this->map->getColumn(i);

		if (solution.exceptionInColumn(this->map->getArr(), temp_arr, i))
		{
			this->map->setColumn(temp_arr, i);

			delete[] temp_arr;		

			return true;
		}

		delete[] temp_arr;
	}

	return false;
}

bool CheckDifficult::checkExceptInStr_Col_Field()
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

void CheckDifficult::makeNotes()
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			temp->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			solution.makeNotes(this->map, temp, i, j);
		}
	}

	delete temp;
}

void CheckDifficult::checkNakedCouples()
{
	Field* tempField = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			tempField->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			solution.nakedCouplesInField(map, tempField, i, j);
		}
	}

	delete tempField;

	for (int i{}; i < this->map_size; ++i)
	{
		solution.nakedCouplesInRow(map->getString(i));
	}

	Cell* tempRow = nullptr;

	for (int i{}; i < this->map_size; ++i)
	{
		tempRow = map->getColumn(i);

		solution.nakedCouplesInRow(tempRow);

		map->setColumn(tempRow, i);

		delete[] tempRow;
	}
}

void CheckDifficult::checkNakedTriplets()
{
	Field* tempField = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			tempField->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			solution.nakedTripletsInField(map, tempField, i, j);
		}
	}

	//delete tempField;

	for (int i{}; i < this->map_size; ++i)
	{
		solution.nakedTripletsInRow(map->getString(i));
	}

	/*Cell* tempRow = nullptr;

	for (int i{}; i < this->map_size; ++i)
	{
		tempRow = map->getColumn(i);

		solution.nakedTripletsInRow(tempRow);

		map->setColumn(tempRow, i);
	}*/

	//delete[] tempRow;

	//delete tempField;
}

bool CheckDifficult::isOnlyOneNote()
{
	if (solution.onlyOneNote(this->map))
	{
		return true;
	}

	return false;
}



bool CheckDifficult::check()
{
	if (this->checkFields())
	{
		std::cout << "LastInField\n";
		return true;
	}
	if (this->checkStrings())
	{
		std::cout << "LastInString\n";
		return true;
	}
	if (this->checkColumns())
	{
		std::cout << "LastInColumn\n";
		return true;
	}
	if (this->checkExceptInField())
	{
		std::cout << "ExceptionInField\n";
		return true;
	}
	if (this->checkExceptInString())
	{
		std::cout << "ExceptionInString\n";
		if (this->complexity < 1)
		{
			this->complexity = 1;
		}
		return true;
	}
	if (this->checkExceptInColumn())
	{
		std::cout << "ExceptionInColumn\n";
		if (this->complexity < 1)
		{
			this->complexity = 1;
		}
		return true;
	}
	if (this->checkExceptInStr_Col_Field())
	{
		std::cout << "LastNumberInString_Column_Field\n";
		if (this->complexity < 2)
		{
			this->complexity = 2;
		}
		return true;
	}
	this->makeNotes();
	std::cout << "MakeNotes!\n";
	this->checkNakedCouples();
	std::cout << "NakedCouples\n";
	this->map->showNotes();
	//this->checkNakedTriplets();
	if (this->isOnlyOneNote())
	{
		std::cout << "OnlyOneNote\n";
		map->show();
		return true;
	}

	//this->map->showNotes();

	return false;
}

bool CheckDifficult::checkComplexity()
{
	this->complexity = 0;

	while (!this->map->isMade())
	{
		if (!this->check())
		{
			return false;
		}
	}

	return true;
}

int CheckDifficult::getComplexity()
{
	return this->complexity;
}
