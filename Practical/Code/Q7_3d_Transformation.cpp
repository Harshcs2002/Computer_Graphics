#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <graphics.h>
using namespace std;

int s=1;

double x1, x2, y2;

void draw_cube(double edge[20][4])
{
  double y1;
  int i;
  clearviewport();
  for (i = 0; i < 19; i++)
  {
    x1 = edge[i][0] + edge[i][2] * (cos(2.3562));
    y1 = edge[i][1] - edge[i][2] * (sin(2.3562));
    x2 = edge[i + 1][0] + edge[i + 1][2] * (cos(2.3562));
    y2 = edge[i + 1][1] - edge[i + 1][2] * (sin(2.3562));
    line(x1 + 320, 240 - y1, x2 + 320, 240 - y2);
  }
  line(320, 240, 320, 25);
  line(320, 240, 550, 240);
  line(320, 240, 150, 410);
}
void scale(double edge[20][4])
{
  double a, b, c;
  int i;
  cout << "Enter The Scaling Factors: ";
  cin >> a >> b >> c;
  clearviewport();
  double scaleMat[4][4] = {
    {a, 0, 0, 0},
    {0, b, 0, 0},
    {0, 0, c, 0},
    {0, 0, 0, 1}
  };
  for (i = 0; i < 20; i++)
  {
    double tempVec[4] = {edge[i][0], edge[i][1], edge[i][2], edge[i][3]};
    for(int j=0; j<4; j++){
      edge[i][j] = 0;
      for(int k=0; k<4; k++){
        edge[i][j] += tempVec[k]*scaleMat[j][k];
      }
    }
  }
  draw_cube(edge);
}

void translate(double edge[20][4])
{
  double Tx, Ty, Tz;
  int i;
  cout << "Enter The Translation Factors: ";
  cin >> Tx >> Ty >> Tz;
  clearviewport();
  double transMat[4][4] = {
    {1, 0, 0, Tx},
    {0, 1, 0, Ty},
    {0, 0, 1, Tz},
    {0, 0, 0, 1}
  };
  for (i = 0; i < 20; i++)
  {
    double tempVec[4] = {edge[i][0], edge[i][1], edge[i][2], 1};
    for(int j=0; j<4; j++){
      edge[i][j] = 0;
      for(int k=0; k<4; k++){
        edge[i][j] += tempVec[k]*transMat[j][k];
      }
    }
  }
  draw_cube(edge);
}

void matrixMult(double edge[20][4], double mat[4][4])
{
  double res[20][4];
  int i, j, k;
  for (i = 0; i < 20; i++)
  {
    for (j = 0; j < 4; j++)
    {
      res[i][j] = 0;
      for (k = 0; k < 4; k++)
      {
        res[i][j] += edge[i][k] * mat[k][j];
      }
    }
  }
  for (i = 0; i < 20; i++)
  {
    for (j = 0; j < 4; j++)
    {
      edge[i][j] = res[i][j];
    }
  }
}
void rotateX(double edge[20][4], double angle)
{
  double c = cos(angle);
  double s = sin(angle);
  double rot_mat[4][4] = {{1, 0, 0, 0},
                          {0, c, -s, 0},
                          {0, s, c, 0},
                          {0, 0, 0, 1}};
  matrixMult(edge, rot_mat);
  draw_cube(edge);
}

void rotateY(double edge[20][4], double angle)
{
  double c = cos(angle);
  double s = sin(angle);
  double rot_mat[4][4] = {{c, 0, s, 0},
                          {0, 1, 0, 0},
                          {-s, 0, c, 0},
                          {0, 0, 0, 1}};
  matrixMult(edge, rot_mat);
  draw_cube(edge);
}

void rotateZ(double edge[20][4], double angle)
{
  double c = cos(angle);
  double s = sin(angle);
  double rot_mat[4][4] = {{c, -s, 0, 0},
                          {s, c, 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};
  matrixMult(edge, rot_mat);
  draw_cube(edge);
}

void rotate(double edge[20][4])
{
  int ch;
  double angle;
  cout << "-=[ Rotation About ]=-" << endl;
  cout << "1:==> X-Axis " << endl;
  cout << "2:==> Y-Axis" << endl;
  cout << "3:==> Z-Axis " << endl;
  cout << "Enter Your Choice: ";
  cin >> ch;

  switch (ch)
  {
  case 1:
    cout << "Enter The Angle (in degrees): ";
    cin >> angle;
    angle = (angle * M_PI) / 180; // Convert angle to radians
    rotateX(edge, angle);
    break;

  case 2:
    cout << "Enter The Angle (in degrees): ";
    cin >> angle;
    angle = (angle * M_PI) / 180; // Convert angle to radians
    rotateY(edge, angle);
    break;

  case 3:
    cout << "Enter The Angle (in degrees): ";
    cin >> angle;
    angle = (angle * M_PI) / 180; // Convert angle to radians
    rotateZ(edge, angle);
    break;

  default:
    cout << "Invalid Choice!" << endl;
    break;
  }
}

void reflect(double edge[20][4]) {
    int ch;
    cout << "-=[ Reflection About ]=-" << endl;
    cout << "1:==> X-Axis" << endl;
    cout << "2:==> Y-Axis " << endl;
    cout << "3:==> Z-Axis " << endl;
    cout << "Enter Your Choice: ";
    cin >> ch;

    double reflect_mat[4][4] = {{1, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}};

    switch (ch) {
        case 1:
            reflect_mat[1][1] = -1;
            reflect_mat[2][2] = -1;
            break;
        case 2:
            reflect_mat[0][0] = -1;
            reflect_mat[2][2] = -1;
            break;
        case 3:
            reflect_mat[0][0] = -1;
            reflect_mat[1][1] = -1;
            break;
        default:
            cout << "Invalid Choice. Reflection aborted." << endl;
            return;
    }

    matrixMult(edge, reflect_mat);
    draw_cube(edge);
}

void perspect(double edge[20][4]) {
  int ch;
  double p, q, r;

  cout << "-=[ Perspective Projection About ]=-" << endl;
  cout << "1:==> X-Axis " << endl;
  cout << "2:==> Y-Axis " << endl;
  cout << "3:==> Z-Axis" << endl;
  cout << "Enter Your Choice := ";
  cin >> ch;

  switch (ch) {
    case 1:
      cout << "Enter P := ";
      cin >> p;

      for (int i = 0; i < 20; i++) {
        double w = p * edge[i][0] + 1;
        double x = edge[i][0];
        double y = edge[i][1];
        double z = edge[i][2];

        edge[i][0] = x / w;
        edge[i][1] = y / w;
        edge[i][2] = z / w;
        edge[i][3] = 1.0 / w;
      }
      break;

    case 2:
      cout << "Enter Q := ";
      cin >> q;

      for (int i = 0; i < 20; i++) {
        double w = q * edge[i][1] + 1;
        double x = edge[i][0];
        double y = edge[i][1];
        double z = edge[i][2];

        edge[i][0] = x / w;
        edge[i][1] = y / w;
        edge[i][2] = z / w;
        edge[i][3] = 1.0 / w;
      }
      break;

    case 3:
      cout << "Enter R := ";
      cin >> r;

      for (int i = 0; i < 20; i++) {
        double w = r * edge[i][2] + 1;
        double x = edge[i][0];
        double y = edge[i][1];
        double z = edge[i][2];

        edge[i][0] = x / w;
        edge[i][1] = y / w;
        edge[i][2] = z / w;
        edge[i][3] = 1.0 / w;
      }
      break;
  }

  draw_cube(edge);
}

int main()
{
   int gm,gd = DETECT;
char data[] = "C:\\MinGW\\lib\\libbgi.a"; 
initgraph(&gd, &gm, data);
    int choice;
  double edge[20][4] = {
      100, 0, 0,1,
      100, 100, 0,1,
      0, 100, 0,1,
      0, 100, 100,1,
      0, 0, 100,1,
      0, 0, 0,1,
      100, 0, 0,1,
      100, 0, 100,1,
      100, 75, 100,1,
      75, 100, 100,1,
      100, 100, 75,1,
      100, 100, 0,1,
      100, 100, 75,1,
      100, 75, 100,1,
      75, 100, 100,1,
      0, 100, 100,1,
      0, 100, 0,1,
      0, 0, 0,1,
      0, 0, 100,1,
      100, 0, 100,1};
    while (s==1)
  {
    cout << "1:==> Draw Cube " << endl;
    cout << "2:==> Scaling " << endl;
    cout << "3:==> Rotation " << endl;
    cout << "4:==> Reflection " << endl;
    cout << "5:==> Translation " << endl;
    cout << "6:==> Perspective Projection " << endl;
    cout << "7:==> Exit " << endl;
    cout << "Enter Your Choice := ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      draw_cube(edge);
      break;

    case 2:
      scale(edge);
      break;

    case 3:
      rotate(edge);
      break;

    case 4:
      reflect(edge);
      break;

    case 5:
      translate(edge);
      break;

    case 6:
      perspect(edge);
      break;

    case 7:
       exit(0);
      break;

    default:
      cout << "\nPress A Valid Key...!!! ";
      break;
    }
  }
  getch();
  closegraph();
  return 0;
}