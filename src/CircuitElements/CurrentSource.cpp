#include "../../include/CircuitElements/CurrentSource.h"

CurrentSource::CurrentSource(std::string name, Node *node1, Node *node2,
                             double current)
    : Element(name, {node1, node2}, current) {
  branches.push_back(new Branch(name, node1, node2));
}

std::vector<vectorFunction> CurrentSource::constitutiveRelations() const {
  return {[=](const Vector &x) -> Vector {
    int currentIdx = branches[0]->getCurrentIdx();
    return Vector({x[currentIdx] - value});
  }};
}
