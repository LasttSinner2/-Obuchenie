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

    PixselMap pixselMap;

    pixselMap.AddPixel(10, 20, 30);
    pixselMap.AddPixel(44, 228, 57);
    pixselMap.AddPixel(228, 72, 88);
    cout << "____________________________________________________________________________" << endl;
    pixselMap.PrintAllPixels();
    cout << "____________________________________________________________________________" << endl;
    PixselMap map;

    // Добавляем пиксели
    map.AddPixel(2, 1, 200); // Светлый
    map.AddPixel(3, 3, 100); // Средний

    // Рисуем пиксели
    map.Draw(2, 1);
    map.Draw(3, 3);

    // Выводим холст
    map.DisplayCanvas();

    // перегруженный оператор <<
    std::cout << p;

    std::ofstream outFile("points.txt");
    if (outFile.is_open()) {
        p.SaveToFile(outFile);
        outFile.close();
    }


    Date d;
    Set(d, 12, 12, 2022);

    std::ofstream outF("Data.txt");
    if (outF.is_open()) {
        SaveDateToFile(d, outF);
        outF.close();
    }
    


    return 0;
}

