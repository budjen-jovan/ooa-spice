#ifndef LINEAR_FUNCTIONBUILDER_H
#define LINEAR_FUNCTIONBUILDER_H

#include "../../include/LinearAlgebra/Vector.h"
#include <functional>

class FunctionBuilder {
public:
  using vectorFunction = std::function<Vector(const Vector&)>;

  vectorFunction build(const Vector& coefficients) const;
};

#endif // LINEAR_FUNCTIONBUILDER_H
