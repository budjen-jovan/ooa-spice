#ifndef INDUCTOR_H 
#define INDUCTOR_H

#include "Element.h"

class Inductor : public Element
{
public:
    Inductor(std::string name, Node* node1, Node* node2, double inductance, double dt);
    std::vector<vectorFunction> constitutiveRelations() const override;
private:
    double dt;
};

#endif // INDUCTOR_H
