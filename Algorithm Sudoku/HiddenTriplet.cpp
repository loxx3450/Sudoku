#include "HiddenTriplet.h"

bool HiddenTriplet::findHiddenTripletInRow(Cell* row, int count, int* hiddenNumbers)
{
	int* tempHiddenNumbers = new int[Groups::Triplet]{};

	int* array = new int[Groups::Triplet]{};

	for (int i{}; i < count - 2; ++i)
	{
		for (int j{ i + 1 }; j < count - 1; ++j)
		{
			for (int g{ j + 1 }; g < count; ++g)
			{
				tempHiddenNumbers[0] = hiddenNumbers[i];
				tempHiddenNumbers[1] = hiddenNumbers[j];
				tempHiddenNumbers[2] = hiddenNumbers[g];

				if (this->ifPassRulesForHiddenTriplets(row, tempHiddenNumbers, array, Groups::Triplet, Groups::Couple))
				{
					if (this->editNotesInRow(row, tempHiddenNumbers, array, Groups::Triplet))
					{
						delete[] tempHiddenNumbers;
						delete[] array;

						return true;
					}
				}
			}
		}
	}

	delete[] tempHiddenNumbers;
	delete[] array;

	return false;
}

bool HiddenTriplet::findHiddenTripletInField(Field* temp, int count, int* hiddenNumbers)
{
	int* tempHiddenNumbers = new int[Groups::Triplet]{};

	Point* array = new Point[Groups::Triplet]{};

	for (int i{}; i < count - 2; ++i)
	{
		for (int j{ i + 1 }; j < count - 1; ++j)
		{
			for (int g{ j + 1 }; g < count; ++g)
			{
				tempHiddenNumbers[0] = hiddenNumbers[i];
				tempHiddenNumbers[1] = hiddenNumbers[j];
				tempHiddenNumbers[2] = hiddenNumbers[g];

				if (this->ifPassRulesForHiddenTriplets(temp, tempHiddenNumbers, array, Groups::Triplet, Groups::Couple))
				{
					if (this->editNotesInField(temp, tempHiddenNumbers, array, Groups::Triplet))
					{
						delete[] tempHiddenNumbers;
						delete[] array;

						return true;
					}
				}
			}
		}
	}

	delete[] tempHiddenNumbers;
	delete[] array;

	return false;
}

bool HiddenTriplet::findPossibleHiddenTripletInRow(Cell* row, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, Groups::Triplet, Groups::Couple);

	if (this->findHiddenTripletInRow(row, count, hiddenNumbers))
	{
		delete[] hiddenNumbers;

		return true;
	}

	delete[] hiddenNumbers;

	return false;
}

bool HiddenTriplet::findPossibleHiddenTripletInField(Field* temp, int count)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, Groups::Triplet, Groups::Couple);

	if (this->findHiddenTripletInField(temp, count, hiddenNumbers))
	{
		delete[] hiddenNumbers;

		return true;
	}

	delete[] hiddenNumbers;

	return false;
}

bool HiddenTriplet::hiddenTripletsInField(Map* map, Field* temp, int temp_i, int temp_j)
{
	if (temp->countOfEmptyCells() < Groups::Triplet)
	{
		return false;
	}

	this->clearNumbers();

	this->overrideNumbersWithFieldNotes(temp);

	int count = this->getCountOfHiddenNumbers(Groups::Triplet, Groups::Couple);

	if (count < Groups::Triplet)
	{
		return false;
	}

	if (this->findPossibleHiddenTripletInField(temp, count))
	{
		map->takeField(temp, temp_i * 3, temp_j * 3);

		return true;
	}

	return false;
}

bool HiddenTriplet::hiddenTripletsInRow(Cell* row)
{
	this->clearNumbers();

	this->overrideNumbersWithRowNotes(row);

	int count = this->getCountOfHiddenNumbers(Groups::Triplet, Groups::Couple);

	if (count < Groups::Triplet)
	{
		return false;
	}

	if (this->findPossibleHiddenTripletInRow(row, count))
	{
		return true;
	}

	return false;
}
