#include "../../include/NewtonRaphson/NewtonRaphson.h"
#include "../../include/LinearAlgebra/LinearSolver.h"

Vector NewtonRaphson::solve(const vectorFunction &f, const Vector &x0,
                            const double h, const double tol,
                            const int maxIter) {

  // Initialize variables, current guess and next guess
  Vector x = x0;
  Vector xNext = Vector(x.size());

  // Initialize solver
  LinearSolver solver;

  // Loop until max iter, break out if convergence
  for (int i = 0; i < maxIter; ++i) {
    // Compute the Jacobian
    Matrix J = jac(f, x, h);

    // Set up the linear system
    Vector b = J * x - f(x);

    // Solve the linear system
    try {
      xNext = solver.solve(J, b);
    } catch (const std::runtime_error &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      break;
    }

    // Check for convergence
    if ((xNext - x).norm() < tol) {
      break;
    }

    // Update the current guess
    x = xNext;
  }

  return xNext;
}
