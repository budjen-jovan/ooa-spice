#ifndef RESISTOR_H
#define RESISTOR_H
#include "Element.h"

class Resistor : public Element {
public:
    Resistor(std::string name, double resistance, Node* node1, Node* node2);
    std::vector<vectorFunction> constitutiveRelations() const override;
};
#endif // RESISTOR_H
