#pragma once

#include <iostream>
#include <cstring>

#include "MyString.h"

using namespace std


MyString::MyString(const char* str)
{
	n_ = strlen(str); //вычислили длину строки
	s_ = new char[n_ + 1]; //выделили буфер
	//здесь может быть отказ в выделении памяти
	strcpy(s_, str); //скопировали в буфер строку
}
MyString::~MyString()
{
	delete[] s_; // если new[], то и delete[]
}
MyString::MyString(const MyString& str) //глубокая копия
{
	n_ = str.n_; //извлеклили длину строки
	s_ = new char[n_ + 1];
	//здесь может быть отказ в выделении памяти
	strcpy(s_, str.s_);
}

MyString& MyString::operator =(const MyString& str)
{
	if (this == &str) return *this; //защита от самоприсваивания
	delete[] s_; //освободили блок, которым владели
	n_ = str.n_;
	s_ = new char[n_ + 1];
	//здесь может быть отказ в выделении памяти
	strcpy(s_, str.s_);
	return *this; //возвращаем левый операнд
}

MyString& MyString::operator +=(const MyString& rh)
{
	char* t = strcpy(new char[n_ + rh.n_ + 1], s_);
	delete[] s_;
	s_ = strcat(t, rh.s_);
	n_ += rh.n_;
	return *this;
}