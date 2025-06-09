#pragma once

#include <iostream>
#include <cstring>

#include "MyString.h"

using namespace std


MyString::MyString(const char* str)
{
	n_ = strlen(str); //��������� ����� ������
	s_ = new char[n_ + 1]; //�������� �����
	//����� ����� ���� ����� � ��������� ������
	strcpy(s_, str); //����������� � ����� ������
}
MyString::~MyString()
{
	delete[] s_; // ���� new[], �� � delete[]
}
MyString::MyString(const MyString& str) //�������� �����
{
	n_ = str.n_; //���������� ����� ������
	s_ = new char[n_ + 1];
	//����� ����� ���� ����� � ��������� ������
	strcpy(s_, str.s_);
}

MyString& MyString::operator =(const MyString& str)
{
	if (this == &str) return *this; //������ �� ����������������
	delete[] s_; //���������� ����, ������� �������
	n_ = str.n_;
	s_ = new char[n_ + 1];
	//����� ����� ���� ����� � ��������� ������
	strcpy(s_, str.s_);
	return *this; //���������� ����� �������
}

MyString& MyString::operator +=(const MyString& rh)
{
	char* t = strcpy(new char[n_ + rh.n_ + 1], s_);
	delete[] s_;
	s_ = strcat(t, rh.s_);
	n_ += rh.n_;
	return *this;
}