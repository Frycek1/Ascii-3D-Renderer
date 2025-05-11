//
// Created by wolny on 08.05.2025.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <stdexcept>
#include <iostream>

#include "shape3D.h"

template <typename T>
class Matrix{
public:
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, const T& initial_value);

    int size(int dim) const;

    T& operator()(int row, int col);
    const T& operator()(int row, int col) const;

    Matrix operator+(const T& value) const;
    Matrix operator-(const T& value) const;
    Matrix operator*(const T& value) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix& operator=(const Matrix& other);
private:
    int num_rows_;
    int num_cols_;
    std::vector<std::vector<T>> data_;
};

template <typename T>
Matrix<T>::Matrix(int rows, int cols) : Matrix(rows, cols, T()) {}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.size(0); i++) {
        for (int j = 0; j < matrix.size(1); j++) {
            os << matrix(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}
template<typename T>
Matrix<T> operator+(const T &scalar, const Matrix<T> &matrix) {
    return matrix + scalar;
}

template<typename T>
Matrix<T> operator-(const T &scalar, const Matrix<T> &matrix) {

    return matrix - scalar;
}

template<typename T>
Point3 operator*(const Point3 point, const Matrix<T> &matrix ) {
    Point3 result;

    result.x = point.x * matrix(0,0) + point.y * matrix(1, 0) + point.z * matrix(2, 0);
    result.y = point.x * matrix(0,1) + point.y * matrix(1, 1) + point.z * matrix(2, 1);
    result.z = point.x * matrix(0,2) + point.y * matrix(1, 2) + point.z * matrix(2, 2);
    return result;
}
#endif //MATRIX_H
