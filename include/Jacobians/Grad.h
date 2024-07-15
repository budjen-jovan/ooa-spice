#ifndef GRAD_H
#define GRAD_H

#include "../LinearAlgebra/Vector.h"
#include <functional>

// Function type: f : R^n -> R
using scalarFunction = std::function<double(const Vector &)>;

// Function type: grad f : R^n -> R^n
Vector grad(const scalarFunction &f, const Vector &x, double h);

#endif // GRAD_H
