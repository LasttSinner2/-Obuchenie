#pragma once
#include "Line.h"
#include <cmath>

// Конструктор по умолчанию
Line::Line() : Point(), start(), end() {}

// Конструктор с параметрами
Line::Line(const Point& start, const Point& end) : Point(start), start(start), end(end) {}

// Виртуальный деструктор
Line::~Line() {}


int Line::GetStartX() const { return start.GetX(); }
int Line::GetStartY() const { return start.GetY(); }

int Line::GetEndX() const { return end.GetX(); }
int Line::GetEndY() const { return end.GetY(); }

// Сеттеры
void Line::SetStart(const Point& start) { this->start = start; }
void Line::SetEnd(const Point& end) { this->end = end; }



// Вычисление длины линии
double Line::GetLength() const {
    int dx = end.GetX() - start.GetX();
    int dy = end.GetY() - start.GetY();
    return std::sqrt(dx * dx + dy * dy);
}


double Line::CenterX() const {
    return (start.GetX() + end.GetX()) / 2.0; // Используем 2.0 для получения double
}

double Line::CenterY() const {
    return (start.GetY() + end.GetY()) / 2.0;
}


void Line::Move(int sdvig) {
    // Смещаем начальную точку
    start.SetX(start.GetX() + sdvig);
    start.SetY(start.GetY() + sdvig);
    // Смещаем конечную точку
    end.SetX(end.GetX() + sdvig);
    end.SetY(end.GetY() + sdvig);
}


// Функция печати линии
void Line::PrintLine() const {
    std::cout << "Line: Start (" << GetStartX() << ", " << GetStartY()
        << "), End (" << GetEndX() << ", " << GetEndY()
        << "), Length = " << GetLength() << std::endl;
}


// Проверка принадлежности точки отрезку
bool Line::IsPointOnLine(const Point& point) const {
    // Вычисляем расстояния
    double distStartToPoint = std::sqrt(std::pow(point.GetX() - start.GetX(), 2) +
        std::pow(point.GetY() - start.GetY(), 2));
    double distEndToPoint = std::sqrt(std::pow(point.GetX() - end.GetX(), 2) +
        std::pow(point.GetY() - end.GetY(), 2));
    double distStartToEnd = GetLength();

    // Погрешность для сравнения чисел с плавающей точкой
    const double epsilon = 1e-6;

    // Проверяем, равно ли сумма расстояний от точки до концов отрезка его длине
    return std::abs(distStartToPoint + distEndToPoint - distStartToEnd) < epsilon;
}