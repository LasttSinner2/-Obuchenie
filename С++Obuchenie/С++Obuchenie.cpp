#pragma once
#include "PrintAll.h"
#include "DataTime.cpp"
#include "DinamicStructure.h"
#include "Pixsel.cpp"
#include "Point.cpp"
#include "Line.cpp"

int main()
{
    vector <int> v = { 1, 2, 44, 55, 66 };
    print(v);
    cout << "____________________________________________________________________________" << endl;
    Pixsel pix(0, 0, 0);
    pix.SetX(55);
    pix.SetY(66);
    pix.SetColor(77);
    pix.printPixsel();
    cout << "____________________________________________________________________________" << endl;
    Pixsel pix2(11, 12, 25);
    pix2 = 5;
    double dist = Distance(pix, pix2);
    cout << "Distance: " << dist << endl;
    if (pix == pix2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    cout << "____________________________________________________________________________" << endl;
    Point p(5, 5);
    
    Point p2(7, 4);

    Line line(p, p2);
    line.PrintLine();
    cout << "____________________________________________________________________________" << endl;
    cout << line.IsPointOnLine(p) << endl;

    return 0;
}

