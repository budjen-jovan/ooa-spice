#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "../CircuitElements/Capacitor.h"
#include "../CircuitElements/CurrentSource.h"
#include "../CircuitElements/Element.h"
#include "../CircuitElements/Inductor.h"
#include "../CircuitElements/Resistor.h"
#include "../CircuitElements/Diode.h"
#include "../CircuitElements/VoltageSource.h"
#include "Branch.h"
#include "Node.h"

class Circuit {
public:
  Circuit();
  Circuit(const std::vector<std::vector<std::string>> &netlist);

  void addElement(Element *element);
  std::vector<vectorFunction> generateConstitutiveRelations() const;

  int numNodes() const;
  int numBranches() const;

  std::vector<vectorFunction> getEquations() const;

  void buildKVL();
  void buildKCL();
  void buildConstitutiveRelations();
  void buildEquations();


private:
  std::vector<Node *> nodes;
  std::vector<Branch *> branches;
  std::vector<Element *> elements;
  std::vector<vectorFunction> equations;
  

  Node *findOrCreateNode(const std::string &name);
};

#endif // CIRCUIT_H
