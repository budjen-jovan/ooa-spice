#include "../include/NewtonRaphson/LinearFunctionBuilder.h"
#include "../include/NewtonRaphson/NonlinearFunctionBuilder.h"
#include "../include/Circuit/Branch.h"

int main(void) {
  // Define coefficients for each linear function
  Vector coefficients1({2.0, 0.0, 0.0});
  Vector coefficients2({0.0, 3.0, 0.0});
  Vector coefficients3({0.0, 0.0, 4.0});

  // Create FunctionBuilder instances
  FunctionBuilder builder1;
  FunctionBuilder builder2;
  FunctionBuilder builder3;

  // Build functions using coefficients
  FunctionBuilder::vectorFunction func1 = builder1.build(coefficients1);
  FunctionBuilder::vectorFunction func2 = builder2.build(coefficients2);
  FunctionBuilder::vectorFunction func3 = builder3.build(coefficients3);

  // Create NonlinearFunctionBuilder and add functions
  NonlinearFunctionBuilder nonlinearBuilder;
  nonlinearBuilder.addFunction(func1);
  nonlinearBuilder.addFunction(func2);
  nonlinearBuilder.addFunction(func3);

  // Get composed function
  NonlinearFunctionBuilder::vectorFunction composedFunc =
      nonlinearBuilder.getComposedFunction();

  // Test with a sample input vector
  Vector x({2.0, 3.0, 4.0});
  Vector result = composedFunc(x);

  result.print(); // Print the result vector

  // Create a Branch instance
  // First I need two nodes
  Node node1("Node1", 1);
  Node node2("Node2", 2);

  // Create a branch
  Branch branch("Branch1", &node1, &node2);
  node1.addConnectedBranch(branch.getName());
  node2.addConnectedBranch(branch.getName());

  // Print the branch
  node1.getConnectedBranches();
  node2.getConnectedBranches();

  return 0;
}
