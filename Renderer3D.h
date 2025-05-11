//
// Created by wolny on 08.05.2025.
//

#ifndef RENDERER3D_H
#define RENDERER3D_H
#include "shape3D.h"


class Renderer3D {
public:
    void render(std::vector<shape3D> shapes);
private:
    AsciiCanvas canvas_ = AsciiCanvas();
    double focus_dist = 100;
    void rotateX(shape3D& shape, double angle);
    void rotateY(shape3D& shape, double angle);
    void rotateZ(shape3D& shape, double angle);
    Point2 screen_projection(Point3 point);
};



#endif //RENDERER3D_H
