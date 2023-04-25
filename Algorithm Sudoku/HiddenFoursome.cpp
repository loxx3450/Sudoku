#include "HiddenFoursome.h"

bool HiddenFoursome::findHiddenFoursomeInField(Field* temp, int count, int* hiddenNumbers)
{
	int* tempHiddenNumbers = new int[Groups::Foursome]{};

	Point* array = new Point[Groups::Foursome]{};

	for (int i{}; i < count - 3; ++i)
	{
		for (int j{ i + 1 }; j < count - 2; ++j)
		{
			for (int g{ j + 1 }; g < count - 1; ++g)
			{
				for (int h{ g + 1 }; h < count; ++h)
				{
					tempHiddenNumbers[0] = hiddenNumbers[i];
					tempHiddenNumbers[1] = hiddenNumbers[j];
					tempHiddenNumbers[2] = hiddenNumbers[g];
					tempHiddenNumbers[3] = hiddenNumbers[h];

					if (this->ifPassRulesForHiddenTriplets(temp, tempHiddenNumbers, array, Groups::Foursome, Groups::Triplet, Groups::Couple))
					{
						if (this->editNotesInField(temp, tempHiddenNumbers, array, Groups::Foursome))
						{
							delete[] tempHiddenNumbers;
							delete[] array;

							return true;
						}
					}


				}
			}
		}
	}

	delete[] tempHiddenNumbers;
	delete[] array;

	return false;
}

bool HiddenFoursome::findHiddenFoursomeInRow(Cell* row, int count, int* hiddenNumbers)
{
	int* tempHiddenNumbers = new int[Groups::Foursome]{};

	int* array = new int[Groups::Foursome]{};

	for (int i{}; i < count - 3; ++i)
	{
		for (int j{ i + 1 }; j < count - 2; ++j)
		{
			for (int g{ j + 1 }; g < count - 1; ++g)
			{
				for (int h{ g + 1 }; h < count; ++h)
				{
					tempHiddenNumbers[0] = hiddenNumbers[i];
					tempHiddenNumbers[1] = hiddenNumbers[j];
					tempHiddenNumbers[2] = hiddenNumbers[g];
					tempHiddenNumbers[3] = hiddenNumbers[h];

					if (this->ifPassRulesForHiddenTriplets(row, tempHiddenNumbers, array, Groups::Foursome, Groups::Triplet, Groups::Couple))
					{
						if (this->editNotesInRow(row, tempHiddenNumbers, array, Groups::Foursome))
						{
							delete[] tempHiddenNumbers;
							delete[] array;

							return true;
						}
					}


				}
			}
		}
	}

	delete[] tempHiddenNumbers;
	delete[] array;

	return false;
}
bool HiddenFoursome::findPossibleHiddenFoursomeInField(Field* temp, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, Groups::Foursome, Groups::Triplet, Groups::Couple);

	if (this->findHiddenFoursomeInField(temp, count, hiddenNumbers))
	{
		delete[] hiddenNumbers;

		return true;
	}

	delete[] hiddenNumbers;

	return false;
}

bool HiddenFoursome::findPossibleHiddenFoursomeInRow(Cell* row, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, Groups::Foursome, Groups::Triplet, Groups::Couple);

	if (this->findHiddenFoursomeInRow(row, count, hiddenNumbers))
	{
		delete[] hiddenNumbers;

		return true;
	}

	delete[] hiddenNumbers;

	return false;
}

bool HiddenFoursome::hiddenFoursomeInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (temp->countOfEmptyCells() < Groups::Foursome)
	{
		return false;
	}

	this->clearNumbers();

	this->overrideNumbersWithFieldNotes(temp);

	int count = this->getCountOfHiddenNumbers(Groups::Foursome, Groups::Triplet, Groups::Couple);

	if (count < Groups::Foursome)
	{
		return false;
	}

	if (this->findPossibleHiddenFoursomeInField(temp, count))
	{
		map->takeField(temp, temp_i * 3, temp_j * 3);

		return true;
	}

	return false;
}

bool HiddenFoursome::hiddenFoursomeInRow(Cell* row)
{
	this->clearNumbers();

	this->overrideNumbersWithRowNotes(row);

	int count = this->getCountOfHiddenNumbers(Groups::Foursome, Groups::Triplet, Groups::Couple);

	if (count < Groups::Foursome)
	{
		return false;
	}

	if (this->findPossibleHiddenFoursomeInRow(row, count))
	{
		return true;
	}

	return false;
}
