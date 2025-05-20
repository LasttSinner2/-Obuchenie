#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>

template <typename T>
void print(const T& value, bool inline_mode = false) {
    std::cout << value;
    if (!inline_mode)
    {
        std::cout << std::endl;
    }
}

template <typename T>
void print(const std::vector<T>& vec)
{
    std::cout << "[ ";
    for (const auto& items : vec)
    {
        print(items, true);
        std::cout << " ";
    }
    std::cout << "] " << std::endl;
}

template <typename T>
void print(const std::list<T>& ls)
{
    std::cout << "[ ";
    for (const auto& items : ls)
    {
        print(items, true);
        std::cout << " ";
    }
    std::cout << "] " << std::endl;
}

template <typename T>
void print(const std::set<T>& set)
{
    std::cout << "[ ";
    for (const auto& items : set)
    {
        print(items, true);
        std::cout << " ";
    }
    std::cout << "] " << std::endl;
}
