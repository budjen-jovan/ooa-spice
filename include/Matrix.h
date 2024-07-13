#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <cmath>
#include <initializer_list>

template <typename T> class Matrix {
private:
  std::vector<Vector<T>> rows;

public:
  // Constructors
  Matrix(size_t numRows, size_t numCols);
  Matrix(std::initializer_list<std::initializer_list<T>> init);

  // Accessors
  size_t numRows() const;
  size_t numCols() const;

  const Vector<T> &operator[](size_t idx) const; // Immutable access to rows
  Vector<T> &operator[](size_t idx);             // Mutable access to rows
  T operator()(size_t row, size_t col) const;    // Access individual elements

  // Matrix operations
  Matrix<T> operator*(const T &scalar) const; // Scalar multiplication
  Vector<T>
  operator*(const Vector<T> &vec) const; // Matrix-vector multiplication
  Matrix<T>
  operator*(const Matrix<T> &other) const; // Matrix-matrix multiplication

  // Print utility
  void print() const;
};

#endif // MATRIX_H