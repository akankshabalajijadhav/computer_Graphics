#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
 
void drawPolygon(int x[], int y[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}
 
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
 
    // Example: triangle
    int x[3] = {200, 250, 150};
    int y[3] = {200, 300, 300};
 
    // Draw original
    drawPolygon(x, y, 3, WHITE);
 
    cout << "Reflection Menu:\n";
    cout << "1. About X-axis\n2. About Y-axis\n3. About Origin\n";
    int choice;
    cin >> choice;
 
    int xr[3], yr[3];
    for (int i = 0; i < 3; i++) {
        if (choice == 1) {          // X-axis
            xr[i] = x[i];
            yr[i] = getmaxy() - y[i];
        } else if (choice == 2) {   // Y-axis
            xr[i] = getmaxx() - x[i];
            yr[i] = y[i];
        } else if (choice == 3) {   // Origin
            xr[i] = getmaxx() - x[i];
            yr[i] = getmaxy() - y[i];
        }
    }
 
    // Draw reflected
    drawPolygon(xr, yr, 3, YELLOW);
 
    getch();
    closegraph();
    return 0;
}
