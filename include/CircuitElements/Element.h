#ifndef ELEMENT_H
#define ELEMENT_H

#include "../LinearAlgebra/Matrix.h"
#include "../Circuit/Branch.h"
#include <string>
#include <vector>

class Element {
public:
  Element(std::string name, const std::vector<Node* >& nodes, double value) : name(name), nodes(nodes), value(value) {};

  virtual Vector constitutiveRelation(int uOffset, int vOffset, int iOffset, int dim) const = 0;

protected:
  std::string name;
  std::vector<Node* > nodes;
  std::vector<Branch* > branches;
  double value;
};

#endif // ELEMENT_H
