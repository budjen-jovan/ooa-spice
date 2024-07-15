#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>

class Node {
public:
  Node(std::string name, int id) : name(name), id(id){};

  std::string getName() const;
  int getId() const;
  double getVoltage() const;
  void setVoltage(double voltage);
  void addConnectedBranch(std::string name);
  void getConnectedBranches() const;

private:
  std::string name;
  int id;
  std::vector<std::string> connectedBranches;
  double voltage = 0.0;
};

#endif // NODE_H
