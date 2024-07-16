#include "../../../include/CircuitElements/SemiconductorDevices/Diode.h"

Diode::Diode(std::string name, Node* node1, Node* node2, double Is, double Vt)
    : Element(name, {&node1, &node2}, 0), Is(Is), Vt(Vt) {
  // instantiate a branch for this diode
  branches.push_back(new Branch(name, node1, node2));
}

std::vector<vectorFunction> Diode::constitutiveRelations() const {
  return {[=](const Vector& x) -> Vector {
    int voltageIdx = branches[0]->getVoltageIdx();
    int currentIdx = branches[0]->getCurrentIdx();
    return Vector({x[currentIdx] - Is * (exp(x[voltageIdx] / Vt) - 1)});
  }};
}
