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

bool HiddenCouple::editNotesInField_HiddenGroups(Field* temp, int* hiddenNumbers, Point* array)
{
	bool flag{ false };

	for (int i{}; i < Groups::Couple; ++i)
	{
		if (temp->getCell(array[i].getX(), array[i].getY())->editNotes(hiddenNumbers, Groups::Couple))
		{
			flag = true;
		}
	}

	return flag;
}

bool HiddenCouple::editNotesInRow_HiddenGroups(Cell* row, int* hiddenNumbers, int* array)
{
	bool flag{ false };

	for (int i{}; i < Groups::Couple; ++i)
	{
		if (row[array[i]].editNotes(hiddenNumbers, Groups::Couple))
		{
			flag = true;
		}
	}

	return flag;
}

bool HiddenCouple::findPossibleHiddenGroupInField(Field* temp, int* hiddenNumbers)
{
	int count{};
	Point* array = new Point[Groups::Couple]{};

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
						if (this->editNotesInField_HiddenGroups(temp, hiddenNumbers, array))
						{
							delete[] array;

							return true;
						}
					}
				}

			}
		}
	}

	delete[] array;

	return false;
}

bool HiddenCouple::findPossibleHiddenGroupInRow(Cell* row, int* hiddenNumbers)
{
	int count{};
	int* array = new int[Groups::Couple]{};

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
					if (this->editNotesInRow_HiddenGroups(row, hiddenNumbers, array))
					{
						delete[] array;

						return true;
					}
				}
			}

		}
	}

	delete[] array;

	return false;
}

bool HiddenCouple::hiddenCouplesInField(Map* map, Field* temp, int temp_i, int temp_j)
{
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

	if (count == Groups::Couple)
	{
		int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(Groups::Couple);

		if (this->findPossibleHiddenGroupInField(temp, hiddenNumbers))
		{
			delete[] hiddenNumbers;

			map->takeField(temp, temp_i * 3, temp_j * 3);

			return true;
		}
	}
	if (count > Groups::Couple)
	{
		int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count);

		int* tempHiddenNumbers = new int[Groups::Couple];

		for (int i{}; i < count - 1; ++i)
		{
			for (int j{ i + 1 }; j < count; ++j)
			{
				tempHiddenNumbers[0] = hiddenNumbers[i];
				tempHiddenNumbers[1] = hiddenNumbers[j];

				if (this->findPossibleHiddenGroupInField(temp, tempHiddenNumbers))
				{
					delete[] hiddenNumbers;
					delete[] tempHiddenNumbers;

					map->takeField(temp, temp_i * 3, temp_j * 3);

					return true;
				}
			}
		}
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

	if (count == Groups::Couple)
	{
		int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(Groups::Couple);

		if (this->findPossibleHiddenGroupInRow(row, hiddenNumbers))
		{
			delete[] hiddenNumbers;

			return true;
		}
	}
	if (count > Groups::Couple)
	{
		int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count);

		for (int i{}, index{}; i < this->map_size; ++i)
		{
			if (this->numbers[i] == Groups::Couple)
			{
				hiddenNumbers[index++] = i + 1;
			}
		}

		int* tempHiddenNumbers = new int[Groups::Couple];

		for (int i{}; i < count - 1; ++i)
		{
			for (int j{ i + 1 }; j < count; ++j)
			{
				tempHiddenNumbers[0] = hiddenNumbers[i];
				tempHiddenNumbers[1] = hiddenNumbers[j];

				if (this->findPossibleHiddenGroupInRow(row, tempHiddenNumbers))
				{
					delete[] hiddenNumbers;
					delete[] tempHiddenNumbers;

					return true;
				}
			}
		}
	}

	return false;
}
