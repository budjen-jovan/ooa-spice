#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H

#include "Element.h"

class VoltageSource : public Element
{
public:
    VoltageSource(std::string name, Node* node1, Node* node2, double voltage);
    std::vector<vectorFunction> constitutiveRelations() const override;
};

#endif // VOLTAGESOURCE_H
