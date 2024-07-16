#include "../include/NewtonRaphson/LinearFunctionBuilder.h"
#include "../include/NewtonRaphson/NonlinearFunctionBuilder.h"
#include "../include/NewtonRaphson/NewtonRaphson.h"
#include "../include/Circuit/Branch.h"
#include "../include/LinearAlgebra/LinearSolver.h"

Vector vectorTestFunction(const Vector& x) {
  return Vector({x[0] * x[0] - 5, x[1] * x[1] - 9, x[2] * x[2] - 16});
}

Vector scalarTestFunction(const Vector& x) {
  double result = std::exp(x[0]) - 2;
  return Vector({result});
  // return Vector({x[0] * x[0] + x[1] - 5});
}


int main(void) {
  // Define coefficients for each linear function
  // Vector coefficients1({2.0, 0.0, 0.0});
  // Vector coefficients2({0.0, 3.0, 0.0});
  // Vector coefficients3({0.0, 0.0, 4.0});

  // Create FunctionBuilder instances
  // FunctionBuilder builder;

  // Build functions using coefficients
  // FunctionBuilder::vectorFunction func1 = builder.build(coefficients1);
  // FunctionBuilder::vectorFunction func2 = builder.build(coefficients2);
  // FunctionBuilder::vectorFunction func3 = builder.build(coefficients3);
  // vectorFunction func3 = scalarTestFunction;
  
  // x[0] x[1] x[2] x[3] x[4] x[5] x[6] x[7]
  // u1   u2   u3   v1   v2   i1   i2   i3


  // KCL:
  vectorFunction kcl1 = [](const Vector& x) {
    return Vector({-x[5] + x[6]});
  };
  vectorFunction kcl2 = [](const Vector& x) {
    return Vector({-x[6] + x[7]});
  };

  // KVL:
  vectorFunction kvl1 = [](const Vector& x) {
    return Vector({x[0] + x[3]});
  };

  vectorFunction kvl2 = [](const Vector& x) {
    return Vector({x[1] - x[3] + x[4]});
  };

  vectorFunction kvl3 = [](const Vector& x) {
    return Vector({x[2] - x[4]});
  };

  // Constitutive relations:
  vectorFunction constitutive1 = [](const Vector &x) {
    return Vector({x[0] + 3.3}); // Vcc = 3.3V
  };

  vectorFunction constitutive2 = [](const Vector &x) {
    return Vector({x[1] - 1000*x[6]}); // R = 1kOhm
  };

  vectorFunction constitutive3 = [](const Vector &x) {
    double Is = 1e-12;
    double Vt = 0.0256;
    return Vector({x[7] - Is * (std::exp(x[2] / Vt) - 1)}); // I - Is * (exp(V/Vt) - 1) = 0
  };


  // Create NonlinearFunctionBuilder and add functions
  NonlinearFunctionBuilder nonlinearBuilder;
  nonlinearBuilder.addFunction(kcl1);
  nonlinearBuilder.addFunction(kcl2);
  nonlinearBuilder.addFunction(kvl1);
  nonlinearBuilder.addFunction(kvl2);
  nonlinearBuilder.addFunction(kvl3);
  nonlinearBuilder.addFunction(constitutive1);
  nonlinearBuilder.addFunction(constitutive2);
  nonlinearBuilder.addFunction(constitutive3);

  vectorFunction circuit = nonlinearBuilder.getComposedFunction();

  // Find roots
  NewtonRaphson nonlinearSolver;
  double dt = 1e-6;
  double tol = 1e-6;
  int maxIter = 2000;
  
  Vector soln = nonlinearSolver.solve(circuit, Vector({3.3, 0, 0, 0, 0, 0, 0, 0}), dt, tol, maxIter);

  std::cout << "Solution: " << std::endl;
  soln.print();
  std::cout << std::endl;

  std::cout << "f(soln): " << std::endl;
  circuit(soln).print();
  std::cout << std::endl;

  // Get composed function
  NonlinearFunctionBuilder::vectorFunction composedFunc =
      nonlinearBuilder.getComposedFunction();

  // Test with a sample input vector
  Vector x = Vector(8); // x({2.0, 3.0, 4.0});
  Vector result = composedFunc(x);

  result.print(); // Print the result vector

  // Create a Branch instance
  // First I need two nodes
  Node node1("n1_name", 1);
  Node node2("n2_name", 2);

  // Create a branch
  Branch branch("b1_name", &node1, &node2);
  node1.addConnectedBranch(&branch);
  node2.addConnectedBranch(&branch);

  // Print the branch
  auto connectedBranches1 = node1.getConnectedBranches();
  auto connectedBranches2 = node2.getConnectedBranches();
  
  std::cout << "Node1 connected branches: " << connectedBranches1.size() << std::endl;
  for (auto branch : connectedBranches1) {
    branch->print();
  }

  std::cout << "Node2 connected branches: " << connectedBranches2.size() << std::endl;
  for (auto branch : connectedBranches2) {
    branch->print();
  }

  Matrix P = Matrix({{0, 1, 0}, {0, 0, 1}, {1, 0, 0}});
  Vector q({1, 2, 3});
  LinearSolver solver;
  Vector x1 = solver.solve(P, q);
  std::cout << "P: " << std::endl;
  P.print();
  std::cout << "q: " << std::endl;
  q.print();
  std::cout << "Expected P\\q: " << std::endl;
  Vector expected({3, 1, 2});
  expected.print();
  std::cout << "P\\q: " << std::endl;
  x1.print();

  Matrix singularMatrix = Matrix({{1, 1}, {1, 1}});
  Vector q2({1, 2});
  Vector x2 = solver.solve(singularMatrix, q2);
  std::cout << "Returned from singular matrix: " << std::endl;
  x2.print();
  
  // Vector function root finding
  // NewtonRaphson nonlinearSolver;
  vectorFunction func = vectorTestFunction;


  Vector initialGuess({1.0, 1.0, 1.0});
  Vector root = nonlinearSolver.solve(func, initialGuess, dt, tol, maxIter);
  std::cout << "Root: " << std::endl;
  root.print();
  std::cout << "f(root)" << std::endl; 
  func(root).print();

  return 0;
}
