#pragma once
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

};