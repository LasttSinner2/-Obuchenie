#pragma once

#include <fstream>
#include <string>

// Структура для даты
struct Date {
    int day;
    int month;
    int year;
};

// Структура для времени
struct Time {
    int seconds;
    int minutes;
    int hour;
};

// Вспомогательные функции
void Set(Time& t, int hour, int minutes, int seconds = 0);
bool IsValidDate(int day, int month, int year);
bool Set(Date& d, int day, int month, int year = 2025);
void Print(const Date& d);
void Print(const Time& t);
std::string Equal(const Time& t1, const Time& t2);
std::string Equal(const Date& d1, const Date& d2);
std::string Less(const Time& t1, const Time& t2);
std::string Less(const Date& d1, const Date& d2);
std::string Grater(const Time& t1, const Time& t2);
std::string Grater(const Date& d1, const Date& d2);
bool InputTime(Time& t);
bool InputDate(Date& d);

void SaveDateToFile(const Date& d, std::ofstream& outFile);

