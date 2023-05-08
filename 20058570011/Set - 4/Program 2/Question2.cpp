#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, steps, k;
    float x, y, xinc, yinc;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    cout << "Enter the value of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    xinc = dx / (float)steps;
    yinc = dy / (float)steps;
    x = x1;
    y = y1;
    putpixel(x, y, 15);
    for (k = 0; k < steps; k++)
    {
        x += xinc;
        y += yinc;
        putpixel(x, y, GREEN);
        delay(100);
    }
    getch();
    closegraph();
    return 0;
}