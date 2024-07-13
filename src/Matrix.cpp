#include "../include/Matrix.h"

// Explicit instantiations

template class Matrix<int>;    // Instantiate Matrix for int
template class Matrix<float>;  // Instantiate Matrix for float
template class Matrix<double>; // Instantiate Matrix for double

// Constructors
template <typename T>
Matrix<T>::Matrix(size_t numRows, size_t numCols)
    : rows(numRows, Vector<T>(numCols)) {}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init) {
  size_t numRows = init.size();
  size_t numCols = init.begin()->size();

  rows.reserve(numRows);

  for (const auto &rowList : init) {
    if (rowList.size() != numCols) {
      throw std::invalid_argument(
          "Initializer list must have consistent row sizes.");
    }
    rows.emplace_back(rowList);
  }
}

// Special matrices

template <typename T> Matrix<T> Matrix<T>::eye(size_t size) {
  Matrix<T> result(size, size);
  for (size_t i = 0; i < size; ++i) {
    result[i][i] = 1;
  }
  return result;
}

template <typename T> Matrix<T> Matrix<T>::zeros(size_t numRows, size_t numCols) {
  return Matrix<T>(numRows, numCols);
}

template <typename T> Matrix<T> Matrix<T>::ones(size_t numRows, size_t numCols) {
  auto result = Matrix<T>(numRows, numCols);
  for (size_t i = 0; i < numRows; ++i) {
    for (size_t j = 0; j < numCols; ++j) {
      result[i][j] = 1;
    }
  }
  return result;
}

// Accessors
template <typename T> size_t Matrix<T>::numRows() const { return rows.size(); }

template <typename T> size_t Matrix<T>::numCols() const {
  if (rows.empty()) {
    return 0;
  }
  return rows[0].size();
}

// Access row

template <typename T> const Vector<T> &Matrix<T>::operator[](size_t idx) const {
  if (idx >= rows.size()) {
    throw std::out_of_range("Index out of range");
  }
  return rows[idx];
}

template <typename T> Vector<T> &Matrix<T>::operator[](size_t idx) {
  if (idx >= rows.size()) {
    throw std::out_of_range("Index out of range");
  }
  return rows[idx];
}

// Access element

template <typename T> T Matrix<T>::operator()(size_t row, size_t col) const {
  if (row >= numRows() || col >= numCols()) {
    throw std::out_of_range("Matrix element access out of range");
  }
  return rows[row][col];
}

// Matrix operations

// Scalar multiplication

template <typename T> Matrix<T> Matrix<T>::operator*(const T &scalar) const {
  Matrix<T> result(*this);
  for (size_t i = 0; i < numRows(); ++i) {
    for (size_t j = 0; j < numCols(); ++j) {
      result[i][j] *= scalar;
    }
  }
  return result;
}

// Matrix-vector multiplication

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T> &vec) const {
  if (numCols() != vec.size()) {
    throw std::invalid_argument(
        "Matrix-vector multiplication dimensions mismatch");
  }
  Vector<T> result(numRows());
  for (size_t i = 0; i < numRows(); ++i) {
    T sum = 0;
    for (size_t j = 0; j < numCols(); ++j) {
      sum += rows[i][j] * vec[j];
    }
    result[i] = sum;
  }
  return result;
}

// Matrix-matrix multiplication

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
  if (numCols() != other.numRows()) {
    throw std::invalid_argument(
        "Matrix-matrix multiplication dimensions mismatch");
  }
  Matrix<T> result(numRows(), other.numCols());
  for (size_t i = 0; i < numRows(); ++i) {
    for (size_t j = 0; j < other.numCols(); ++j) {
      T sum = 0;
      for (size_t k = 0; k < numCols(); ++k) {
        sum += rows[i][k] * other[k][j];
      }
      result[i][j] = sum;
    }
  }
  return result;
}

// Pretty-print the matrix

template <typename T> void Matrix<T>::print() const {
  // Determine the maximum width for each column
  std::vector<int> columnWidths(numCols(), 0);

  for (size_t i = 0; i < numRows(); ++i) {
    for (size_t j = 0; j < numCols(); ++j) {
      int width = std::to_string(rows[i][j]).length();
      if (width > columnWidths[j]) {
        columnWidths[j] = width;
      }
    }
  }

  // Print the matrix with aligned columns
  for (size_t i = 0; i < numRows(); ++i) {
    if (i == 0 || i == numRows() - 1) {
      std::cout << "[ ";
    } else {
      std::cout << "| ";
    }
    for (size_t j = 0; j < numCols(); ++j) {
      std::cout << std::setw(columnWidths[j]) << rows[i][j];
      if (j < numCols() - 1) {
        std::cout << " ";
      }
    }
    if (i == 0 || i == numRows() - 1) {
      std::cout << " ]";
    } else {
      std::cout << " |";
    }
    std::cout << std::endl;
  }
}

