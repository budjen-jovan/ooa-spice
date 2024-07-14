#include "../include/LinearAlgebra/LinearSolver.h"
#include "../include/LinearAlgebra/Matrix.h"
#include "../include/LinearAlgebra/Vector.h"

int main() {
  // Matrix A({{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}});
  Matrix A({{1, 2, 3}, {4, 5, 6}, {7, 8, 10}});

  Vector b({8, -11, -3});

  LinearSolver solver;
  try {
    Vector x = solver.solve(A, b);

    std::cout << "Solution vector x:" << std::endl;
    x.print();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
