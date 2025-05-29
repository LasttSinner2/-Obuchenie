#pragma once
#include "Line.h"
#include <cmath>

// ����������� �� ���������
Line::Line() : Point(), start(), end() {}

// ����������� � �����������
Line::Line(const Point& start, const Point& end) : Point(start), start(start), end(end) {}

// ����������� ����������
Line::~Line() {}


int Line::GetStartX() const { return start.GetX(); }
int Line::GetStartY() const { return start.GetY(); }

int Line::GetEndX() const { return end.GetX(); }
int Line::GetEndY() const { return end.GetY(); }

// �������
void Line::SetStart(const Point& start) { this->start = start; }
void Line::SetEnd(const Point& end) { this->end = end; }



// ���������� ����� �����
double Line::GetLength() const {
    int dx = end.GetX() - start.GetX();
    int dy = end.GetY() - start.GetY();
    return std::sqrt(dx * dx + dy * dy);
}


double Line::CenterX() const {
    return (start.GetX() + end.GetX()) / 2.0; // ���������� 2.0 ��� ��������� double
}

double Line::CenterY() const {
    return (start.GetY() + end.GetY()) / 2.0;
}


void Line::Move(int sdvig) {
    // ������� ��������� �����
    start.SetX(start.GetX() + sdvig);
    start.SetY(start.GetY() + sdvig);
    // ������� �������� �����
    end.SetX(end.GetX() + sdvig);
    end.SetY(end.GetY() + sdvig);
}


// ������� ������ �����
void Line::PrintLine() const {
    std::cout << "Line: Start (" << GetStartX() << ", " << GetStartY()
        << "), End (" << GetEndX() << ", " << GetEndY()
        << "), Length = " << GetLength() << std::endl;
}


// �������� �������������� ����� �������
bool Line::IsPointOnLine(const Point& point) const {
    // ��������� ����������
    double distStartToPoint = std::sqrt(std::pow(point.GetX() - start.GetX(), 2) +
        std::pow(point.GetY() - start.GetY(), 2));
    double distEndToPoint = std::sqrt(std::pow(point.GetX() - end.GetX(), 2) +
        std::pow(point.GetY() - end.GetY(), 2));
    double distStartToEnd = GetLength();

    // ����������� ��� ��������� ����� � ��������� ������
    const double epsilon = 1e-6;

    // ���������, ����� �� ����� ���������� �� ����� �� ������ ������� ��� �����
    return std::abs(distStartToPoint + distEndToPoint - distStartToEnd) < epsilon;
}