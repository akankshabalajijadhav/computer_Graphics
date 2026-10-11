#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
using namespace std;
 
struct Point {
    int x, y;
};
 
// Draw a triangle from 3 points
void drawObject(Point p[]) {
    line(p[0].x, p[0].y, p[1].x, p[1].y);
    line(p[1].x, p[1].y, p[2].x, p[2].y);
    line(p[2].x, p[2].y, p[0].x, p[0].y);
}
 
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
 
    Point p[3] = {{200, 200}, {250, 300}, {150, 300}};
    setcolor(WHITE);
    drawObject(p); // Original triangle
 
    int choice;
    cout << "Choose Transformation:\n1. Translation\n2. Scaling\n3. Rotation\n4. Shearing\n";
    cin >> choice;
 
    Point q[3]; // transformed object
 
    if (choice == 1) {
        int tx, ty;
        cout << "Enter tx, ty: ";
        cin >> tx >> ty;
        for (int i = 0; i < 3; i++) {
            q[i].x = p[i].x + tx;
            q[i].y = p[i].y + ty;
        }
    }
    else if (choice == 2) {
        float sx, sy;
        cout << "Enter sx, sy: ";
        cin >> sx >> sy;
        for (int i = 0; i < 3; i++) {
            q[i].x = p[i].x * sx;
            q[i].y = p[i].y * sy;
        }
    }
    else if (choice == 3) {
        float angle;
        cout << "Enter rotation angle (in degrees): ";
        cin >> angle;
        angle = angle * 3.14159 / 180; // convert to radians
        for (int i = 0; i < 3; i++) {
            q[i].x = round(p[i].x * cos(angle) - p[i].y * sin(angle));
            q[i].y = round(p[i].x * sin(angle) + p[i].y * cos(angle));
        }
    }
    else if (choice == 4) {
        float shx, shy;
        cout << "Enter shear factors shx, shy: ";
        cin >> shx >> shy;
        for (int i = 0; i < 3; i++) {
            q[i].x = p[i].x + shx * p[i].y;
            q[i].y = p[i].y + shy * p[i].x;
        }
    }
 
    setcolor(YELLOW);
    drawObject(q); // Transformed triangle
 
    getch();
    closegraph();
    return 0;
}
