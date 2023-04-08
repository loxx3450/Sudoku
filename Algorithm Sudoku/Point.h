#pragma once


class Point
{
private:
	int x;
	int y;

public:
	Point(int x = -1, int y = -1) :
		x{x},
		y{y}
	{}

	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}
};