#ifndef JACOBIAN_H
#define JACOBIAN_H

#include "../LinearAlgebra/Matrix.h"
#include "../LinearAlgebra/Vector.h"
#include "Grad.h"
#include <functional>

using vectorFunction = std::function<Vector(const Vector&)>;

Matrix jac(const vectorFunction &f, const Vector &x, double h);

#endif // JACOBIAN_H
