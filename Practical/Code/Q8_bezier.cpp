// write a program to draw a bezier curve using graphics.h

#include <graphics.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;

void bezier(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    float x, y, t;
    for (t = 0.0; t <= 1.0; t += 0.00005)
    {
        x = pow(1 - t, 3) * x1 + 3 * t * pow(1 - t, 2) * x2 + 3 * pow(t, 2) * (1 - t) * x3 + pow(t, 3) * x4;
        y = pow(1 - t, 3) * y1 + 3 * t * pow(1 - t, 2) * y2 + 3 * pow(t, 2) * (1 - t) * y3 + pow(t, 3) * y4;
        putpixel(x, y, WHITE);
    }

    circle(x1, y1, 3);
    circle(x2, y2, 3);
    circle(x3, y3, 3);
    circle(x4, y4, 3);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
     int x1, y1, x2, y2, x3, y3, x4, y4;

     cout << "---Bezier Curve---" << endl;
    cout << "Enter Point 1 (x, y): ";
    cin >> x1 >> y1;
    cout << "Enter Point 2 (x, y): ";
    cin >> x2 >> y2;
    cout << "Enter Point 3 (x, y): ";
    cin >> x3 >> y3;
    cout << "Enter Point 4 (x, y): ";
    cin >> x4 >> y4;

    bezier(x1, y1, x2, y2, x3, y3, x4, y4);

    getch();
    closegraph();
    return 0;
}