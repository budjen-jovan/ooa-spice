#ifndef RESISTOR_H
#define RESISTOR_H
#include "Element.h"

class Resistor : public Element {
public:
    Resistor(std::string name, double resistance, Node* node1, Node* node2);

    Vector constitutiveRelation(int uOffset, int vOffset, int iOffset, int dim) const override;
};
#endif // RESISTOR_H
