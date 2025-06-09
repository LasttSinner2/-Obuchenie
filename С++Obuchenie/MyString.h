#pragma once
class MyString {
public:
	int Length() { return n_; }
	void Print() { std::cout << s_; }
	MyString(const char* str = "");
	~MyString();
	MyString& operator =(const MyString&);
	MyString(const String&);
	String& operator +=(const MyString& rhs);
	friend bool operator ==(const MyString& lhs, const MyString& rhs);
	friend bool operator >(const MyString& lhs, const MyString& rhs);
	char& operator [](int i);
private:
	size_t n_; //длина строки (без учета завершающего С\0Т)
	char* s_; //адрес буфера дл€ строки в динамической пам€ти
};