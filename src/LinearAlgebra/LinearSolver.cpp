#include "../../include/LinearAlgebra/LinearSolver.h"

Vector LinearSolver::solve(const Matrix &A, const Vector &b) const {
  // Check if the matrix is square
  if (A.rows() != A.cols()) {
    throw std::invalid_argument("Matrix is not square");
  }
  // Check if the matrix and vector are compatible
  if (A.cols() != b.size()) {
    throw std::invalid_argument("Matrix and vector are not compatible");
  }

  // Create a copy of the matrix and vector
  Matrix A_copy = A;
  Vector b_copy = b;

  // Perform Gauss-Jordan elimination
  gaussJordan(A_copy, b_copy);

  // Return the solution
  int n = A_copy.cols();
  Vector x(n);
  for (int i = 0; i < n; i++) {
    x[i] = b_copy[i];
  }

  return x;
}

void LinearSolver::gaussJordan(Matrix &A, Vector &b) const {
  int numCols = A.cols();
  int numRows = A.rows();

  int lead = 0;
  for (int r = 0; r < numRows; r++) {
    if (lead >= numCols) {
      return;
    }

    int i = r;
    while (A[i][lead] == 0.0) {
      ++i;
      if (i == numRows) {
        i = r;
        ++lead;
        if (lead == numCols) {
          return;
        }
      }
    }
    swapRows(A, i, r);

    double lv = A[r][lead];
    scaleRow(A, r, 1.0 / lv);
    b[r] /= lv;

    for (int i = 0; i < numRows; i++) {
      if (i != r) {
        double c = A[i][lead];
        addMultipleOfRow(A, i, r, -c);
        b[i] -= c * b[r];
      }
    }

    ++lead;
  }
}

void LinearSolver::swapRows(Matrix &A, int row1, int row2) const {
  std::swap(A[row1], A[row2]);
}

void LinearSolver::scaleRow(Matrix &A, int row, double scalar) const {
  for (int i = 0; i < A.cols(); i++) {
    A[row][i] *= scalar;
  }
}

void LinearSolver::addMultipleOfRow(Matrix &A, int destRow, int srcRow,
                                    double scalar) const {
  for (int i = 0; i < A.cols(); i++) {
    A[destRow][i] += scalar * A[srcRow][i];
  }
}
