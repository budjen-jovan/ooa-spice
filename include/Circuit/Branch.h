#ifndef BRANCH_H
#define BRANCH_H

#include "Node.h"
#include <string>

// Forward declaration
class Node;

class Branch {
public:
  Branch(std::string name, Node *node1, Node *node2);

  double getVoltage() const;
  double getCurrent() const;
  
  void setId(int id);
  int getId() const;

  void setVoltage(double voltage);
  void setCurrent(double current);

  void setVoltageIdx(int idx);
  void setCurrentIdx(int idx);

  int getVoltageIdx() const;
  int getCurrentIdx() const;

  std::string getName() const;
  Node *getNode1() const;
  Node *getNode2() const;

  void print() const;

private:
  std::string name;
  int id = 0;
  int voltageIdx = 0;
  int currentIdx = 0;
  Node *node1;
  Node *node2;
  double voltage = 0.0;
  double current = 0.0;
};

#endif // BRANCH_H
