#pragma once
#include "Point.h"



class Line : public Point{
private:
	Point start;
	Point end; 
public:
    // Конструктор по умолчанию
    Line();

    // Конструктор с параметрами 
    Line(const Point& start, const Point& end);

    // Виртуальный деструктор
    virtual ~Line();


    // Сеттеры
    void SetStart(const Point& start);
    void SetEnd(const Point& end);


    int GetStartX() const;
    int GetStartY() const;
    int GetEndX() const;
    int GetEndY() const;

    double GetLength() const;
    double CenterX() const;
    double CenterY() const;

    // Функция для смещения координат
    void Move(int sdvig);

    void PrintLine() const;
};