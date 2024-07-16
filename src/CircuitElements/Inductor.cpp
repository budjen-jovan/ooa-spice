#include "../../include/CircuitElements/Inductor.h"

Inductor::Inductor(std::string name, Node *node1, Node *node2,
                   double inductance, double dt)
    : Element(name, {node1, node2}, inductance), dt(dt) {
  branches.push_back(new Branch(name, node1, node2));
}

std::vector<vectorFunction> Inductor::constitutiveRelations() const {
  return {[=](const Vector &x) -> Vector {
    int voltageIdx = branches[0]->getVoltageIdx();
    int currentIdx = branches[0]->getCurrentIdx();

    double Veq = -value / dt * branches[0]->getCurrent();
    double req = value / dt;

    return Vector({-x[voltageIdx] + req * x[currentIdx] + Veq});
  }};
}
