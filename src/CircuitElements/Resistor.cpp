#include "../../include/CircuitElements/Resistor.h"

Resistor::Resistor(std::string name, double resistance, Node *node1,
                   Node *node2)
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
