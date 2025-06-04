#pragma once
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

};