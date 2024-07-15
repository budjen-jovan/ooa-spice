#ifndef BRANCH_H
#define BRANCH_H

#include "Node.h"
#include <string>

class Branch {
public:
  Branch(std::string name, Node *node1, Node *node2);

  double getVoltage() const;
  double getCurrent() const;
  
  void setId(int id);
  int getId() const;

  void setVoltage(double voltage);
  void setCurrent(double current);

  std::string getName() const;
  Node *getNode1() const;
  Node *getNode2() const;

private:
  std::string name;
  int id = 0;
  Node *node1;
  Node *node2;
  double voltage = 0.0;
  double current = 0.0;
};

#endif // BRANCH_H
