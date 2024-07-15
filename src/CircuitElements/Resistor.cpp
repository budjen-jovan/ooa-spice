#include "../../include/CircuitElements/Resistor.h"

Resistor::Resistor(std::string name, double resistance, Node* node1, Node* node2) : Element(name, {node1, node2}, resistance) {
  // instantiate a branch for this resistor
  branches.push_back(new Branch(name, node1, node2));
}

Vector Resistor::constitutiveRelation(int uOffset, int vOffset, int iOffset, int dim) const {
  Vector equation(dim);
  // STA Layout
  // u
  // v
  // i
  
  // int u_idx = uOffset + nodes[0]->getId();
  // int i_idx = iOffset + branches[0]->getId();

  return equation;
}
