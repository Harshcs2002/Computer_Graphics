#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;
void midpointellipse(int rx, int ry)
{
    int x, y, xc = getmaxx() / 2, yc = getmaxy() / 2;
    line(0, yc, getmaxx(), yc);
    line(xc, 0, xc, getmaxy());
    float p1, p2;
    x = 0;
    y = ry;
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    while ((2.0 * ry * ry * x) <= (2.0 * rx * rx * y))
    {
        putpixel(xc + x, yc + y, YELLOW);
        putpixel(xc - x, yc + y, YELLOW);
        putpixel(xc + x, yc - y, YELLOW);
        putpixel(xc - x, yc - y, YELLOW);
        if (p1 < 0)
        {
            x = x + 1;
            p1 = p1 + (2.0 * ry * ry * x) + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p1 = p1 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) - (ry * ry);
        }
    }
    p2 = (ry * ry * (x + 0.5) * (x + 0.5)) + (rx * rx * (y - 1) * (y - 1)) - (rx * rx * ry * ry);
    while (y >= 0)
    {
        putpixel(xc + x, yc + y, YELLOW);
        putpixel(xc - x, yc + y, YELLOW);
        putpixel(xc + x, yc - y, YELLOW);
        putpixel(xc - x, yc - y, YELLOW);
        if (p2 > 0)
        {
            y = y - 1;
            p2 = p2 - (2.0 * rx * rx * y) + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p2 = p2 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (rx * rx);
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    int rx, ry;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    cout << "Enter the radius of x-axis: ";
    cin >> rx;
    cout << "Enter the radius of y-axis: ";
    cin >> ry;
    midpointellipse(rx, ry);
    getch();
    closegraph();
    return 0;
}