#include "../../include/NewtonRaphson/LinearFunctionBuilder.h"

FunctionBuilder::vectorFunction
FunctionBuilder::build(const Vector &coefficients) const {
  return [coefficients](const Vector &x) -> Vector {
    double result = 0.0;

    for (int i = 0; i < coefficients.size(); i++) {
      result += coefficients[i] * x[i];
    }

    return Vector({result});
  };
}
