#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include "../Jacobians/Jacobian.h"

class NewtonRaphson {
public:
  NewtonRaphson() = default;
  ~NewtonRaphson() = default;

  Vector solve(const vectorFunction &f, const Vector &x0, const double h,
               const double tol, const int maxIter);
};

#endif // NEWTONRAPHSON_H
