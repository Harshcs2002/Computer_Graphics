#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void Window(int x1, int y1, int x2, int y2)
{
    rectangle(x1, y1, x2, y2);
}

void Code(int x, int y, int x1, int y1, int x2, int y2, int *c)
{
    if (y > y2)
        c[0] = 1;
    else
        c[0] = 0;
    if (y < y1)
        c[1] = 1;
    else
        c[1] = 0;
    if (x > x2)
        c[2] = 1;
    else
        c[2] = 0;
    if (x < x1)
        c[3] = 1;
    else
        c[3] = 0;
}

void Cohen(int x1, int y1, int x2, int y2, int xwmin, int ywmin, int xwmax, int ywmax)
{
    int c1[4], c2[4], i;
    int accept = 0, done = 0;
    Code(x1, y1, xwmin, ywmin, xwmax, ywmax, c1);
    Code(x2, y2, xwmin, ywmin, xwmax, ywmax, c2);
    do
    {
        if ((c1[0] == 0 && c1[1] == 0 && c1[2] == 0 && c1[3] == 0) &&
            (c2[0] == 0 && c2[1] == 0 && c2[2] == 0 && c2[3] == 0))
        {
            accept = 1;
            done = 1;
        }
        else if ((c1[0] & c2[0]) || (c1[1] & c2[1]) || (c1[2] & c2[2]) ||
                 (c1[3] & c2[3]))
        {
            done = 1;
        }
        else
        {
            float m = (float)(y2 - y1) / (x2 - x1);
            float xi, yi;
            for (i = 0; i < 4; i++)
            {
                if (c1[i])
                {
                    switch (i)
                    {
                    case 0:
                        xi = x1 + (x2 - x1) * (ywmax - y1) / (y2 - y1);
                        yi = ywmax;
                        break;
                    case 1:
                        xi = x1 + (x2 - x1) * (ywmin - y1) / (y2 - y1);
                        yi = ywmin;
                        break;
                    case 2:
                        yi = y1 + (y2 - y1) * (xwmax - x1) / (x2 - x1);
                        xi = xwmax;
                        break;
                    case 3:
                        yi = y1 + (y2 - y1) * (xwmin - x1) / (x2 - x1);
                        xi = xwmin;
                        break;
                    }
                    x1 = xi;
                    y1 = yi;
                    Code(x1, y1, xwmin, ywmin, xwmax, ywmax, c1);
                }
                else if (c2[i])
                {
                    switch (i)
                    {
                    case 0:
                        xi = x1 + (x2 - x1) * (ywmax - y1) / (y2 - y1);
                        yi = ywmax;
                        break;
                    case 1:
                        xi = x1 + (x2 - x1) * (ywmin - y1) / (y2 - y1);
                        yi = ywmin;
                        break;
                    case 2:
                        yi = y1 + (y2 - y1) * (xwmax - x1) / (x2 - x1);
                        xi = xwmax;
                        break;
                    case 3:
                        yi = y1 + (y2 - y1) * (xwmin - x1) / (x2 - x1);
                        xi = xwmin;
                        break;
                    }
                    x2 = xi;
                    y2 = yi;
                    Code(x2, y2, xwmin, ywmin, xwmax, ywmax, c2);
                }
            }
        }
    } while (done == 0);
    if (accept)
    {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    int x1, y1, x2, y2, xwmin, ywmin, xwmax, ywmax;
    cout << "Enter the coordinates of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the coordinates of the window: ";
    cin >> xwmin >> ywmin >> xwmax >> ywmax;
    setcolor(GREEN);
    cout << "Before clipping: ";
    Window(xwmin, ywmin, xwmax, ywmax);
    line(x1, y1, x2, y2);
    delay(8000);
    cleardevice();
    cout << "After clipping: ";
    Window(xwmin, ywmin, xwmax, ywmax);
    Cohen(x1, y1, x2, y2, xwmin, ywmin, xwmax, ywmax);
    getch();
    closegraph();
    return 0;
}