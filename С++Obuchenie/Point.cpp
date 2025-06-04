#pragma once
#include "Point.h"

// ����������� �� ���������
Point::Point() : x(0), y(0) {}

// ����������� � �����������
Point::Point(int x, int y) : x(x), y(y) {}
	

Point::~Point() {}

void Point::SetX(int x) {
	this->x = x;
}

void Point::SetY(int y) {
	this->y = y;
}

void Point::Print()
{
	std::cout << '(' << x << ',' << y << ')';
}

Point Point::operator +(const Point& other)
{
	return Point(x + other.x, y + other.y);
}
int Point::operator *(const Point& other)
{
	return x * other.x + y * other.y;
}

