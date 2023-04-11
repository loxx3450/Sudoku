//#pragma once
//#include "NakedGroup.h"
//
//class NakedTriplet : public NakedGroup
//{
//private:
//
//	bool isNewPoint(Point* array, int count, int x, int y)
//	{
//		for (int i{}; i < count; ++i)
//		{
//			if (x == array[i].getX() && y == array[i].getY())
//			{
//				return false;
//			}
//		}
//
//		return true;
//	}
//
//	bool isNewIndex(int* array, int count, int index)
//	{
//		for (int i{}; i < count; ++i)
//		{
//			if (index == array[i])
//			{
//				return false;
//			}
//		}
//
//		return true;
//	}
//
//	int fillRemainingNotes(Cell* array, int* remainingNotes)
//	{
//		bool* notes;
//
//		bool isAlready{ false };
//
//		int index{};
//
//		for (int i{}; i < Groups::Triplet; ++i)
//		{
//			notes = array[i].getNotes();
//
//			for (int j{}; j < this->map_size; ++j)
//			{
//				if (notes[j] == true)
//				{
//					for (int g{}; g < Groups::Triplet; ++g)
//					{
//						if (remainingNotes[g] == j + 1)
//						{
//							isAlready = true;
//							break;
//						}
//					}
//
//					if (!isAlready)
//					{
//						remainingNotes[index++] = j + 1;
//					}
//
//					isAlready = false;
//				}
//			}
//		}
//
//		return index;
//	}
//
//	bool ifPassRulesForNakedTriplets(Cell* array)
//	{
//		int* remainingNotes = new int[Groups::Triplet]{};
//
//		int count{};
//
//		count = this->fillRemainingNotes(array, remainingNotes);
//
//		if (count != 3)
//		{
//			delete[] remainingNotes;
//
//			return false;
//		}
//
//		count = 0;
//
//		for (int i{}; i < Groups::Triplet; ++i)
//		{
//			for (int j{}; j < Groups::Triplet; ++j)
//			{
//				if (array[j].inNotes(remainingNotes[i]) == true)
//				{
//					++count;
//				}
//			}
//
//			if (count < 2)
//			{
//				delete[] remainingNotes;
//
//				return false;
//			}
//
//			count = 0;
//
//		}
//
//		delete[] remainingNotes;
//
//
//		return true;
//	}
//
//	void editNotesForTripletsInField(Field* tempField, Cell* array, Point* arr, int count)
//	{
//		for (int i{}; i < this->field_size; ++i)
//		{
//			for (int j{}; j < this->field_size; ++j)
//			{
//				if (tempField->getNum(i, j) == 0 && this->isNewPoint(arr, count, i, j))
//				{
//					for (int g{}; g < count; ++g)
//					{
//						tempField->getCell(i, j)->editNotes(array[g].getNotes());
//					}
//				}
//			}
//		}
//	}
//
//	void editNotesForTripletsInRow(Cell* row, Cell* array, int* arr, int count)
//	{
//		for (int i{}; i < this->field_size; ++i)
//		{
//			std::cout << arr[i] << " ";
//		}
//		std::cout << "\n\n";
//
//		for (int i{}; i < this->map_size; ++i)
//		{
//			if (row[i].getNum() == 0 && this->isNewIndex(arr, count, i))
//			{
//				for (int j{}; j < count; ++j)
//				{
//					if (array[j].getNotes() != nullptr && row[i].getNotes() != nullptr)
//					{
//						row[i].editNotes(array[j].getNotes());
//					}
//				}
//			}
//		}
//	}
//
//	void findPossibleTripletsInField(Field* tempField)
//	{
//		int index{}, count{ tempField->countOfEmptyCells() };
//
//		Cell* arrayCells = new Cell[count]{};
//		Point* arrayPoints = new Point[count]{};
//
//		for (int i{}; i < this->field_size; ++i)
//		{
//			for (int j{}; j < this->field_size; ++j)
//			{
//				if ((tempField->getCell(i, j)->countOfNotes() >= 2 && tempField->getCell(i, j)->countOfNotes() <= 3) && tempField->getNum(i, j) == 0)
//				{
//					arrayCells[index].setCell(*tempField->getCell(i, j));
//					arrayPoints[index].set(i, j);
//					index++;
//				}
//			}
//		}
//
//		if (index == 3)
//		{
//			if (this->ifPassRulesForNakedTriplets(arrayCells))
//			{
//				this->editNotesForTripletsInField(tempField, arrayCells, arrayPoints, 3);
//			}
//		}
//		else if (index > 3)
//		{
//			Cell* temp_arrayCells = new Cell[Groups::Triplet];
//			Point* temp_arrayPoints = new Point[Groups::Triplet];
//
//			for (int i{}; i < index - 2; ++i)
//			{
//				for (int j{ i + 1 }; j <= index - i + 1; ++j)
//				{
//					for (int g{ j + 1 }; g < index; ++g)
//					{
//						temp_arrayCells[0] = arrayCells[i];
//						temp_arrayCells[1] = arrayCells[j];
//						temp_arrayCells[2] = arrayCells[g];
//
//						if (this->ifPassRulesForNakedTriplets(temp_arrayCells))
//						{
//							temp_arrayPoints[0].set(arrayPoints[i].getX(), arrayPoints[i].getY());
//							temp_arrayPoints[1].set(arrayPoints[j].getX(), arrayPoints[j].getY());
//							temp_arrayPoints[2].set(arrayPoints[g].getX(), arrayPoints[g].getY());
//							this->editNotesForTripletsInField(tempField, temp_arrayCells, temp_arrayPoints, 3);
//						}
//					}
//				}
//			}
//
//			delete[] temp_arrayCells;
//			delete[] temp_arrayPoints;
//		}
//		delete[] arrayCells;
//		delete[] arrayPoints;
//	}
//
//	void findPossibleTripletsInRow(Cell* row, int count)
//	{
//		int index{};
//
//		Cell* arrayCells = new Cell[count]{};
//		int* arrayIndexes = new int[count] {};
//
//		for (int i{}; i < this->map_size; ++i)
//		{
//			if ((row[i].countOfNotes() >= 2 && row[i].countOfNotes() <= 3) && row[i].getNum() == 0)
//			{
//				arrayCells[index].setCell(row[i]);
//				arrayIndexes[index] = i;
//				index++;
//			}
//		}
//
//		if (index == 3)
//		{
//			if (this->ifPassRulesForNakedTriplets(arrayCells))
//			{
//				this->editNotesForTripletsInRow(row, arrayCells, arrayIndexes, 3);
//			}
//		}
//		else if (index > 3)
//		{
//			Cell* temp_arrayCells = new Cell[Groups::Triplet];
//			int* temp_arrayIndexes = new int[Groups::Triplet];
//
//			for (int i{}; i < index - 2; ++i)
//			{
//				for (int j{ i + 1 }; j <= index - i + 1; ++j)
//				{
//					for (int g{ j + 1 }; g < index; ++g)
//					{
//						temp_arrayCells[0] = arrayCells[i];
//						temp_arrayCells[1] = arrayCells[j];
//						temp_arrayCells[2] = arrayCells[g];
//
//						if (this->ifPassRulesForNakedTriplets(temp_arrayCells))
//						{
//							temp_arrayIndexes[0] = arrayIndexes[i];
//							temp_arrayIndexes[1] = arrayIndexes[j];
//							temp_arrayIndexes[2] = arrayIndexes[g];
//							this->editNotesForTripletsInRow(row, temp_arrayCells, temp_arrayIndexes, 3);
//						}
//					}
//				}
//			}
//
//			delete[] temp_arrayCells;
//			delete[] temp_arrayIndexes;
//		}
//
//		delete[] arrayIndexes;
//	}
//
//public:
//	virtual void nakedTripletsInField(Map* map, Field* temp, int temp_i, int temp_j) override
//	{
//		if (temp->countOfEmptyCells() < Groups::Triplet)
//		{
//			return;
//		}
//
//		this->findPossibleTripletsInField(temp);
//
//		map->takeField(temp, temp_i * this->field_size, temp_j * this->field_size);
//	}
//
//	virtual void nakedTripletsInRow(Cell* row) override
//	{
//		int count{};
//
//		for (int i{}; i < this->map_size; ++i)
//		{
//			if (row[i].getNum() == 0)
//			{
//				++count;
//			}
//		}
//
//		if (count < Groups::Triplet)
//		{
//			return;
//		}
//
//		this->findPossibleTripletsInRow(row, count);
//	}
//};
//
