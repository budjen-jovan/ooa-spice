#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
  Node(std::string name, int id) : name(name), id(id) {};

  std::string getName() const;
  int getId() const;
  double getVoltage() const;
  void setVoltage(double voltage);

private:
  std::string name;
  int id;
  double voltage = 0.0;
};

#endif // NODE_H
