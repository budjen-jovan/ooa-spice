#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <initializer_list>

template <typename T> class Vector {
private:
  std::vector<T> elements;

public:
  // Constructors
  Vector(size_t size); // Constructor with size
  Vector(std::initializer_list<T> init); // Constructor with initializer list

  // Accessors
  T &operator[](size_t idx);             // Mutable access to elements
  const T &operator[](size_t idx) const; // Immutable access to elements

  size_t size() const; // Return size of vector
  
  // Print utility
  void print() const;
};

#endif // VECTOR_H
