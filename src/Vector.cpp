#include "../include/Vector.h"

Vector::Vector(int size) : elements(size) {}

Vector::Vector(const std::vector<double> &elements) : elements(elements) {}

double &Vector::operator[](int index) { return elements[index]; }

const double &Vector::operator[](int index) const { return elements[index]; }

int Vector::size() const { return elements.size(); }

void Vector::row_print() const {
  int max_width = 0;
  for (const auto &elem : elements) {
    int width = std::to_string(elem).length();
    if (width > max_width) {
      max_width = width;
    }
  }

  std::cout << "[ ";
  for (size_t i = 0; i < elements.size(); ++i) {
    std::cout << std::setw(max_width) << elements[i];
    if (i != elements.size() - 1) {
      std::cout << " ";
    }
  }
  std::cout << " ]";
}

void Vector::print() const {
  // Find the maximum number of digits for formatting
  int max_digits = 1; // Minimum of 1 digit assumed
  for (size_t i = 0; i < elements.size(); ++i) {
    std::ostringstream oss;
    oss << elements[i];
    int digits = oss.str().length();
    if (digits > max_digits) {
      max_digits = digits;
    }
  }

  // Print each element in a column format
  for (size_t i = 0; i < elements.size(); ++i) {
    std::cout << "[ " << std::setw(max_digits) << elements[i] << " ]"
              << std::endl;
  }
}
