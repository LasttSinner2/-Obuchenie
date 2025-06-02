#pragma once

class Pixsel {
private:
    int x;
    int y;
    int color;

public:
    // Конструктор по умолчанию
    Pixsel();

    // Конструктор с параметрами
    Pixsel(int x, int y, int color);

    // Конструктор преобразования
    Pixsel(int x);

    // Деструктор 
    ~Pixsel();

    // Геттеры
    int GetX() const;
    int GetY() const;
    int GetColor() const;

    // Сеттеры
    void SetX(int x);
    void SetY(int y);
    void SetColor(int color);

    // Метод для установки всех значений
    void Set(int x, int y, int color);

    // фунция печати пикселя
    void printPixsel();

    // операторы
    bool operator==(const Pixsel& other) const;
    
};

// Свободная функция для вычисления расстояния
double Distance(const Pixsel & p1, const Pixsel & p2);

