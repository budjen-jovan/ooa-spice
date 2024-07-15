#include "../include/LinearAlgebra/LinearSolver.h"
#include "../include/LinearAlgebra/Matrix.h"
#include "../include/LinearAlgebra/Vector.h"
#include "../include/Jacobians/Grad.h"

double scalarTestFunction(const Vector &x) {
  // f(x) = x^2 + y^2 + z^2
  // grad(f(x)) = 2x + 2y + 2z
  return x[0]*x[1] + x[1]*x[2] + x[0]*x[2];
}

int main() {
  // Matrix A({{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}});
  // Matrix A({{1, 2, 3}, {4, 5, 6}, {7, 8, 10}});
  Matrix A({{1, 1, 1}, {2, 0, -1}, {0, 3, 1}});

  // Vector b({8, -11, -3});
  Vector b({5, 4, 2});

  std::cout << "Matrix A:" << std::endl;
  A.print();
  std::cout << "Vector b:" << std::endl;
  b.print();

  std::cout << "Solving the system of linear equations Ax = b..." << std::endl;
  std::cout << "\n" << std::endl;

  LinearSolver solver;
  try {
    Vector x = solver.solve(A, b);

    std::cout << "Solution vector x:" << std::endl;
    x.print();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  
  // Test the gradient function
  Vector x({1, 2, 3});
  double h = 1e-6;
  Vector gradient = grad(scalarTestFunction, x, h);
  std::cout << "Gradient of the test function at x = [1, 2, 3]:" << std::endl;
  gradient.print();



  return 0;
}
