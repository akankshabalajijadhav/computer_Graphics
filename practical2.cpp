#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;
// Function to draw line using DDA with style
void DDA_Line(int x1, int y1, int x2, int y2, int style) {
 int dx = x2 - x1;
 int dy = y2 - y1;
 int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 float x_inc = dx / (float)steps;
 float y_inc = dy / (float)steps;
 float x = x1;
 float y = y1;
 for (int i = 0; i <= steps; i++) {
 // Line Style Control
 if (style == 1) { // Dotted
 if (i % 2 == 0)
 putpixel(round(x), round(y), WHITE);
 }
 else if (style == 2) { // Thick
 putpixel(round(x), round(y), WHITE);
 putpixel(round(x), round(y) + 1, WHITE); // e
 }
 else { // Normal
 putpixel(round(x), round(y), WHITE);
 }
 x += x_inc;
 y += y_inc;
 }
}
int main() {
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "");
 // Rectangle coordinates
 int x1 = 100, y1 = 100, x2 = 250, y2 = 200;
 // Draw rectangle with dotted lines
 DDA_Line(x1, y1, x2, y1, 1); // Top
 DDA_Line(x2, y1, x2, y2, 1); // Right
 DDA_Line(x2, y2, x1, y2, 1); // Bottom
 DDA_Line(x1, y2, x1, y1, 1); // Left
 // Draw another rectangle with thick lines
 int X1 = 300, Y1 = 100, X2 = 450, Y2 = 200;
 DDA_Line(X1, Y1, X2, Y1, 2);
 DDA_Line(X2, Y1, X2, Y2, 2);
 DDA_Line(X2, Y2, X1, Y2, 2);
 DDA_Line(X1, Y2, X1, Y1, 2);
 getch();
 closegraph();
 return 0;
}
