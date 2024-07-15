#include "../../include/Jacobians/Grad.h"

Vector grad(const scalarFunction &f, const Vector &x, double h) {
  int n = x.size();
  Vector gradient(n);

  for (int i = 0; i < n; i++) {
    // central difference
    Vector x1 = x;
    x1[i] += h;
    Vector x2 = x;
    x2[i] -= h;
    gradient[i] = (f(x1) - f(x2)) / (2 * h);
  }

  return gradient;
}
