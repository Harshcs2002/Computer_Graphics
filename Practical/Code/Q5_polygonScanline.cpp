// Write a program to fill a polygon using Scan line fill algorithm.

#include <graphics.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;

void polygonScanline(int n, int x[], int y[])
{
    int i, j, k, ymax = 0, ymin = 480, x1, y1, x2, y2, temp, flag = 0;
    float m[20], xi[20];

    for (i = 0; i < n; i++)
    {
        if (y[i] > ymax)
            ymax = y[i];
        if (y[i] < ymin)
            ymin = y[i];
    }

    for (i = 0; i < n; i++)
    {
        j = (i + 1) % n;
        x1 = x[i];
        y1 = y[i];
        x2 = x[j];
        y2 = y[j];

        if (y2 != y1)
            m[i] = (float)(x2 - x1) / (y2 - y1);
        else
            m[i] = 0;
    }

    for (i = ymin; i <= ymax; i++)
    {
        k = 0;
        for (j = 0; j < n; j++)
        {
            if (((y[j] <= i) && (y[j + 1] > i)) || ((y[j] > i) && (y[j + 1] <= i)))
            {
                xi[k] = x[j] + m[j] * (i - y[j]);
                k++;
            }
        }

        for (j = 0; j < k - 1; j++)
        {
            for (int l = 0; l < k - j - 1; l++)
            {
                if (xi[l] > xi[l + 1])
                {
                    temp = xi[l];
                    xi[l] = xi[l + 1];
                    xi[l + 1] = temp;
                }
            }
        }

        setcolor(RED);
        for (j = 0; j < k; j += 2)
        {
            line(xi[j], i, xi[j + 1] + 1, i);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    int n, x[20], y[20];

    cout << "---Polygon Scanline---" << endl;
    cout << "Enter number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Point " << i + 1 << " (x, y): ";
        cin >> x[i] >> y[i];
    }

    polygonScanline(n, x, y);

    getch();
    closegraph();
    return 0;
}