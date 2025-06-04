#pragma once
#include "Pixsel.h"
#include <cmath>
#include <iostream>
#include <map>
#include <vector>


// Конструктор по умолчанию
Pixsel::Pixsel() : x(0), y(0), color(0) {}

// Конструктор с параметрами
Pixsel::Pixsel(int x, int y, int color) : x(x), y(y), color(color) {}
//конструктор преобразования
Pixsel::Pixsel(int x) {
    SetX(x);
    SetY(x);
    SetColor(0);
}

// Деструктор 
Pixsel::~Pixsel() {

}
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
void Pixsel::printPixsel() const{
    std::cout << "x : " << GetX() << std::endl;
    std::cout << "y : " << GetY() << std::endl;
    std::cout << "color : " << GetColor() << std::endl;
}

// перегрузка оператора равенства
bool Pixsel::operator==(const Pixsel& other) const {
    return x == other.x && y == other.y && color == other.color;
}


// перегрузка оператора неравенства
bool Pixsel::operator!=(const Pixsel& other) const {
    return !(*this == other);
}


// функция смещения пикселя
void Pixsel::MuvePixsel(int dx, int dy) {
    x += dx;
    y += dy;
}

// Реализация функции Distance
double Distance(const Pixsel& p1, const Pixsel& p2) {
    int dx = p2.GetX() - p1.GetX();
    int dy = p2.GetY() - p1.GetY();
    return std::sqrt(dx * dx + dy * dy);

};

class PixselMap {
private:
    std::map<std::pair<int, int>, Pixsel> pixels;
    static const int WIDTH = 10;  // Ширина холста
    static const int HEIGHT = 10; // Высота холста
    std::vector<std::vector<char>> canvas;
public:

    // Конструктор
    PixselMap() {
        // Инициализация холста пустыми символами
        canvas = std::vector<std::vector<char>>(HEIGHT, std::vector<char>(WIDTH, '.'));
    }

    // Добавление пикселя в мапу
    void AddPixel(int x, int y, int color) {
        if (color >= 0 && color <= 255) {
            pixels[{x, y}] = Pixsel(x, y, color);
            std::cout << "Pixel added at (" << x << ", " << y << ") with color " << color << std::endl;
        }
        else {
            std::cout << "Invalid color value: " << color << ". Color must be between 0 and 255." << std::endl;
        }

    }

    // Удаление пикселя по координатам
    void RemovePixel(int x, int y) {
        auto it = pixels.find({ x, y });
        if (it != pixels.end()) {
            pixels.erase(it);
            std::cout << "Pixel removed at (" << x << ", " << y << ")" << std::endl;
        }
        else {
            std::cout << "No pixel found at (" << x << ", " << y << ")" << std::endl;
        }
    }

    // Вывод всех пикселей
    void PrintAllPixels() const {
        if (pixels.empty()) {
            std::cout << "No pixels in the map." << std::endl;
            return;
        }
        for (const auto& pair : pixels) {
            std::cout << "Pixel at (" << pair.first.first << ", " << pair.first.second << "):" << std::endl;
            pair.second.printPixsel(); // Вызов для константного объекта
            std::cout << "------------------------" << std::endl;
        }
    }

    // Получение пикселя по координатам
    bool GetPixel(int x, int y, Pixsel& pixel) const {
        auto it = pixels.find({ x, y });
        if (it != pixels.end()) {
            pixel = it->second;
            return true;
        }
        return false;
    }

    void Draw(int x, int y) {
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            std::cout << "Coordinates (" << x << ", " << y << ") are out of canvas bounds!" << std::endl;
            return;
        }
        auto it = pixels.find({ x,y });
        if (it != pixels.end()) {
            int color = it->second.GetColor();
            // Определяем символ в зависимости от цвета
            char symbol = '.';
            if (color > 0) {
                if (color <= 85) symbol = '#';  // Тёмный
                else if (color <= 170) symbol = '+'; // Средний
                else symbol = '*'; // Светлый
            }
            canvas[x][y] = symbol;
            std::cout << "Pixel drawn at (" << x << ", " << y << ") with color " << color << std::endl;

        }
        else {
            std::cout << "No pixel found at (" << x << ", " << y << ") to draw!" << std::endl;
        }
    }

    

    




    void DisplayCanvas() const {
        for (int k = 0; k < WIDTH; k++) {
            std::cout << k << " ";
        }

        for (int l = 0; l < HEIGHT; l++) {
            std::cout << l << " ";
            for (int k = 0; k < WIDTH; ++k){
                std::cout << canvas[l][k] << " ";
            }
            std::cout << std::endl;
        }
    }




};