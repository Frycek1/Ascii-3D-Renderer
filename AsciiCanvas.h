//
// Created by wolny on 06.05.2025.
//

#ifndef ASCIICANVAS_H
#define ASCIICANVAS_H

struct Point2{
    double x;
    double y;
};

class AsciiCanvas {
private:
    static const int width = 100;
    static const int height = 60;
    char screen[width][height];

public:
    AsciiCanvas();
    void Clear();
    void Draw();
    void Line(Point2 a, Point2 b);
    void Circle(Point2 p, int radius);
};



#endif //ASCIICANVAS_H
