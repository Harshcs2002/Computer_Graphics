#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, d, x, y;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    cout << "Enter the value of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    d = dy - dx / 2;
    x = x1;
    y = y1;
    putpixel(x, y, RED);
    while (x < x2)
    {
        if (d < 0)
        {
            d = d + dy;
        }
        else
        {
            d = d + (dy - dx);
            y++;
        }
        x++;
        putpixel(x, y, RED);
        delay(100);
    }
    getch();
    closegraph();
    return 0;
}