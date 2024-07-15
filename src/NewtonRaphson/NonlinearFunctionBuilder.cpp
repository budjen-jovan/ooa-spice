#include "../../include/NewtonRaphson/NonlinearFunctionBuilder.h"

void NonlinearFunctionBuilder::addFunction(const vectorFunction &func) {
  functions.push_back(func);
}

NonlinearFunctionBuilder::vectorFunction
NonlinearFunctionBuilder::getComposedFunction() const {
  return [this](const Vector &x) -> Vector {
    Vector result = functions[0](x);
    for (size_t i = 1; i < functions.size(); ++i) {
      Vector appended = functions[i](x);
      result = result.concatenate(appended);
    }
    return result;
  };
}
