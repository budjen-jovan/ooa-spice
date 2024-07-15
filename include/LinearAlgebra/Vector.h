#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iomanip> // for std::setw
#include <iostream>
#include <vector>

class Vector {
public:
  Vector(int size);
  Vector(const std::vector<double> &elements);
  static Vector getRandVector(int n);
  static Vector getRandVector(int n, double min, double max);
  static Vector getZeroVector(int n);
  static Vector getOnesVector(int n);

  double &operator[](int index);
  const double &operator[](int index) const;

  int size() const;

  void print() const;
  void row_print() const;

  Vector operator+(const Vector &other) const;
  Vector operator-(const Vector &other) const;
  Vector operator*(double scalar) const;
  Vector operator/(double scalar) const;

  double norm() const;

  friend Vector operator*(double scalar, const Vector &vector);

private:
  std::vector<double> elements;
};

#endif // VECTOR_H
