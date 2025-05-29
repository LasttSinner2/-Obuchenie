#pragma once
#include "Pixsel.h"
#include <cmath>
#include <iostream>

// Конструктор по умолчанию
Pixsel::Pixsel() : x(0), y(0), color(0) {}

// Конструктор с параметрами
Pixsel::Pixsel(int x, int y, int color) : x(x), y(y), color(color) {}



// Геттеры
int Pixsel::GetX() const {
    return x;
}

int Pixsel::GetY() const {
    return y;
}

int Pixsel::GetColor() const {
    return color;
}

// Сеттеры
void Pixsel::SetX(int x) {
    this->x = x;
}

void Pixsel::SetY(int y) {
    this->y = y;
}

void Pixsel::SetColor(int color) {
    // Проверка: цвет в диапазоне 0–255
    if (color >= 0 && color <= 255) {
        this->color = color;
    }
}

// Установка всех значений
void Pixsel::Set(int x, int y, int color) {
    this->x = x;
    this->y = y;
    if (color >= 0 && color <= 255) {
        this->color = color;
    }
}

// фунция печати пикселя
void Pixsel::printPixsel() {
    std::cout << "x : " << GetX() << std::endl;
    std::cout << "y : " << GetY() << std::endl;
    std::cout << "color : " << GetColor() << std::endl;
}


bool Pixsel::operator==(const Pixsel& other) const {
    return x == other.x && y == other.y && color == other.color;
}


// Реализация функции Distance
double Distance(const Pixsel& p1, const Pixsel& p2) {
    int dx = p2.GetX() - p1.GetX();
    int dy = p2.GetY() - p1.GetY();
    return std::sqrt(dx * dx + dy * dy);

};

