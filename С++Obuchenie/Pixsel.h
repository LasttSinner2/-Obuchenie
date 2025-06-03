#pragma once

class Pixsel {
private:
    int x;
    int y;
    int color;

public:
    // ����������� �� ���������
    Pixsel();

    // ����������� � �����������
    Pixsel(int x, int y, int color);

    // ����������� ��������������
    Pixsel(int x);

    // ���������� 
    ~Pixsel();

    // �������
    int GetX() const;
    int GetY() const;
    int GetColor() const;

    // �������
    void SetX(int x);
    void SetY(int y);
    void SetColor(int color);

    // ����� ��� ��������� ���� ��������
    void Set(int x, int y, int color);

    // ������ ������ �������
    void printPixsel() const;

    void MuvePixsel(int dx, int dy);

    // ���������
    bool operator==(const Pixsel& other) const;
    bool operator!=(const Pixsel& other) const;
};

// ��������� ������� ��� ���������� ����������
double Distance(const Pixsel & p1, const Pixsel & p2);

