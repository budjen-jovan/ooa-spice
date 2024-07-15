#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>

// Forward declaration
class Branch;

class Node {
public:
  Node(std::string name, int id) : name(name), id(id){};

  std::string getName() const;
  int getId() const;
  double getVoltage() const;
  void setVoltage(double voltage);
  void addConnectedBranch(Branch* branch);
  void getConnectedBranches() const;

private:
  std::string name;
  int id;
  std::vector<Branch*> connectedBranches;
  double voltage = 0.0;
};

#endif // NODE_H
