#include "../include/Matrix.h"

Matrix::Matrix(int rows, int cols) : elements(rows, Vector(cols)) {}

Matrix::Matrix(const std::vector<std::vector<double>> &elements) {
  for (const auto &row : elements) {
    this->elements.push_back(Vector(row));
  }
}

Vector &Matrix::operator[](int index) { return elements[index]; }

const Vector &Matrix::operator[](int index) const { return elements[index]; }

int Matrix::rows() const { return elements.size(); }

int Matrix::cols() const { return elements.empty() ? 0 : elements[0].size(); }

void Matrix::print() const {
  // Find maximum number of digits for formatting each column
  std::vector<int> max_digits(cols(), 1); // Minimum of 1 digit assumed
  for (const auto &vec : elements) {
    for (int j = 0; j < cols(); ++j) {
      std::ostringstream oss;
      oss << vec[j];
      int digits = oss.str().length();
      if (digits > max_digits[j]) {
        max_digits[j] = digits;
      }
    }
  }

  // Print the matrix with dynamically adjusted widths
  for (const auto &vec : elements) {
    std::cout << "[ ";
    for (int j = 0; j < cols(); ++j) {
      if (j == 0) {
        std::cout << std::setw(max_digits[j]) << vec[j];
      } else {
        std::cout << " " << std::setw(max_digits[j]) << vec[j];
      }
    }
    std::cout << " ]" << std::endl;
  }
}
