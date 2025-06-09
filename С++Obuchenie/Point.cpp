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

Point Point::operator +(const Point& other)
{
	return Point(x + other.x, y + other.y);
}
int Point::operator *(const Point& other)
{
	return x * other.x + y * other.y;
}

void Point::SaveToFile(std::ofstream& outFile) const {
	if (!outFile.is_open()) {
		std::cerr << "Error: File is not open for writing!\n";
		return;
	}
	outFile << x << " " << y << "\n"; // Простой формат: x и y через пробел
}

