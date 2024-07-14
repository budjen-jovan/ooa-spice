#ifndef VECTOR_H
#define VECTOR_H

#include <iomanip> // for std::setw
#include <iostream>
#include <vector>

class Vector {
public:
  Vector(int size);
  Vector(const std::vector<double> &elements);

  double &operator[](int index);
  const double &operator[](int index) const;

  int size() const;
  
  void print() const;
  void row_print() const;

private:
  std::vector<double> elements;
};

#endif // VECTOR_H

