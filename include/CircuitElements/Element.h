#ifndef ELEMENT_H
#define ELEMENT_H

#include "../LinearAlgebra/Matrix.h"
#include "../Circuit/Branch.h"
#include <string>
#include <vector>
#include <functional>

using vectorFunction = std::function<Vector(const Vector&)>;

class Element {
public:
  Element(std::string name, const std::vector<Node* >& nodes, double value) : name(name), nodes(nodes), value(value) {};
  virtual std::vector<vectorFunction> constitutiveRelations() const = 0;
  void setBranchId(int branchIdx, int id) { branches[0]->setId(id); }

protected:
  std::string name;
  std::vector<Node* > nodes;
  std::vector<Branch* > branches;
  double value;
};

#endif // ELEMENT_H
