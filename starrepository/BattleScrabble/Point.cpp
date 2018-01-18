#include "stdafx.h"
#include "Point.h"
#include <sstream>

Point::Point(const int _x, const int _y) : x(_x), y(_y)
{
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

std::string Point::toString() const
{
	std::ostringstream stringStream;
	stringStream << "(" << x << "," << y << ")";
	return stringStream.str();
}

bool operator==(const Point& _Left, const Point& _Right)
{
	return _Left.x == _Right.x && _Left.y == _Right.y;
}
