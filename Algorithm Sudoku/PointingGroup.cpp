#include "PointingGroup.h"

bool PointingGroup::isNewPoint(int* array, int size, int i)
{
	for (int index{}; index < size; ++index)
	{
		if (array[index] == i)
		{
			return false;
		}
	}

	return true;
}

bool PointingGroup::findPossiblePointingGroupInField(Field* temp, int value, Point* array, int size)
{
	int index{};

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (temp->getCell(i, j)->inNotes(value))
			{
				array[index++].set(i, j);

				if (index == size)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool PointingGroup::findPossiblePointingGroupInRow(Cell* row, int value, int* array, int size)
{
	int index{};

	for (int i{}; i < this->map_size; ++i)
	{
		if (row[i].inNotes(value))
		{
			array[index++] = i;

			if (index == size)
			{
				return true;
			}
		}
	}

	return false;
}

bool PointingGroup::ifPassRulesForPointingGroupInField_String(Point* array, int size)
{
	Point temp{};

	for (int i{}; i < size; ++i)
	{
		temp = array[i];

		if (temp.getX() != array[i + 1].getX() && i + 1 != size)
		{
			return false;
		}
	}

	return true;
}

bool PointingGroup::ifPassRulesForPointingGroupInField_Column(Point* array, int size)
{
	Point temp{};

	for (int i{}; i < size; ++i)
	{
		temp = array[i];

		if (temp.getY() != array[i + 1].getY() && i + 1 != size)
		{
			return false;
		}
	}

	return true;
}

bool PointingGroup::ifPassRulesForPointingGroupInRow(int* array, int size)
{
	int temp{};

	for (int i{}; i < size; ++i)
	{
		temp = (int)(array[i] / 3);

		if (temp != (int)(array[i + 1] / 3) && i + 1 != size)
		{
			return false;
		}
	}

	return true;
}

bool PointingGroup::editString(Map* map, Point* array, int value, int temp_i, int temp_j, int size)
{
	bool flag{ false };

	int temp{};

	int* temp_array = new int[size] {};

	for (int i{}; i < size; ++i)
	{
		temp_array[i] = array[i].getY() + temp_j * 3;
	}

	Cell* string = map->getString(temp_i * 3 + array[0].getX());

	for (int i{}; i < this->map_size; ++i)
	{
		if (string[i].getNum() == 0 && this->isNewPoint(temp_array, size, i))
		{
			temp = string[i].countOfNotes();

			string[i].removeNote(value);

			if (temp > string[i].countOfNotes())
			{
				flag = true;
			}
		}
	}

	delete[] temp_array;

	return flag;
}

bool PointingGroup::editColumn(Map* map, Point* array, int value, int temp_i, int temp_j, int size)
{
	bool flag{ false };

	int temp{};

	int* temp_array = new int[size] {};

	for (int i{}; i < size; ++i)
	{
		temp_array[i] = array[i].getX() + temp_i * 3;
	}

	Cell* column = map->getColumn(temp_j * 3 + array[0].getY());

	for (int i{}; i < this->map_size; ++i)
	{
		if (column[i].getNum() == 0 && this->isNewPoint(temp_array, size, i))
		{
			temp = column[i].countOfNotes();

			column[i].removeNote(value);

			if (temp > column[i].countOfNotes())
			{
				flag = true;
			}
		}
	}

	map->setColumn(column, temp_j * 3 + array[0].getY());

	delete[] column;

	return flag;
}

bool PointingGroup::editFieldForString(Map* map, int* array, int value, int temp_i, int string_i)
{
	bool flag{ false };

	int temp_index{ (int)(array[0] / 3) };

	Field* temp = new Field{};

	int temp_count{};

	temp->generate(map->getArr(), temp_i * 3, temp_index * 3);

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (i == string_i)
			{
				continue;
			}

			if (temp->getCell(i, j)->getNum() == 0 && temp->getCell(i, j)->inNotes(value))
			{
				temp_count = temp->countOfCellNotes(i, j);

				temp->removeCellNote(value, i, j);

				if (temp_count > temp->countOfCellNotes(i, j))
				{
					flag = true;
				}
			}
		}
	}

	map->takeField(temp, temp_i * 3, temp_index * 3);

	delete temp;

	return flag;
}

bool PointingGroup::editFieldForColumn(Map* map, int* array, int value, int temp_j, int column_j)
{
	bool flag{ false };

	int temp_index{ (int)(array[0] / 3) };

	Field* temp = new Field{};

	int temp_count{};

	temp->generate(map->getArr(), temp_index * 3, temp_j * 3);

	for (int i{}; i < this->field_size; ++i)
	{
		for (int j{}; j < this->field_size; ++j)
		{
			if (j == column_j)
			{
				continue;
			}

			if (temp->getCell(i, j)->getNum() == 0 && temp->getCell(i, j)->inNotes(value))
			{
				temp_count = temp->countOfCellNotes(i, j);

				temp->removeCellNote(value, i, j);

				if (temp_count > temp->countOfCellNotes(i, j))
				{
					flag = true;
				}
			}
		}
	}

	map->takeField(temp, temp_index * 3, temp_j * 3);

	delete temp;

	return flag;
}

bool PointingGroup::findPointingGroupInField(Map* map, Field* temp, int count, int temp_i, int temp_j, int size)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, size, size, size);
	Point* array = new Point[size]{};

	for (int i{}; i < count; ++i)
	{
		if (this->findPossiblePointingGroupInField(temp, hiddenNumbers[i], array, size))
		{
			if (this->ifPassRulesForPointingGroupInField_String(array, size))
			{
				if (this->editString(map, array, hiddenNumbers[i], temp_i, temp_j, size))
				{
					delete[] hiddenNumbers;
					delete[] array;

					return true;
				}
			}
			if (this->ifPassRulesForPointingGroupInField_Column(array, size))
			{
				if (this->editColumn(map, array, hiddenNumbers[i], temp_i, temp_j, size))
				{
					delete[] hiddenNumbers;
					delete[] array;

					return true;
				}
			}
		}
	}

	delete[] hiddenNumbers;
	delete[] array;

	return false;
}

bool PointingGroup::findPointingGroupInString(Map* map, Cell* row, int count, int temp_i, int string_i, int size)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, size, size, size);
	int* array = new int[size] {};

	for (int i{}; i < count; ++i)
	{
		if (this->findPossiblePointingGroupInRow(row, hiddenNumbers[i], array, size))
		{
			if (this->ifPassRulesForPointingGroupInRow(array, size))
			{
				if (this->editFieldForString(map, array, hiddenNumbers[i], temp_i, string_i))
				{
					delete[] hiddenNumbers;
					delete[] array;

					return true;
				}
			}
		}
	}

	delete[] hiddenNumbers;
	delete[] array;

	return false;
}

bool PointingGroup::findPointingGroupInColumn(Map* map, Cell* row, int count, int temp_j, int column_j, int size)
{
	int* hiddenNumbers = this->fillHiddenNumbersWithNumbers(count, size, size, size);
	int* array = new int[size] {};

	for (int i{}; i < count; ++i)
	{
		if (this->findPossiblePointingGroupInRow(row, hiddenNumbers[i], array, size))
		{
			if (this->ifPassRulesForPointingGroupInRow(array, size))
			{
				if (this->editFieldForColumn(map, array, hiddenNumbers[i], temp_j, column_j))
				{
					delete[] hiddenNumbers;
					delete[] array;

					return true;
				}
			}
		}
	}

	delete[] hiddenNumbers;
	delete[] array;

	return false;
}

bool PointingGroup::PointingGroupInField(Map* map, Field* temp, int temp_i, int temp_j, int size)
{
	if (temp->countOfEmptyCells() < size)
	{
		return false;
	}

	this->clearNumbers();
	this->overrideNumbersWithFieldNotes(temp);

	int count = this->getCountOfHiddenNumbers(size, size, size);

	if (count == 0)
	{
		return false;
	}

	if (this->findPointingGroupInField(map, temp, count, temp_i, temp_j, size))
	{
		return true;
	}

	return false;
}

bool PointingGroup::PointingGroupInString(Map* map, Cell* row, int temp_i, int string_i, int size)
{
	this->clearNumbers();
	this->overrideNumbersWithRowNotes(row);

	int count = this->getCountOfHiddenNumbers(size, size, size);

	if (count == 0)
	{
		return false;
	}

	if (this->findPointingGroupInString(map, row, count, temp_i, string_i, size))
	{
		return true;
	}

	return false;
}

bool PointingGroup::PointingGroupInColumn(Map* map, Cell* row, int temp_j, int column_j, int size)
{
	this->clearNumbers();
	this->overrideNumbersWithRowNotes(row);

	int count = this->getCountOfHiddenNumbers(size, size, size);

	if (count == 0)
	{
		return false;
	}

	if (this->findPointingGroupInColumn(map, row, count, temp_j, column_j, size))
	{
		return true;
	}

	return false;
}