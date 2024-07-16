#include "../../include/CircuitElements/VoltageSource.h"

VoltageSource::VoltageSource(std::string name, Node *node1, Node *node2,
                             double voltage)
    : Element(name, {node1, node2}, voltage) {
  branches.push_back(new Branch(name, node1, node2));
}

std::vector<vectorFunction> VoltageSource::constitutiveRelations() const {
  return {[=](const Vector &x) -> Vector {
    int voltageIdx = branches[0]->getVoltageIdx();
    return Vector({x[voltageIdx] - value});
  }};
}
