#ifndef DIODE_H
#define DIODE_H

#include "Element.h"

class Diode : public Element
{
public:
  Diode(std::string name, Node* node1, Node* node2, double Is, double Vt);
  std::vector<vectorFunction> constitutiveRelations() const override;

private:
  double Is;
  double Vt;
};

#endif // DIODE_H
