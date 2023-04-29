#include "CheckDifficult.h"

bool CheckDifficult::methodForField(Solution* obj, bool (Solution::* func)(Map*, Field*, int, int))
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			temp->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			if ((obj->*func)(this->map, temp, i, j))
			{
				delete temp;

				return true;
			}
		}
	}

	delete temp;

	return false;
}

bool CheckDifficult::methodForString(Solution* obj, bool (Solution::* func)(Cell*))
{
	for (int i{}; i < this->map_size; ++i)
	{
		if ((obj->*func)(this->map->getString(i)))
		{
			return true;
		}
	}

	return false;
}

bool CheckDifficult::methodForColumn(Solution* obj, bool (Solution::* func)(Cell*))
{
	Cell* tempRow = nullptr;

	for (int i{}; i < this->map_size; ++i)
	{
		tempRow = map->getColumn(i);

		if ((obj->*func)(tempRow))
		{
			map->setColumn(tempRow, i);

			delete[] tempRow;

			return true;
		}

		delete[] tempRow;
	}

	return false;
}

bool CheckDifficult::checkFields()
{
	if (this->methodForField(this->solution, &Solution::lastInField))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkStrings()
{
	if (this->methodForString(this->solution, &Solution::lastInRow))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkColumns()
{
	if (this->methodForColumn(this->solution, &Solution::lastInRow))
	{
		return true;
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

			if (solution->exceptionInField(this->map->getArr(), temp, i, j))
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
		if (solution->exceptionInString(this->map->getArr(), this->map->getString(i), i))
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

		if (solution->exceptionInColumn(this->map->getArr(), temp_arr, i))
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
	if (this->methodForField(this->solution, &Solution::lastNumberInStr_Col_Field))
	{
		return true;
	}

	return false;
}

void CheckDifficult::extremeMethodForNotes()
{
	while (true)
	{
		if (this->checkNakedCouples() || this->checkNakedTriplets() || this->checkNakedFoursome())
		{
			continue;
		}

		break;
	}
}

void CheckDifficult::insaneMethodForNotes()
{
	while (true)
	{
		if (this->checkNakedCouples() || this->checkNakedTriplets() || this->checkNakedFoursome())
		{
			continue;
		}
		if (this->checkHiddenCouples() || this->checkHiddenTriplets() || this->checkHiddenFoursome())
		{
			continue;
		}
		if (this->checkPointingGroup(Groups::Couple) || this->checkPointingGroup(Groups::Triplet))
		{
			continue;
		}

		break;
	}
}

void CheckDifficult::makeNotes()
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			temp->generate(this->map->getArr(), i * this->field_size, j * this->field_size);

			solution->makeNotes(this->map, temp, i, j);
		}
	}

	delete temp;
}

bool CheckDifficult::checkNakedCouples()
{
	if (this->methodForField(this->solution, &Solution::nakedCouplesInField))
	{
		return true;
	}

	if (this->methodForString(this->solution, &Solution::nakedCouplesInRow))
	{
		return true;
	}

	if (this->methodForColumn(this->solution, &Solution::nakedCouplesInRow))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkNakedTriplets()
{
	if (this->methodForField(this->solution, &Solution::nakedTripletsInField))
	{
		return true;
	}

	if (this->methodForString(this->solution, &Solution::nakedTripletsInRow))
	{
		return true;
	}

	if (this->methodForColumn(this->solution, &Solution::nakedTripletsInRow))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkNakedFoursome()
{
	if (this->methodForField(this->solution, &Solution::nakedFoursomeInField))
	{
		return true;
	}

	if (this->methodForString(this->solution, &Solution::nakedFoursomeInRow))
	{
		return true;
	}

	if (this->methodForColumn(this->solution, &Solution::nakedFoursomeInRow))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::isOnlyOneNote()
{
	if (solution->onlyOneNote(this->map))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkHiddenCouples()
{
	if (this->methodForField(this->solution, &Solution::hiddenCouplesInField))
	{
		return true;
	}

	if (this->methodForString(this->solution, &Solution::hiddenCouplesInRow))
	{
		return true;
	}

	if (this->methodForColumn(this->solution, &Solution::hiddenCouplesInRow))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkHiddenTriplets()
{
	if (this->methodForField(this->solution, &Solution::hiddenTripletsInField))
	{
		return true;
	}

	if (this->methodForString(this->solution, &Solution::hiddenTripletsInRow))
	{
		return true;
	}

	if (this->methodForColumn(this->solution, &Solution::hiddenTripletsInRow))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkHiddenFoursome()
{
	if (this->methodForField(this->solution, &Solution::hiddenFoursomeInField))
	{
		return true;
	}

	if (this->methodForString(this->solution, &Solution::hiddenFoursomeInRow))
	{
		return true;
	}

	if (this->methodForColumn(this->solution, &Solution::hiddenFoursomeInRow))
	{
		return true;
	}

	return false;
}

bool CheckDifficult::checkPointingGroup(int size)
{
	Field* temp = new Field{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			temp->generate(map->getArr(), i * this->field_size, j * this->field_size);

			if (solution->pointingGroupInField(map, temp, i, j, size))
			{
				delete temp;

				return true;
			}
		}
	}

	delete temp;

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (solution->pointingGroupInString(this->map, this->map->getString(i * 3 + j), i, j, size))
			{
				return true;
			}
		}
	}

	Cell* column = nullptr;

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			column = this->map->getColumn(i * 3 + j);

			if (solution->pointingGroupInColumn(this->map, column, i, j, size))
			{
				this->map->setColumn(column, i * 3 + j);

				delete[] column;

				return true;
			}

			delete[] column;
		}
	}

	return false;
}

bool CheckDifficult::hiddenNote()
{
	if (solution->hiddenNote(this->map))
	{
		return true;
	}

	return false;
}



bool CheckDifficult::checkEasy()
{
	if (this->checkFields() || this->checkStrings() || this->checkColumns())
	{
		return true;
	}
	if (this->checkExceptInField())
	{
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
	if (this->checkExceptInString() || this->checkExceptInColumn())
	{
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

	this->extremeMethodForNotes();

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

bool CheckDifficult::checkInsane()
{
	if (this->checkHard())
	{
		return true;
	}

	this->makeNotes();

	this->insaneMethodForNotes();

	if (this->isOnlyOneNote())
	{
		//std::cout << "OnlyOneNote\n";
		if (this->complexity < 4)
		{
			this->complexity = 4;
		}
		return true;
	}
	if (this->hiddenNote())
	{
		//std::cout << "HiddenNote\n";
		if (this->complexity < 4)
		{
			this->complexity = 4;
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
			case 4:
				if (!this->checkInsane())
				{
					return false;
				}
		}
	}

	return true;
}

int CheckDifficult::getComplexity()
{
	return this->complexity;
}
