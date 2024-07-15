#include "../../include/NewtonRaphson/NewtonRaphson.h"

Vector NewtonRaphson::solve(const vectorFunction &f, const Vector &x0,
                            const double h, const double tol,
                            const int maxIter) {

  // Initialize variables, current guess and next guess
  Vector x = x0;
  Vector xNext = Vector(x.size());

  // TODO: Implement a better way to handle this
  double minGuess = x0.min();
  if (minGuess == 0) {
    minGuess = -10;
  }

  double maxGuess = x0.max();
  if (maxGuess == 0) {
    maxGuess = 10;
  }

  // Initialize solver
  LinearSolver solver;

  // Loop until max iter, break out if convergence
  for (int i = 0; i < maxIter; ++i) {
    // Compute the Jacobian
    Matrix J = jac(f, x, h);

    // Set up the linear system
    Vector b = J * x - f(x);

    // Solve the linear system
    xNext = solver.solve(J, b);

    // Randomize the initial guess if singular
    if (solver.getSingularFlag()) {
      x = Vector::getRandVector(x.size(), minGuess, maxGuess);
      xNext = Vector(x.size());
      std::cerr << "Singular matrix encountered, randomizing initial guess." << std::endl;
      solver.resetSingularFlag();
      continue;
    }

    // Check for convergence
    if ((xNext - x).norm() < tol) {
      return xNext;
    }

    // Update the current guess
    x = xNext;
  }
  
  // If the solver did not converge, print a warning
  std::cerr << "Newton-Raphson did not converge within max iterations." << std::endl;
  return Vector(x.size());
}
