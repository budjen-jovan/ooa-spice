#ifndef MATRIX_H
#define MATRIX_H

#include "Utils.h"
#include "Vector.h"
#include <cmath>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class Matrix {
private:
  std::vector<Vector<T>> rows;

public:
  // Constructors
  Matrix(size_t numRows, size_t numCols);
  Matrix(std::initializer_list<std::initializer_list<T>> init);

  // Special matrices
  static Matrix<T> eye(size_t size);
  static Matrix<T> zeros(size_t numRows, size_t numCols);
  static Matrix<T> ones(size_t numRows, size_t numCols);

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

  // Row operations
  void swapRows(size_t row1, size_t row2);
  void scaleRow(size_t row, T scalar);
  void addScaledRow(size_t targetRow, size_t sourceRow, T scalar);

  // Substitution methods
  Vector<T> forwardSubstitution(const Vector<T> &b, const Matrix<T> &L) const;
  Vector<T> backwardSubstitution(const Vector<T> &y, const Matrix<T> &U) const;

  // RREF
  Matrix<T> rref() const;
  void toRREF();

  // Rank
  size_t rank() const;

  // Print utility
  void print() const;
};

#endif // MATRIX_H
