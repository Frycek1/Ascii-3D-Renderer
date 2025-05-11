//
// Created by wolny on 08.05.2025.
//

#ifndef SHAPE3D_H
#define SHAPE3D_H
#include <vector>

#include "AsciiCanvas.h"


struct Point3 {
    double x;
    double y;
    double z;
};
struct Edge {
    int a;
    int b;
};


class shape3D {
public:
    std::vector<Point3> points;
    std::vector<Edge> edges;
    shape3D(std::vector<Point3> points, std::vector<Edge> edges);
};



#endif //SHAPE3D_H
