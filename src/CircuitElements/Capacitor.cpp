#include "../../include/CircuitElements/Capacitor.h"

Capacitor::Capacitor(std::string name, Node *node1, Node *node2,
                     double capacitance, double dt)
    : Element(name, {node1, node2}, capacitance), dt(dt) {
  branches.push_back(new Branch(name, node1, node2));
}

std::vector<vectorFunction> Capacitor::constitutiveRelations() const {
  return {[=](const Vector &x) -> Vector {
    int voltageIdx = branches[0]->getVoltageIdx();
    int currentIdx = branches[0]->getCurrentIdx();

    double Ieq = -value / dt * branches[0]->getVoltage();
    double geq = value / dt;

    return Vector({geq * x[voltageIdx] - x[currentIdx] + Ieq});
  }};
}
