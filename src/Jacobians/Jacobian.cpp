#include "../../include/Jacobians/Jacobian.h"

Matrix jac(const vectorFunction &f, const Vector &x, double h) {
  Vector f0 = f(x);
  int m = f0.size();
  int n = x.size();
  Matrix J(m, n);

  for (int i = 0; i < m; ++i) {
    scalarFunction scalarFunc = [i, &f](const Vector &x) { return f(x)[i]; };

    Vector gradient = grad(scalarFunc, x, h);
    for (int j = 0; j < n; ++j) {
      J[i][j] = gradient[j];
    }
  }

  return J;
}
