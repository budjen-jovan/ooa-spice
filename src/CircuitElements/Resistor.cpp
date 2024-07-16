#include "../../include/CircuitElements/Resistor.h"

Resistor::Resistor(std::string name, Node *node1, Node *node2,
                   double resistance)
    : Element(name, {node1, node2}, resistance) {
  // instantiate a branch for this resistor
  branches.push_back(new Branch(name, node1, node2));
}

std::vector<vectorFunction> Resistor::constitutiveRelations() const {
  return {[=](const Vector &x) -> Vector {
    int voltageIdx = branches[0]->getVoltageIdx();
    int currentIdx = branches[0]->getCurrentIdx();
    return Vector({x[voltageIdx] - x[currentIdx] * value});
  }};
}
