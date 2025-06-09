#pragma once
#include <iostream>
#include <fstream>

class Point {
private:
	int x;
	int y;
public:

	// ����������� �� ���������
	Point();

	// ����������� � �����������
	Point(int x, int y);
	
	// ����������
	~Point();


	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetX(int x);
	void SetY(int x);

	void Print();

	Point operator +(const Point&);
	int operator *(const Point&);

	// ������������� ������� ��� ���������� ��������� <<
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	
	friend std::istream& operator>>(std::istream& is, Point& point);
	
	void SaveToFile(std::ofstream& outFile) const;

};

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.x << point.y << ")" << std::endl;
	return os;
};

std::istream& operator>>(std::istream& is, Point& point) {
	is >> point.x >> point.y;  // ������ x � y �� ������
	return is;
}