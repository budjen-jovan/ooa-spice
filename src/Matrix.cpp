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

Matrix Matrix::operator+(const Matrix &other) const {
  if (rows() != other.rows() || cols() != other.cols()) {
    throw std::invalid_argument(
        "Matrices must be of the same size for addition.");
  }

  Matrix result(rows(), cols());
  for (int i = 0; i < rows(); ++i) {
    result[i] = elements[i] + other[i];
  }

  return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
  if (rows() != other.rows() || cols() != other.cols()) {
    throw std::invalid_argument(
        "Matrices must be of the same size for subtraction.");
  }

  Matrix result(rows(), cols());
  for (int i = 0; i < rows(); ++i) {
    result[i] = elements[i] - other[i];
  }

  return result;
}

Matrix Matrix::operator*(double scalar) const {
  Matrix result(rows(), cols());
  for (int i = 0; i < rows(); ++i) {
    result[i] = elements[i] * scalar;
  }

  return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
  if (cols() != other.rows()) {
    throw std::invalid_argument(
        "The number of columns in the first matrix must be equal to the number "
        "of rows in the second matrix for multiplication.");
  }

  Matrix result(rows(), other.cols());
  for (int i = 0; i < rows(); ++i) {
    for (int j = 0; j < other.cols(); ++j) {
      double sum = 0.0;
      for (int k = 0; k < cols(); ++k) {
        sum += elements[i][k] * other[k][j];
      }
      result[i][j] = sum;
    }
  }

  return result;
}

Vector Matrix::operator*(const Vector &vec) const {
  if (cols() != vec.size()) {
    throw std::invalid_argument(
        "The number of columns in the matrix must be equal to the size of the "
        "vector for multiplication.");
  }

  Vector result(rows());
  for (int i = 0; i < rows(); ++i) {
    double sum = 0.0;
    for (int j = 0; j < cols(); ++j) {
      sum += elements[i][j] * vec[j];
    }
    result[i] = sum;
  }

  return result;
}

Matrix operator*(double scalar, const Matrix &matrix) {
  return matrix * scalar;
}
