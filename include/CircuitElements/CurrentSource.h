#ifndef CURRENTSOURCE_H 
#define CURRENTSOURCE_H

#include "Element.h"

class CurrentSource : public Element
{
public:
    CurrentSource(std::string name, Node* node1, Node* node2, double current);
    std::vector<vectorFunction> constitutiveRelations() const override;
};

#endif // CURRENTSOURCE_H
