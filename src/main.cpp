#include "../include/Matrix.h"
#include "../include/Vector.h"

int main() {
  // Create a 3x3 identity matrix
  Matrix<double> I = Matrix<double>::eye(3);
  std::cout << "Identity Matrix:" << std::endl;
  I.print();
  std::cout << std::endl;

  // Create a 3x3 matrix with specific values
  Matrix<double> A = {{2, -1, 1}, {3, 3, 9}, {3, 3, 5}};
  std::cout << "Matrix A:" << std::endl;
  A.print();
  std::cout << std::endl;

  // Perform row operations
  A.swapRows(0, 1);
  std::cout << "After swapping row 0 and row 1:" << std::endl;
  A.print();
  std::cout << std::endl;

  A.scaleRow(1, 0.5);
  std::cout << "After scaling row 1 by 0.5:" << std::endl;
  A.print();
  std::cout << std::endl;

  A.addScaledRow(2, 1, -3);
  std::cout << "After adding -3 times row 1 to row 2:" << std::endl;
  A.print();
  std::cout << std::endl;

  // Create a lower triangular matrix L and upper triangular matrix U
  Matrix<double> L = {{1, 0, 0}, {2, 1, 0}, {4, 3, 1}};
  Matrix<double> U = {{1, 2, 3}, {0, 1, 4}, {0, 0, 1}};

  // Create a vector b
  Vector<double> b = {5, 6, 7};

  // Perform forward substitution to solve L * y = b
  Vector<double> y = L.forwardSubstitution(b, L);
  std::cout << "Solution vector y after forward substitution:" << std::endl;
  y.print();
  std::cout << std::endl;

  // Perform backward substitution to solve U * x = y
  Vector<double> x = U.backwardSubstitution(y, U);
  std::cout << "Solution vector x after backward substitution:" << std::endl;
  x.print();
  std::cout << std::endl;

  Matrix<double> B = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::cout << "Matrix B:" << std::endl;
  B.print();
  std::cout << std::endl;

  Matrix<double> RREF_B = B.rref();
  std::cout << "rref(B):" << std::endl;
  RREF_B.print();
  std::cout << std::endl;

  // Check matrix rank
  std::cout << "rank(B) = " << B.rank() << std::endl;

  Matrix<int> C = {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
  std::cout << "Matrix C:" << std::endl;
  C.print();

  std::cout << "rank(C) = " << C.rank() << std::endl;

  std::cout << "rref(C):" << std::endl;
  C.rref().print();

  return 0;
}
