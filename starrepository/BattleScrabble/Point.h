#pragma once

#include <string>
#include "stdafx.h"

class Point
{
private:
	int x;
	int y;
public:
	Point(const int _x, const int _y);
	int getX() const;
	int getY() const;
	std::string toString() const;


	friend bool operator==(const Point& _Left, const Point& _Right);
};
