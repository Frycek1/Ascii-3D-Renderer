//
// Created by wolny on 06.05.2025.
//

#include "AsciiCanvas.h"
#include "ConsoleUtils.h"
#include <iostream>



AsciiCanvas::AsciiCanvas() {
    ConsoleUtils::ShowConsoleCursor(false);
}

void AsciiCanvas::Clear() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            screen[x][y] = ' ';
        }
    }
}

void AsciiCanvas::Draw() {
    ConsoleUtils::setCursorPos(0, 0);
    std::string buffer = "";
    buffer.reserve((width + 1) * height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            buffer += screen[x][y];
        }
        buffer += '\n';
    }
    std::cout << buffer;
}

void AsciiCanvas::Line(Point2 a, Point2 b) {
    int xa = a.x;
    int ya = a.y;
    int xb = b.x;
    int yb = b.y;

    int dx = xb - xa;
    int dy = yb - ya;
    int stepX = (dx > 0) ? 1 : -1;
    int stepY = (dy > 0) ? 1 : -1;
    int absDx = abs(dx);
    int absDy = abs(dy);

    int currentX = xa;
    int currentY = ya;

    screen[currentX][currentY] = 'x';
    if (absDx > absDy) {
        int error = 2 * absDy - absDx;

        for (int i = 0; i < absDx; ++i) {
            currentX += stepX;

            if (error < 0) {
                error += 2 * absDy;
            } else {
                currentY += stepY;
                error += 2 * absDy - 2 * absDx;
            }
            screen[currentX][currentY] = 'x';
        }
    } else {
        int error = 2 * absDx - absDy;
        for (int i = 0; i < absDy; ++i) {
            currentY += stepY;
            if (error < 0) {
                error += 2 * absDx;
            } else {
                currentX += stepX;
                error += 2 * absDx - 2 * absDy;
            }
            screen[currentX][currentY] = 'x';
        }
    }

}

void AsciiCanvas::Circle(Point2 p, int radius) {

}
