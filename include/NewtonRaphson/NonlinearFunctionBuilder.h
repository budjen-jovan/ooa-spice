#ifndef NONLINEAR_FUNCTION_BUILDER_H
#define NONLINEAR_FUNCTION_BUILDER_H

#include "../LinearAlgebra/Vector.h"
#include <functional>

class NonlinearFunctionBuilder
{
public:
  using vectorFunction = std::function<Vector(const Vector&)>;
  
  void addFunction(const vectorFunction& func);

  vectorFunction getComposedFunction() const;

private:
  std::vector<vectorFunction> functions;
};


#endif // NONLINEAR_FUNCTION_BUILDER_H
