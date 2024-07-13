#include "../include/Vector.h"

// Constructors
template <typename T> Vector<T>::Vector(size_t size) : elements(size) {}
template <typename T> Vector<T>::Vector(std::initializer_list<T> init) : elements(init) {}

// Get mutable access to elements
template <typename T> T &Vector<T>::operator[](size_t idx) {
  if (idx >= elements.size()) {
    throw std::out_of_range("Vector index out of range");
  }
  return elements[idx];
}

// Get immutable access to elements
template <typename T> const T &Vector<T>::operator[](size_t idx) const {
  if (idx >= elements.size()) {
    throw std::out_of_range("Vector index out of range");
  }
  return elements[idx];
}

// Get vector size
template <typename T> size_t Vector<T>::size() const { return elements.size(); }

// Pretty print vector
template <typename T> void Vector<T>::print() const {
  // Determine maximum width based on the largest element
  int max_width = 0;
  for (size_t i = 0; i < elements.size(); ++i) {
    int digits = elements[i] == 0 ? 1 : static_cast<int>(std::log10(std::abs(elements[i]))) + 1;
    if (digits > max_width) {
      max_width = digits;
    }
  }

  // Print elements in a column
  for (size_t i = 0; i < elements.size(); ++i) {
    std::cout << "[ " << std::setw(max_width) << elements[i] << " ]\n";
  }
}

// Vector operations
// Vector addition
template <typename T> Vector<T> Vector<T>::operator+(const Vector<T> &other) const {
  if (elements.size() != other.size()) {
    throw std::invalid_argument("Vector sizes do not match");
  }

  Vector<T> result(elements.size());
  for (size_t i = 0; i < elements.size(); ++i) {
    result[i] = elements[i] + other[i];
  }
  return result;
}

// Vector subtraction
template <typename T> Vector<T> Vector<T>::operator-(const Vector<T> &other) const {
  if (elements.size() != other.size()) {
    throw std::invalid_argument("Vector sizes do not match");
  }

  Vector<T> result(elements.size());
  for (size_t i = 0; i < elements.size(); ++i) {
    result[i] = elements[i] - other[i];
  }
  return result;
}

// Vector dot product
template <typename T> T Vector<T>::operator*(const Vector<T> &other) const {
  if (elements.size() != other.size()) {
    throw std::invalid_argument("Vector sizes do not match");
  }

  T result = 0;
  for (size_t i = 0; i < elements.size(); ++i) {
    result += elements[i] * other[i];
  }
  return result;
}


template class Vector<int>;    // Explicit instantiation of Vector<int>
template class Vector<float>;  // Explicit instantiation of Vector<float>
template class Vector<double>; // Explicit instantiation of Vector<double>
