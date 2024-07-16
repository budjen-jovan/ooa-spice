#ifndef RESISTOR_H
#define RESISTOR_H
#include "Element.h"

class Resistor : public Element {
public:
    Resistor(std::string name, Node* node1, Node* node2, double resistance);
    std::vector<vectorFunction> constitutiveRelations() const override;
};
#endif // RESISTOR_H
