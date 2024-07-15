#include "../include/NewtonRaphson/NewtonRaphson.h"

Vector vectorTestFunction(const Vector &x) {
  return Vector({x[0] * x[0] - 1, x[1] * x[1] - 3});
}

Vector appendFourthFunction(const Vector &x) {
    // Define your fourth function here
    return Vector({x[2] * x[2] - 5});
}

vectorFunction composeFunctions(vectorFunction f1, vectorFunction f2) {
    return [=](const Vector& x) {
        Vector result = f1(x);
        Vector appended = f2(x);
        result.elements.insert(result.elements.end(), appended.elements.begin(), appended.elements.end());
        return result;
    };
}


double scalarTestFunction(const Vector &x) {
  return x[0] * x[1] + x[1] * x[2] + x[0] * x[2];
}

int main() {
  // Matrix A({{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}});
  // Matrix A({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  Matrix A({{1, 1, 1}, {2, 0, -1}, {0, 3, 1}});

  // Vector b({8, -11, -3});
  // Vector b({5, 4, 2});
  Vector b = Vector::getRandVector(3, 0, 10);

  std::cout << "Matrix A:" << std::endl;
  A.print();
  std::cout << "Vector b:" << std::endl;
  b.print();

  std::cout << "Solving the system of linear equations Ax = b..." << std::endl;
  std::cout << "\n" << std::endl;

  LinearSolver solver;
  std::cout << solver.getSingularFlag() << std::endl;
  try {
    Vector x = solver.solve(A, b);

    std::cout << "Solution vector x:" << std::endl;
    x.print();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  std::cout << solver.getSingularFlag() << std::endl;
  solver.resetSingularFlag();
  std::cout << solver.getSingularFlag() << std::endl;

  // Test the gradient function
  Vector x({1, 2, 3});
  double h = 1e-6;
  Vector gradient = grad(scalarTestFunction, x, h);
  std::cout << "Gradient of the test function at x = [1, 2, 3]:" << std::endl;
  gradient.print();

  // Define the vector function
  vectorFunction f = vectorTestFunction;

  // Calculate the Jacobian
  Matrix jacobian = jac(f, x, h);

  // Output the Jacobian
  std::cout << "Jacobian Matrix at [1.0, 2.0, 3.0]:" << std::endl;
  jacobian.print();

  // Check norm calculation
  std::cout << "norm(x) = " << x.norm() << std::endl;

  vectorFunction combinedFunction = composeFunctions(vectorTestFunction, appendFourthFunction);

  // Test the Newton-Raphson method
  // Vector x0 = Vector::getRandVector(3, -5, 5);
  Vector x0 = Vector::getZeroVector(3);
  std::cout << "Initial guess x0:" << std::endl;
  x0.print();

  NewtonRaphson newtonRaphson;
  Vector solution = Vector(x.size());
  
  solution = newtonRaphson.solve(combinedFunction, x0, h, 1e-6, 200);
  
  std::cout << "Solution vector x:" << std::endl;
  solution.print();
  
  std::cout << "f(x) = " << std::endl;
  combinedFunction(solution).print();
  
  Matrix bad = Matrix({{0, 1, 0}, {1, 0, 0}, {0, 0, 1}});
  Vector badb = Vector({1, 2, 3});
  
  std::cout << "Test case for permutation matrix" << std::endl;
  Vector expected = Vector({2, 1, 3});
  std::cout << "Expected solution: " << std::endl;
  expected.print();
  std::cout << "Actual solution: " << std::endl;
  solver.solve(bad, badb).print();

  return 0;
}
