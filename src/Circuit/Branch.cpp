#include "../../include/Circuit/Branch.h"
#include "../../include/Circuit/Node.h"

Branch::Branch(std::string name, Node *node1, Node *node2)
    : name(name), node1(node1), node2(node2) {}

double Branch::getVoltage() const { return voltage; }
double Branch::getCurrent() const { return current; }

void Branch::setVoltage(double voltage) { this->voltage = voltage; }
void Branch::setCurrent(double current) { this->current = current; }

void Branch::setId(int id) { this->id = id; }
int Branch::getId() const { return id; }

std::string Branch::getName() const { return name; }

Node *Branch::getNode1() const { return node1; }
Node *Branch::getNode2() const { return node2; }

void Branch::print() const {
  std::string repr = "";
  repr += "Branch: " + name + ", ";
  repr += "Node1: " + node1->getName() + ", ";
  repr += "Node2: " + node2->getName() + ", ";
  repr += "Voltage: " + std::to_string(voltage) + ", ";
  repr += "Current: " + std::to_string(current);
  std::cout << repr << std::endl;
}
