#include "../../include/Circuit/Node.h"

int Node::getId() const { return id; }
std::string Node::getName() const { return name; }
double Node::getVoltage() const { return voltage; }
void Node::setVoltage(double voltage) { this->voltage = voltage; }
void Node::addConnectedBranch(std::string name) { connectedBranches.push_back(name); }
void Node::getConnectedBranches() const {
  for (auto name : connectedBranches) {
    std::cout << name << std::endl;
  }
}
