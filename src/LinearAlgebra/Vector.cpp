#include "../../include/LinearAlgebra/Vector.h"

Vector::Vector(int size) : elements(size) {}

Vector::Vector(const std::vector<double> &elements) : elements(elements) {}

Vector::Vector(std::initializer_list<double> list) : elements(list) {}

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
  for (unsigned long int i = 0; i < elements.size(); ++i) {
    std::cout << std::setw(max_width) << elements[i];
    if (i != elements.size() - 1) {
      std::cout << " ";
    }
  }
  std::cout << " ]";
}

// Friend function definition for scalar * vector
Vector operator*(double scalar, const Vector &vector) {
  Vector result(vector.size());
  for (int i = 0; i < vector.size(); ++i) {
    result[i] = scalar * vector[i];
  }
  return result;
}

void Vector::print() const {
  // Find the maximum number of digits for formatting
  int max_digits = 1; // Minimum of 1 digit assumed
  for (unsigned long int i = 0; i < elements.size(); ++i) {
    std::ostringstream oss;
    oss << elements[i];
    int digits = oss.str().length();
    if (digits > max_digits) {
      max_digits = digits;
    }
  }

  // Print each element in a column format
  for (unsigned long int i = 0; i < elements.size(); ++i) {
    std::cout << "[ " << std::setw(max_digits) << elements[i] << " ]"
              << std::endl;
  }
}

Vector Vector::operator+(const Vector &other) const {
  if (size() != other.size()) {
    throw std::invalid_argument(
        "Vectors must be of the same size for addition.");
  }

  Vector result(size());
  for (int i = 0; i < size(); ++i) {
    result[i] = elements[i] + other[i];
  }
  return result;
}

Vector Vector::operator-(const Vector &other) const {
  if (size() != other.size()) {
    throw std::invalid_argument(
        "Vectors must be of the same size for subtraction.");
  }

  Vector result(size());
  for (int i = 0; i < size(); ++i) {
    result[i] = elements[i] - other[i];
  }
  return result;
}

Vector Vector::operator*(double scalar) const {
  Vector result(size());
  for (int i = 0; i < size(); ++i) {
    result[i] = elements[i] * scalar;
  }
  return result;
}

Vector Vector::operator/(double scalar) const {
  Vector result(size());
  for (int i = 0; i < size(); ++i) {
    result[i] = elements[i] / scalar;
  }
  return result;
}

double Vector::norm() const {
  double norm = 0;
  for (int i = 0; i < size(); ++i) {
    norm += elements[i] * elements[i];
  }
  return std::sqrt(norm);
}

Vector Vector::getRandVector(int n) {
  Vector v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = static_cast<double>(rand()) / RAND_MAX;
  }
  return v;
}

Vector Vector::getRandVector(int n, double min, double max) {
  Vector v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = min + static_cast<double>(rand()) / RAND_MAX * (max - min);
  }
  return v;
}

Vector Vector::getZeroVector(int n) {
  Vector v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = 0;
  }
  return v;
}

Vector Vector::getOnesVector(int n) {
  Vector v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = 1;
  }
  return v;
}

double Vector::min() const {
  double min = elements[0];
  for (int i = 1; i < size(); ++i) {
    if (elements[i] < min) {
      min = elements[i];
    }
  }
  return min;
}

double Vector::max() const {
  double max = elements[0];
  for (int i = 1; i < size(); ++i) {
    if (elements[i] > max) {
      max = elements[i];
    }
  }
  return max;
}

Vector Vector::concatenate(const Vector &other) const {
  Vector result(size() + other.size());
  for (int i = 0; i < size(); ++i) {
    result[i] = elements[i];
  }
  for (int i = 0; i < other.size(); ++i) {
    result[i + size()] = other[i];
  }
  return result;
}
