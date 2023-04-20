#include "HiddenCouple.h"

int* HiddenCouple::fillHiddenNumbersWithNumbers(int size)
{
	int* hiddenNumbers = new int[size] {};

	for (int i{}, index{}; i < this->map_size; ++i)
	{
		if (this->numbers[i] == Groups::Couple)
		{
			hiddenNumbers[index++] = i + 1;
		}
	}

	return hiddenNumbers;
}

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

bool HiddenCouple::findPossibleHiddenGroupInField(Field* temp, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count);

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

bool HiddenCouple::findPossibleHiddenGroupInRow(Cell* row, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count);

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

	if (this->findPossibleHiddenGroupInField(temp, count))
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
	
	if (this->findPossibleHiddenGroupInRow(row, count))
	{
		return true;
	}

	return false;
}
