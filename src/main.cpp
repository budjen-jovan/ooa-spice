#include "../include/LinearAlgebra/Matrix.h"
#include "../include/LinearAlgebra/Vector.h"
#include "../include/LinearAlgebra/LinearSolver.h"

int main() {
  Matrix A({{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}});

  Vector b({8, -11, -3});

  LinearSolver solver;
  Vector x = solver.solve(A, b);

  std::cout << "Solution vector x:" << std::endl;
  x.print();
  return 0;
}
