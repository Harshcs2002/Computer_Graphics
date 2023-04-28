#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;

void draw_Polygon(int n, int *drawPolygon)
{
    setcolor(MAGENTA);
    drawpoly(n + 1, drawPolygon);
}

void drawLine(int x1, int y1, int x2, int y2)
{
    setcolor(GREEN);
    line(x1, y1, x2, y2);
}

void translate(int n, int *drawPolygon, int tx, int ty)
{

    int i, j;
    int newPolygon[100];
    int T[3][3] = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
    for (i = 0, j = 0; i < n; i++)
    {
        int v[3] = {drawPolygon[i * 2], drawPolygon[i * 2 + 1], 1};
        int v_out[3] = {0, 0, 0};
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 3; l++)
            {
                v_out[k] += T[k][l] * v[l];
            }
        }
        newPolygon[j++] = v_out[0];
        newPolygon[j++] = v_out[1];
    }
    newPolygon[j++] = newPolygon[0];
    newPolygon[j] = newPolygon[1];
    setcolor(RED);
    drawpoly(n + 1, newPolygon);
}

void scale(int n, int *drawPolygon, int sx, int sy)
{
    int i, j;
    int newPolygon[100];
    for (i = 0, j = 0; i < n; i++)
    {
        newPolygon[j++] = drawPolygon[i * 2] * sx;
        newPolygon[j++] = drawPolygon[i * 2 + 1] * sy;
    }
    newPolygon[j++] = newPolygon[0];
    newPolygon[j] = newPolygon[1];
    int tfx = (-sx + 1) * drawPolygon[0], tfy = (-sy + 1) * drawPolygon[1];
    translate(n, newPolygon, tfx, tfy);
}
void rotate(int n, int *drawPolygon, int angle)
{
    int i, j;
    int newPolygon[100];
    for (i = 0, j = 0; i < n; i++)
    {
        newPolygon[j++] = drawPolygon[i * 2] * cos(angle * 3.14 / 180) - drawPolygon[i * 2 + 1] * sin(angle * 3.14 / 180);
        newPolygon[j++] = drawPolygon[i * 2] * sin(angle * 3.14 / 180) + drawPolygon[i * 2 + 1] * cos(angle * 3.14 / 180);
    }
    newPolygon[j++] = newPolygon[0];
    newPolygon[j] = newPolygon[1];
    int tfx = drawPolygon[0] - newPolygon[0];
    int tfy = drawPolygon[1] - newPolygon[1];
    translate(n, newPolygon, tfx, tfy);
}

void shear(int n, int *drawPolygon, int shx, int shy)
{
    int i, j;
    int newPolygon[100];
    for (i = 0, j = 0; i < n; i++)
    {
        newPolygon[j++] = drawPolygon[i * 2] + shx * drawPolygon[i * 2 + 1];
        newPolygon[j++] = drawPolygon[i * 2 + 1] + shy * drawPolygon[i * 2];
    }
    newPolygon[j++] = newPolygon[0];
    newPolygon[j] = newPolygon[1];
    setcolor(RED);
    drawpoly(n + 1, newPolygon);
}

void reflect(int n, int *drawPolygon)
{
    int i, j;
    int newPolygon[2 * n + 2];
    int x = getmaxx();
    for (i = 0; i < 2 * n + 2; i++)
    {
        if (i % 2 == 0)
        {
            newPolygon[i] = x - drawPolygon[i];
        }
        else
        {
            newPolygon[i] = drawPolygon[i];
        }
    }
    setcolor(RED);
    drawpoly(n + 1, newPolygon);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    int n, i, j, k, tx, ty, sx, sy, angle, shx, shy, x1, y1, x2, y2;
    int drawPolygon[100];
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the vertices: ";
    for (i = 0, j = 0; i < n; i++)
    {
        cin >> drawPolygon[j++] >> drawPolygon[j++];
    }
    drawPolygon[j++] = drawPolygon[0];
    drawPolygon[j] = drawPolygon[1];
    draw_Polygon(n, drawPolygon);
    do
    {
        cout << "1. Translation \t 2. Scaling \t 3. Rotation \t 4. Shearing \t 5. Reflection \t 6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> k;
        cleardevice();
        draw_Polygon(n, drawPolygon);
        switch (k)
        {

        case 1:
            cout << "Enter the translation factor: ";
            cin >> tx >> ty;
            translate(n, drawPolygon, tx, ty);
            break;
        case 2:
            cout << "Enter the scaling factor: ";
            cin >> sx >> sy;
            scale(n, drawPolygon, sx, sy);
            break;
        case 3:
            cout << "Enter the angle of rotation: ";
            cin >> angle;
            rotate(n, drawPolygon, angle);
            break;
        case 4:
            cout << "Enter the shearing factor: ";
            cin >> shx >> shy;
            shear(n, drawPolygon, shx, shy);
            break;
        case 5:
            x1 = getmaxx() / 2;
            y1 = 0, y2 = getmaxy();
            drawLine(x1, y1, x1, y2);
            reflect(n, drawPolygon);
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (k != 6);

    getch();
    closegraph();
    return 0;
}
