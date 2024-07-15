#ifndef LINEAR_SOLVER_H
#define LINEAR_SOLVER_H

#include "Matrix.h"
#include "Vector.h"
#include <stdexcept>

class LinearSolver {
public:
  LinearSolver() = default;
  ~LinearSolver() = default;

  Vector solve(const Matrix &A, const Vector &b) const;

  bool singularExceptionThrown() const;
  bool nonSquareExceptionThrown() const;
  bool incompatibleExceptionThrown() const;
  
  bool getSingularFlag() const;
  bool getNonSquareFlag() const;
  bool getIncompatibleFlag() const;

  void resetSingularFlag();
  void resetNonSquareFlag();
  void resetIncompatibleFlag();

private:
  // Flags
  mutable bool singularFlag = false;
  mutable bool incompatibleFlag = false;
  mutable bool nonSquareFlag = false;

  // Helper functions
  void swapRows(Matrix &A, int row1, int row2) const;
  void scaleRow(Matrix &A, int row, double scalar) const;
  void addMultipleOfRow(Matrix &A, int destRow, int srcRow,
                        double scalar) const;

  // Gauss-Jordan elimination
  void gaussJordan(Matrix &A, Vector &b) const;
};

#endif // LINEAR_SOLVER_H
