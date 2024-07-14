#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"
#include <iostream>
#include <vector>

class Matrix {
public:
  Matrix(int rows, int cols);
  Matrix(const std::vector<std::vector<double>> &elements);

  Vector &operator[](int index);
  const Vector &operator[](int index) const;

  int rows() const;
  int cols() const;
  void print() const;

private:
  std::vector<Vector> elements;
};

#endif // MATRIX_H

