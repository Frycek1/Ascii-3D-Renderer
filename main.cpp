#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <thread>
#include <chrono>
#include "Matrix.h"
#include "MatrixTransformations.h"
#include "Renderer3D.h"

using namespace  std;

int main() {
    std::vector<Point3> cube_points{
        Point3(-7.5, -7.5, -7.5), Point3(-7.5, 7.5, -7.5), Point3(7.5, -7.5, -7.5),
        Point3(7.5, 7.5, -7.5), Point3(-7.5, -7.5, 7.5), Point3(-7.5, 7.5, 7.5),
        Point3(7.5, -7.5, 7.5), Point3(7.5, 7.5, 7.5)
    };
    std::vector<Edge> cube_edges{
        Edge(0, 1), Edge(0, 2), Edge(0, 4), Edge(1, 3), Edge(1, 5),
        Edge(2, 3), Edge(2, 6), Edge(3, 7), Edge(4, 5), Edge(4, 6),
        Edge(5, 7), Edge(6, 7)
    };
    shape3D cube(cube_points, cube_edges);

    std::vector<Point3> tetrahedron_points {
        Point3(-3.75, -3.75, -3.75),
        Point3(11.25, -3.75, -3.75),
        Point3(-3.75, 11.25, -3.75),
        Point3(-3.75, -3.75, 11.25)
    };

    std::vector<Edge> tetrahedron_edges {
        Edge(0, 1), Edge(0, 2), Edge(0, 3),
        Edge(1, 2), Edge(1, 3), Edge(2, 3)
    };
    shape3D tetrahedron(tetrahedron_points, tetrahedron_edges);

    Renderer3D renderer;
    renderer.render(std::vector<shape3D>{tetrahedron, cube});

    system("pause");
    return 0;
}
