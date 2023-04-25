#include "HiddenCouple.h"

bool HiddenCouple::ifPassRulesForHiddenCouples(Field* temp, int* hiddenNumbers, Point* array)
{
	int count{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			for (int index{}; index < Groups::Couple; ++index)
			{
				if (!temp->getCell(i, j)->inNotes(hiddenNumbers[index]))
				{
					break;
				}

				if (index == Groups::Couple - 1)
				{
					array[count].set(i, j);

					++count;

					if (count == Groups::Couple)
					{
						return true;
					}
				}

			}
		}
	}

	return false;
}

bool HiddenCouple::ifPassRulesForHiddenCouples(Cell* row, int* hiddenNumbers, int* array)
{
	int count{};

	for (int i{}; i < this->map_size; ++i)
	{
		for (int index{}; index < Groups::Couple; ++index)
		{
			if (!row[i].inNotes(hiddenNumbers[index]))
			{
				break;
			}

			if (index == Groups::Couple - 1)
			{
				array[count] = i;

				++count;

				if (count == Groups::Couple)
				{
					return true;
				}
			}

		}
	}

	return false;
}

bool HiddenCouple::findPossibleHiddenCoupleInField(Field* temp, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, Groups::Couple);

	int* tempHiddenNumbers = new int[Groups::Couple];

	Point* array = new Point[Groups::Couple]{};

	for (int i{}; i < count - 1; ++i)
	{
		for (int j{ i + 1 }; j < count; ++j)
		{
			tempHiddenNumbers[0] = hiddenNumbers[i];
			tempHiddenNumbers[1] = hiddenNumbers[j];

			if (this->ifPassRulesForHiddenCouples(temp, tempHiddenNumbers, array))
			{
				if (this->editNotesInField(temp, tempHiddenNumbers, array, Groups::Couple))
				{
					delete[] array;
					delete[] hiddenNumbers;
					delete[] tempHiddenNumbers;

					return true;
				}
			}
		}
	}

	delete[] array;
	delete[] hiddenNumbers;
	delete[] tempHiddenNumbers;

	return false;
}

bool HiddenCouple::findPossibleHiddenCoupleInRow(Cell* row, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, Groups::Couple);

	int* tempHiddenNumbers = new int[Groups::Couple];

	int* array = new int[Groups::Couple]{};

	for (int i{}; i < count - 1; ++i)
	{
		for (int j{ i + 1 }; j < count; ++j)
		{
			tempHiddenNumbers[0] = hiddenNumbers[i];
			tempHiddenNumbers[1] = hiddenNumbers[j];

			if (this->ifPassRulesForHiddenCouples(row, tempHiddenNumbers, array))
			{
				if (this->editNotesInRow(row, tempHiddenNumbers, array, Groups::Couple))
				{
					delete[] array;
					delete[] hiddenNumbers;
					delete[] tempHiddenNumbers;

					return true;
				}
			}
		}
	}

	delete[] array;
	delete[] hiddenNumbers;
	delete[] tempHiddenNumbers;

	return false;
}

bool HiddenCouple::hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (temp->countOfEmptyCells() < Groups::Couple)
	{
		return false;
	}

	this->clearNumbers();
	this->overrideNumbersWithFieldNotes(temp);

	int count{};

	for (int i{}; i < this->map_size; ++i)
	{
		if (this->numbers[i] == Groups::Couple)
		{
			++count;
		}
	}

	if (count < Groups::Couple)
	{
		return false;
	}

	if (this->findPossibleHiddenCoupleInField(temp, count))
	{
		map->takeField(temp, temp_i * 3, temp_j * 3);

		return true;
	}

	return false;
}

bool HiddenCouple::hiddenCouplesInRow(Cell* row)
{
	this->clearNumbers();
	this->overrideNumbersWithRowNotes(row);

	int count = this->getCountOfHiddenNumbers(Groups::Couple);

	if (count < Groups::Couple)
	{
		return false;
	}
	
	if (this->findPossibleHiddenCoupleInRow(row, count))
	{
		return true;
	}

	return false;
}
