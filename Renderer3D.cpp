//
// Created by wolny on 08.05.2025.
//

#include "Renderer3D.h"

#include <thread>

#include "Matrix.h"
#include "MatrixTransformations.h"
#include "AsciiCanvas.h"
#include <random>


void Renderer3D::render(std::vector<shape3D> shapes) {
    int offset = 10;
    bool change_offset = true;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distrib_inclusive_upper(0.0, std::nextafter(0.3, std::numeric_limits<double>::max()));
    double random_num = distrib_inclusive_upper(gen);
    while(true) {
        canvas_.Clear();
        for(auto& shape : shapes) {

            if(change_offset) {
                offset = 10;
            }
            else {
                offset = 30;
            }
            random_num = distrib_inclusive_upper(gen);
            rotateY(shape, random_num);
            random_num = distrib_inclusive_upper(gen);
            rotateX(shape, random_num);
            random_num = distrib_inclusive_upper(gen);
            rotateZ(shape, random_num);

            for(auto& edge : shape.edges) {
                Point2 A = screen_projection(shape.points[edge.a]);
                Point2 B =  screen_projection(shape.points[edge.b]);
                A.x += offset; A.y += offset;
                B.x += offset; B.y += offset;
                canvas_.Line(A, B);
            }
            change_offset = !change_offset;
        }

        canvas_.Draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

void Renderer3D::rotateX(shape3D& shape, double angle) {
    Matrix<double> rotationMatrix = MatrixTransformations::RotationX<double>(angle);
    for(auto& point : shape.points) {
        point = point * rotationMatrix;
    }
}

void Renderer3D::rotateY(shape3D& shape, double angle) {
    Matrix<double> rotationMatrix = MatrixTransformations::RotationY<double>(angle);
    for(auto& point : shape.points) {
        point = point * rotationMatrix;
    }
}

void Renderer3D::rotateZ(shape3D& shape, double angle) {
    Matrix<double> rotationMatrix = MatrixTransformations::RotationZ<double>(angle);
    for(auto& point : shape.points) {
        point = point * rotationMatrix;
    }
}

Point2 Renderer3D::screen_projection(Point3 point) {
    Point2 result;

    result.x =(point.x * focus_dist) / (focus_dist + point.z);
    result.y =(point.y * focus_dist) / (focus_dist + point.z);


    return result;
}

