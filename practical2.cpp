#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
using namespace std;
 
// Function to plot with styles
void plotCirclePoints(int xc, int yc, int x, int y, int style, int count) {
    // Style control
    bool draw = false;
    if (style == 1) draw = true;                              // Solid
    else if (style == 2 && count % 2 == 0) draw = true;       // Dotted
    else if (style == 3 && (count / 5) % 2 == 0) draw = true; // Dashed
 
    if (draw) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}
 
// DDA Circle
void DDA_Circle(int xc, int yc, int r, int style) {
    int steps = 360;
    for (int i = 0; i < steps; i++) {
        float theta = i * 3.14159 / 180; // convert to rad
        int x = round(r * cos(theta));
        int y = round(r * sin(theta));
        plotCirclePoints(xc, yc, x, y, style, i);
    }
}
 
// Bresenham Circle
void Bresenham_Circle(int xc, int yc, int r, int style) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    int count = 0;
    while (y >= x) {
        plotCirclePoints(xc, yc, x, y, style, count++);
        x++;
        if (d < 0) d = d + 4 * x + 6;
        else {
            y--;
            d = d + 4 * (x - y) + 10;
        }
    }
}
 
// Midpoint Circle
void Midpoint_Circle(int xc, int yc, int r, int style) {
    int x = 0, y = r;
    int p = 1 - r;
    int count = 0;
    while (x <= y) {
        plotCirclePoints(xc, yc, x, y, style, count++);
        x++;
if (p < 0) p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}
 
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
 
    int xc, yc, r, choice, style;
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;
 
    cout << "Choose Algorithm:\n1. DDA\n2. Bresenham\n3. Midpoint\n";
    cin >> choice;
    cout << "Choose Style:\n1. Solid\n2. Dotted\n3. Dashed\n";
    cin >> style;
 
    if (choice == 1) DDA_Circle(xc, yc, r, style);
    else if (choice == 2) Bresenham_Circle(xc, yc, r, style);
    else if (choice == 3) Midpoint_Circle(xc, yc, r, style);
    else cout << "Invalid choice!";
 
    getch();
    closegraph();
    return 0;
}
