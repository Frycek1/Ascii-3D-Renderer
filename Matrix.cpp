#include "Matrix.h"

#include <ostream>
#include <stdexcept>
#include <stdio.h>
#include "Matrix.h"
using namespace std;

template <typename T>
Matrix<T>::Matrix(int rows, int cols, const T& initial_value) {
    if (rows < 1 || cols < 1) {
        throw std::invalid_argument("Matrix size must be positive");
    }
    this->num_rows_ = rows;
    this->num_cols_ = cols;
    data_.resize(rows);
    for (int i = 0; i < rows; i++) {
        data_[i].resize(cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->data_[i][j] = initial_value;
        }
    }
}

template<typename T>
int Matrix<T>::size(int dim) const{
    if(dim == 0)
        return num_rows_;
    if(dim == 1)
        return num_cols_;

    throw std::invalid_argument("Dimension must be 0 or 1");
}



template <typename T>
T& Matrix<T>::operator()(int row, int col) {
    if (row < 0 || col < 0 || row >= this->num_rows_ || col >= this->num_cols_) {
        throw std::invalid_argument("Matrix index out of range");
    }
    return this->data_[row][col];
}

template<typename T>
const T & Matrix<T>::operator()(int row, int col) const {
    if (row < 0 || col < 0 || row >= this->num_rows_ || col >= this->num_cols_) {
        throw std::invalid_argument("Matrix index out of range");
    }
    return this->data_[row][col];
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T& value) const{
    Matrix<T> result(this->size(0), this->size(1));
    for (int i = 0; i < this->num_rows_; i++) {
        for (int j = 0; j < this->num_cols_; j++) {
            result(i, j) = this->data_[i][j] + value;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T& value) const{
    Matrix<T> result(this->size(0), this->size(1));
    for (int i = 0; i < this->num_rows_; i++) {
        for (int j = 0; j < this->num_cols_; j++) {
            result(i, j) = this->data_[i][j] - value;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &value) const {
    Matrix<T> result(this->size(0), this->size(1));
    for (int i = 0; i < this->num_rows_; i++) {
        for (int j = 0; j < this->num_cols_; j++) {
            result(i, j) = this->data_[i][j] * value;
        }
    }
    return result;
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &other) const {
    if (this->size(0) != other.size(0) || this->size(1) != other.size(1)) {
        throw std::invalid_argument("Matrix dimension mismatch");
    }

    Matrix<T> result(this->size(0), this->size(1));
    for (int i = 0; i < this->size(0); i++) {
        for (int j = 0; j < this->size(1); j++) {
            result(i, j) = this->data_[i][j] + other(i, j);
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
    int rowsA = this->num_rows_;
    int colsA = this->num_cols_;
    int rowsB = other.size(0);
    int colsB = other.size(1);

    if (colsA != rowsB) {
        throw std::invalid_argument("Matrix dimension mismatch for multiplication (colsA != rowsB)");
    }

    Matrix<T> result(rowsA, colsB);

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            T sum = T();
            for (int k = 0; k < colsA; ++k) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix &other) {
    if (this == &other)
        return *this;
    this->num_rows_ = other.num_rows_;
    this->num_cols_ = other.num_cols_;
    this->data_ = other.data_;

    return *this;
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;


