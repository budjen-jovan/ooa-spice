#include "../../include/Circuit/Node.h"
#include "../../include/Circuit/Branch.h"

int Node::getId() const { return id; }
std::string Node::getName() const { return name; }
double Node::getVoltage() const { return voltage; }
void Node::setVoltage(double voltage) { this->voltage = voltage; }
void Node::addConnectedBranch(Branch *branch) {
  connectedBranches.push_back(branch);
}
std::vector<Branch*> Node::getConnectedBranches() const { return connectedBranches; }
