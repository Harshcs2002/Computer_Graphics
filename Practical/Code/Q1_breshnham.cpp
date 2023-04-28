#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, p, x, y;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    cout << "Enter the value of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;
    x = x1;
    y = y1;
    putpixel(x, y, YELLOW);
    while (x < x2)
    {
        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            p = p + 2 * (dy - dx);
            y++;
        }
        x++;
        putpixel(x, y, YELLOW);
        delay(100);
    }
    getch();
    closegraph();
    return 0;
}