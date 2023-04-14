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

	while (true)
	{
		if (this->checkNakedCouples())
		{
			continue;
		}
		if (this->checkNakedTriplets())
		{
			continue;
		}

		break;
	}
}

bool CheckDifficult::checkNakedCouples()
{
	Field* tempField = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			tempField->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			if (solution.nakedCouplesInField(map, tempField, i, j))
			{
				delete tempField;

				return true;
			}
		}
	}

	delete tempField;

	for (int i{}; i < this->map_size; ++i)
	{
		if (solution.nakedCouplesInRow(map->getString(i)))
		{
			return true;
		}
	}

	Cell* tempRow = nullptr;

	for (int i{}; i < this->map_size; ++i)
	{
		tempRow = map->getColumn(i);

		if (solution.nakedCouplesInRow(tempRow))
		{
			map->setColumn(tempRow, i);

			delete[] tempRow;

			return true;
		}

		delete[] tempRow;
	}

	return false;
}

bool CheckDifficult::checkNakedTriplets()
{
	Field* tempField = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			tempField->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			if (solution.nakedTripletsInField(map, tempField, i, j))
			{
				delete tempField;

				return true;
			}
		}
	}

	delete tempField;

	for (int i{}; i < this->map_size; ++i)
	{
		if (solution.nakedTripletsInRow(map->getString(i)))
		{
			return true;
		}
	}

	Cell* tempRow = nullptr;

	for (int i{}; i < this->map_size; ++i)
	{
		tempRow = map->getColumn(i);

		if (solution.nakedTripletsInRow(tempRow))
		{
			map->setColumn(tempRow, i);

			delete[] tempRow;

			return true;
		}

		delete[] tempRow;
	}

	return false;
}

bool CheckDifficult::isOnlyOneNote()
{
	if (solution.onlyOneNote(this->map))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::hiddenNote()
{
	if (solution.hiddenNote(this->map))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkEasy()
{
	if (this->checkFields())
	{
		//std::cout << "LastInField\n";
		return true;
	}
	if (this->checkStrings())
	{
		//std::cout << "LastInString\n";
		return true;
	}
	if (this->checkColumns())
	{
		//std::cout << "LastInColumn\n";
		return true;
	}
	if (this->checkExceptInField())
	{
		//std::cout << "ExceptionInField\n";
		return true;
	}

	return false;
}

bool CheckDifficult::checkMedium()
{
	if (this->checkEasy())
	{
		return true;
	}
	if (this->checkExceptInString())
	{
		//std::cout << "ExceptionInString\n";
		if (this->complexity < 1)
		{
			this->complexity = 1;
		}
		return true;
	}
	if (this->checkExceptInColumn())
	{
		//std::cout << "ExceptionInColumn\n";
		if (this->complexity < 1)
		{
			this->complexity = 1;
		}
		return true;
	}

	return false;
}

bool CheckDifficult::checkHard()
{
	if (this->checkMedium())
	{
		return true;
	}
	if (this->checkExceptInStr_Col_Field())
	{
		//std::cout << "LastNumberInString_Column_Field\n";
		if (this->complexity < 2)
		{
			this->complexity = 2;
		}
		return true;
	}

	return false;
}

bool CheckDifficult::checkExtreme()
{
	if (this->checkHard())
	{
		return true;
	}
	this->makeNotes();
	//this->map->show();
	if (this->isOnlyOneNote())
	{
		//std::cout << "OnlyOneNote\n";
		if (this->complexity < 3)
		{
			this->complexity = 3;
		}
		return true;
	}
	if (this->hiddenNote())
	{
		//std::cout << "HiddenNote\n";
		if (this->complexity < 3)
		{
			this->complexity = 3;
		}
		return true;
	}

	return false;
}


bool CheckDifficult::checkComplexity(int complexity)
{
	this->complexity = 0;

	while (!this->map->isMade())
	{
		switch (complexity)
		{
			case 0:
				if (!this->checkEasy())
				{
					return false;
				}
				break;
			case 1:
				if (!this->checkMedium())
				{
					return false;
				}
				break;
			case 2:
				if (!this->checkHard())
				{
					return false;
				}
				break;
			case 3:
				if (!this->checkExtreme())
				{
					return false;
				}
				break;
		}
	}

	return true;
}

int CheckDifficult::getComplexity()
{
	return this->complexity;
}
