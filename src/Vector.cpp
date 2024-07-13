#include "../include/Vector.h"

template <typename T> Vector<T>::Vector(size_t size) : elements(size) {}

template <typename T> Vector<T>::Vector(std::initializer_list<T> init) : elements(init) {}





template <typename T> T &Vector<T>::operator[](size_t idx) {
  if (idx >= elements.size()) {
    throw std::out_of_range("Vector index out of range");
  }
  return elements[idx];
}

template <typename T> const T &Vector<T>::operator[](size_t idx) const {
  if (idx >= elements.size()) {
    throw std::out_of_range("Vector index out of range");
  }
  return elements[idx];
}

template <typename T> size_t Vector<T>::size() const { return elements.size(); }

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
template class Vector<int>;    // Explicit instantiation of Vector<int>
template class Vector<float>;  // Explicit instantiation of Vector<float>
template class Vector<double>; // Explicit instantiation of Vector<double>
