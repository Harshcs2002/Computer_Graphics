#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;
void Bcircle(int r)
{
    int x, y, xc = getmaxx() / 2, yc = getmaxy() / 2, p;
    x = 0;
    y = r;
    p = 3 - (2 * r);
    for (x = 0; x <= y; x++)
    {
        putpixel(xc + x, yc - y, YELLOW);
        if (p < 0)
        {
            y = y;
            p = (p + (4 * x) + 1);
        }
        else
        {
            y = y - 1;
            p = (p + (4 * (x - y) + 1));
        }
        putpixel(xc + x, yc - y, YELLOW);
        putpixel(xc - x, yc - y, YELLOW);
        putpixel(xc + x, yc + y, YELLOW);
        putpixel(xc - x, yc + y, YELLOW);
        putpixel(xc + y, yc - x, YELLOW);
        putpixel(xc - y, yc - x, YELLOW);
        putpixel(xc + y, yc + x, YELLOW);
        putpixel(xc - y, yc + x, YELLOW);
    }
}
int main()
{
    int gd = DETECT, gm;
    int r;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    cout << "Enter the radius of circle: ";
    cin >> r;
    Bcircle(r);
    getch();
    closegraph();
    return 0;
}