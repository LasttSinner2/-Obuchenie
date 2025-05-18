
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
    std::cout << "] " << std:: endl;
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




int main()
{
    print(123);
    print(std::vector<double>{1.2, 1.77, 1, 99});
    print(std::string("Hello"));
    print(std::list<std::string>{"a", "d"});
    std::set<int> numbers = { 1, 4, 6 };
    print(numbers);
    return 0;
}

