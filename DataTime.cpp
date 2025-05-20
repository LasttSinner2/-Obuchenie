#include "DataTime.h"
#include <iostream>

using namespace std;

// Установка времени
void Set(Time& t, int hour, int minutes, int seconds) {
    t.hour = hour;
    t.minutes = minutes;
    t.seconds = seconds;
}

// Проверка даты
bool IsValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}

// Установка даты
bool Set(Date& d, int day, int month, int year) {
    if (IsValidDate(day, month, year)) {
        d.day = day;
        d.month = month;
        d.year = year;
        return true;
    }
    return false;
}

// Печать
void Print(const Date& d) {
    cout << "Дата: " << d.day << "." << d.month << "." << d.year << endl;
}

void Print(const Time& t) {
    cout << "Время: " << t.hour << ":" << t.minutes << ":" << t.seconds << endl;
}

// Сравнение на равенство
string Equal(const Time& t1, const Time& t2) {
    return (t1.hour == t2.hour && t1.minutes == t2.minutes && t1.seconds == t2.seconds) ? "Yes" : "No";
}

string Equal(const Date& d1, const Date& d2) {
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) ? "Yes" : "No";
}

// Проверка на меньше
string Less(const Time& t1, const Time& t2) {
    if (t1.hour < t2.hour) {
        return "Yes";
    }
    else if (t1.hour == t2.hour) {
        if (t1.minutes < t2.minutes) {
            return "Yes";
        }
        else if (t1.minutes == t2.minutes) {
            if (t1.seconds < t2.seconds) {
                return "Yes";
            }
        }
    }
    return "No";
}

string Less(const Date& d1, const Date& d2) {
    if (d1.year < d2.year) {
        return "Yes";
    }
    else if (d1.year == d2.year) {
        if (d1.month < d2.month) {
            return "Yes";
        }
        else if (d1.month == d2.month) {
            if (d1.day < d2.day) {
                return "Yes";
            }
        }
    }
    return "No";
}

// Проверка на больше
string Grater(const Time& t1, const Time& t2) {
    if (t1.hour < t2.hour) {
        return "No";
    }
    else if (t1.hour == t2.hour) {
        if (t1.minutes < t2.minutes) {
            return "No";
        }
        else if (t1.minutes == t2.minutes) {
            if (t1.seconds < t2.seconds) {
                return "No";
            }
        }
    }
    return "Yes";
}

string Grater(const Date& d1, const Date& d2) {
    if (d1.year < d2.year) {
        return "No";
    }
    else if (d1.year == d2.year) {
        if (d1.month < d2.month) {
            return "No";
        }
        else if (d1.month == d2.month) {
            if (d1.day < d2.day) {
                return "No";
            }
        }
    }
    return "Yes";
}

// Ввод времени
bool InputTime(Time& t) {
    int h, m, s;
    cin >> h >> m >> s;
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
        Set(t, h, m, s);
        return true;
    }
    return false;
}

// Ввод даты
bool InputDate(Date& d) {
    int day, month, year;
    cin >> day >> month >> year;
    return Set(d, day, month, year);
}