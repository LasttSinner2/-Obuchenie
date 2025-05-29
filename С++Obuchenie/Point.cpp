#pragma once
#include "Point.h"

// Конструктор по умолчанию
Point::Point() : x(0), y(0) {}

// Конструктор с параметрами
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

