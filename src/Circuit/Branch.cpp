#include "../../include/Circuit/Branch.h"

double Branch::getVoltage() const { return voltage; }
double Branch::getCurrent() const { return current; }

void Branch::setVoltage(double voltage) { this->voltage = voltage; }
void Branch::setCurrent(double current) { this->current = current; }

int Branch::getId() const { return id; }

std::string Branch::getName() const { return name; }

Node *Branch::getNode1() const { return node1; }
Node *Branch::getNode2() const { return node2; }
