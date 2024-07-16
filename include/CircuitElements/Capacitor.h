#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Element.h"

class Capacitor : public Element
{
public:
    Capacitor(std::string name, Node* node1, Node* node2, double capacitance, double dt);
    std::vector<vectorFunction> constitutiveRelations() const override;
private:
    double dt;
};

#endif // CAPACITOR_H
