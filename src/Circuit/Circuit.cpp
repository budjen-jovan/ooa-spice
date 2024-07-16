#include "../../include/Circuit/Circuit.h"

Circuit::Circuit() {}

Circuit::Circuit(const std::vector<std::vector<std::string>> &netlist) {
  for (const auto &entry : netlist) {
    if (entry.size() < 4) {
      throw std::invalid_argument(
          "Invalid netlist entry: insufficient number of arguments");
    }

    std::string name = entry[0];
    std::string node1Name = entry[1];
    std::string node2Name = entry[2];

    // Extract values from the tail of the netlist entry
    std::vector<double> values;
    for (size_t i = 3; i < entry.size(); i++) {
      values.push_back(std::stod(entry[i]));
    }

    Node *node1 = findOrCreateNode(node1Name);
    Node *node2 = findOrCreateNode(node2Name);

    Element *element = nullptr;

    switch (name[0]) {
    case 'R':
      if (values.size() != 1) {
        throw std::invalid_argument("Invalid netlist entry: incorrect number "
                                    "of arguments for resistor");
      }
      element = new Resistor(name, node1, node2, values[0]);
      element->setBranchId(0, elements.size());
      break;

    case 'L':
      if (values.size() != 2) {
        throw std::invalid_argument("Invalid netlist entry: incorrect number "
                                    "of arguments for inductor");
      }
      element = new Inductor(name, node1, node2, values[0], values[1]);
      element->setBranchId(0, elements.size());
      break;

    case 'C':
      if (values.size() != 2) {
        throw std::invalid_argument("Invalid netlist entry: incorrect number "
                                    "of arguments for capacitor");
      }
      element = new Capacitor(name, node1, node2, values[0], values[1]);
      element->setBranchId(0, elements.size());
      break;

    case 'V':
      if (values.size() != 1) {
        throw std::invalid_argument("Invalid netlist entry: incorrect number "
                                    "of arguments for voltage source");
      }
      element = new VoltageSource(name, node1, node2, values[0]);
      element->setBranchId(0, elements.size());
      break;

    case 'I':
      if (values.size() != 1) {
        throw std::invalid_argument("Invalid netlist entry: incorrect number "
                                    "of arguments for current source");
      }
      element = new CurrentSource(name, node1, node2, values[0]);
      element->setBranchId(0, elements.size());
      break;

    case 'D':
      if (values.size() != 2) {
        throw std::invalid_argument("Invalid netlist entry: incorrect number "
                                    "of arguments for diode");
      }
      element = new Diode(name, node1, node2, values[0], values[1]);
      element->setBranchId(0, elements.size());
      break;

    default:
      throw std::invalid_argument("Invalid netlist entry: unknown element");
    }

    addElement(element);
  }
}

Node *Circuit::findOrCreateNode(const std::string &name) {
  for (Node *node : nodes) {
    if (node->getName() == name) {
      return node;
    }
  }
  // If the node does not exist, create it
  int id = nodes.size();
  Node *node = new Node(name, id);
  nodes.push_back(node);
  return node;
}

int Circuit::numNodes() const { return nodes.size(); }

int Circuit::numBranches() const { return elements.size(); }

void Circuit::addElement(Element *element) { elements.push_back(element); }

void Circuit::buildKVL() {
  // u, i, v
  // iterate over branches, construct kvl
  for (Branch *branch : branches) {
    Node *node1 = branch->getNode1();
    Node *node2 = branch->getNode2();

    int voltageIdx = branch->getVoltageIdx();

    int node1Id = node1->getId();
    int node2Id = node2->getId();

    // create lambda-function for branch KVL
    vectorFunction kvlEquation = [=](const Vector &x) -> Vector {
      double voltageDrop = x[voltageIdx];

      if (node1Id != 0) {
        voltageDrop -= x[node1Id - 1];
      }
      if (node2Id != 0) {
        voltageDrop += x[node2Id - 1];
      }

      return Vector({voltageDrop});
    };

    equations.push_back(kvlEquation);
  }
}

void Circuit::buildKCL() {
  // iterate over nodes, construct kcl
  for (Node *node : nodes) {
    if (node) {
      int nodeId = node->getId();
      if (nodeId == 0) {
        continue;
      }

      // create lambda-function for node KCL
      vectorFunction kclEquation = [node, this](const Vector &x) -> Vector {
        double sumCurrents = 0.0;

        // iterate over connected branches, with positive current leaving the
        // node

        for (Branch *branch : node->getConnectedBranches()) {
          if (branch) {
            int currentIdx = branch->getCurrentIdx();
            if (branch->getNode1() == node) {
              sumCurrents += x[currentIdx];
            } else if (branch->getNode2() == node) {
              sumCurrents -= x[currentIdx];
            }
          }
        }
        return Vector({sumCurrents});
      };

      equations.push_back(kclEquation);
    }
  }
}

std::vector<vectorFunction> Circuit::getEquations() const { return equations; }
