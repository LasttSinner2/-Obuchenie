#pragma once
#include <iostream>
#include <fstream>

class Point {
private:
	int x;
	int y;
public:

	// Конструктор по умолчанию
	Point();

	// Конструктор с параметрами
	Point(int x, int y);
	
	// Деструктор
	~Point();


	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetX(int x);
	void SetY(int x);

	void Print();

	Point operator +(const Point&);
	int operator *(const Point&);

	// Дружественная функция для перегрузки оператора <<
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	
	friend std::istream& operator>>(std::istream& is, Point& point);
	
	void SaveToFile(std::ofstream& outFile) const;

};

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.x << point.y << ")" << std::endl;
	return os;
};

std::istream& operator>>(std::istream& is, Point& point) {
	is >> point.x >> point.y;  // Чтение x и y из потока
	return is;
}