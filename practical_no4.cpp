#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;
 
// Function to draw Equilateral Triangle
void drawTriangle(int x[3], int y[3], int color) {
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
}
 
// Function to draw Rhombus
void drawRhombus(int x[4], int y[4], int color) {
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
}
 
// Translation
void translation(int x[], int y[], int n, int tx, int ty) {
    for (int i = 0; i < n; i++) {
        x[i] = x[i] + tx;
        y[i] = y[i] + ty;
    }
}
 
// Scaling
void scaling(int x[], int y[], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        x[i] = x[i] * sx;
        y[i] = y[i] * sy;
    }
}
 
// Rotation
void rotation(int x[], int y[], int n, float angle) {
    float rad = angle * 3.14159 / 180; // convert to radians
    for (int i = 0; i < n; i++) {
        int tempX = x[i];
        int tempY = y[i];
        x[i] = tempX * cos(rad) - tempY * sin(rad);
        y[i] = tempX * sin(rad) + tempY * cos(rad);
    }
}
 
// Shearing
void shearing(int x[], int y[], int n, float shx, float shy) {
    for (int i = 0; i < n; i++) {
        int tempX = x[i];
        x[i] = x[i] + shx * y[i];
        y[i] = y[i] + shy * tempX;
    }
}
 
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
 
    int choice, transformChoice;
    cout << "Choose Object:\n1. Equilateral Triangle\n2. Rhombus\nEnter choice: ";
    cin >> choice;
 
    // Coordinates
    int x[4], y[4], n;
 
    if (choice == 1) {
        // Equilateral Triangle (side 100px)
        x[0] = 200; y[0] = 200;
        x[1] = 300; y[1] = 200;
        x[2] = 250; y[2] = 120;
        n = 3;
        drawTriangle(x, y, WHITE);
    } else {
        // Rhombus
        x[0] = 200; y[0] = 200;
        x[1] = 250; y[1] = 150;
        x[2] = 300; y[2] = 200;
        x[3] = 250; y[3] = 250;
        n = 4;
        drawRhombus(x, y, WHITE);
    }
 
    cout << "\nChoose Transformation:\n1. Translation\n2. Scaling\n3. Rotation\n4. Shearing\nEnter choice: ";
    cin >> transformChoice;
 
    switch (transformChoice) {
        case 1: {
            int tx, ty;
            cout << "Enter tx, ty: ";
            cin >> tx >> ty;
            translation(x, y, n, tx, ty);
            break;
        }
        case 2: {
            float sx, sy;
            cout << "Enter sx, sy: ";
            cin >> sx >> sy;
            scaling(x, y, n, sx, sy);
            break;
        }
        case 3: {
            float angle;
            cout << "Enter angle (in degrees): ";
            cin >> angle;
            rotation(x, y, n, angle);
            break;
        }
        case 4: {
            float shx, shy;
            cout << "Enter shx, shy: ";
            cin >> shx >> shy;
            shearing(x, y, n, shx, shy);
            break;
        }
        default:
            cout << "Invalid Choice!";
    }
 
    // Draw transformed object in YELLOW
    if (choice == 1) {
        drawTriangle(x, y, YELLOW);
    } else {
        drawRhombus(x, y, YELLOW);
    }
 
    getch();
    closegraph();
    return 0;
}
