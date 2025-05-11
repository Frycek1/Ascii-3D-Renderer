//
// Created by wolny on 08.05.2025.
//

#ifndef MATRIXTRANSFORMATIONS_H
#define MATRIXTRANSFORMATIONS_H

#include "Matrix.h"
#include <cmath>

namespace MatrixTransformations {
    template <typename T, typename U>
    Matrix<T> RotationX(U angle) {
        Matrix<T> rotationMatrix(3, 3);
        rotationMatrix(0, 0) = 1;
        rotationMatrix(1, 1) = cos(angle);
        rotationMatrix(1, 2) = -sin(angle);
        rotationMatrix(2, 1) = sin(angle);
        rotationMatrix(2, 2) = cos(angle);
        return rotationMatrix;
    }

    template <typename T, typename U>
    Matrix<T> RotationY(U angle) {
        Matrix<T> rotationMatrix(3, 3);
        rotationMatrix(0, 0) = cos(angle);
        rotationMatrix(0, 2) = sin(angle);
        rotationMatrix(1, 1) = 1;
        rotationMatrix(2, 0) = -sin(angle);
        rotationMatrix(2, 2) = cos(angle);
        return rotationMatrix;
    }

    template <typename T, typename U>
    Matrix<T> RotationZ(U angle) {
        Matrix<T> rotationMatrix(3, 3);
        rotationMatrix(0, 0) = cos(angle);
        rotationMatrix(0, 1) = -sin(angle);
        rotationMatrix(1, 0) = sin(angle);
        rotationMatrix(1, 1) = cos(angle);
        rotationMatrix(2, 2) = 1;
        return rotationMatrix;
    }
};



#endif //MATRIXTRANSFORMATIONS_H
