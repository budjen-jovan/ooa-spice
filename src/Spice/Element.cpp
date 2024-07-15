#include "../../include/Spice/Element.h"

void Resistor::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                     Vector &e) {
  int n1 = nodes[0]->getId();
  int n2 = nodes[1]->getId();

  double conductance = 1.0 / resistance;

  // Stamp resistor into the G matrix
  // avoiding stamping if node is ground (0)
  if (n1 != 0)
    G[n1][n1] += conductance;
  if (n2 != 0)
    G[n2][n2] += conductance;
  if (n1 != 0 && n2 != 0) {
    G[n1][n2] -= conductance;
    G[n2][n1] -= conductance;
  }
};

void Capacitor::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                      Vector &e) {
  int n1 = nodes[0]->getId();
  int n2 = nodes[1]->getId();

  double currentVoltage = branches[0]->getVoltage();
  double conductance = capacitance / dt;
  double currentCurrent = conductance * currentVoltage;

  // Capacitor, from the standpoint of iteration n+1, is seen as a current
  // source of current I(n) and a parallel conductance G = C/dt currentCurrent
  // is exactly the I(n) Stamp the current source into the i vector
  if (n1 != 0) {
    i[n1] += currentCurrent;
  }
  if (n2 != 0) {
    i[n2] -= currentCurrent;
  }

  // Stamp the conductance into the G matrix
  if (n1 != 0)
    G[n1][n1] += conductance;
  if (n2 != 0)
    G[n2][n2] += conductance;
  if (n1 != 0 && n2 != 0) {
    G[n1][n2] -= conductance;
    G[n2][n1] -= conductance;
  }

  // The branches should be updated inside the simulation loop
}

void Inductor::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                     Vector &e) {
  int n1 = nodes[0]->getId();
  int n2 = nodes[1]->getId();

  double currentVoltage = branches[0]->getVoltage();
  double conductance = dt / inductance;

  // Inductor, from the standpoint of iteration n+1, is seen as a voltage
  // source of voltage V(n) and a series resistance R = L/dt
  // currentVoltage is exactly the V(n).

  // Assuming the parsing step has already set the voltage source index
  int voltageSourceIndex = getVoltageSourceIndex();

  // Stamp the voltage source into the e vector
  e[voltageSourceIndex] += currentVoltage;

  // Stamp the resistance into the G matrix
  if (n1 != 0)
    G[n1][n1] += conductance;
  if (n2 != 0)
    G[n2][n2] += conductance;
  if (n1 != 0 && n2 != 0) {
    G[n1][n2] -= conductance;
    G[n2][n1] -= conductance;
  }
}

void Inductor::setVoltageSourceIndex(int index) { voltageSourceIndex = index; }

int Inductor::getVoltageSourceIndex() { return voltageSourceIndex; }

// TODO: controlled sources

void VoltageControlledVoltageSource::stamp(Matrix &G, Matrix &B, Matrix &C,
                                           Matrix &D, Vector &i, Vector &e) {
  std::cerr << "VoltageControlledVoltageSource::stamp not implemented"
            << std::endl;
}

void VoltageControlledCurrentSource::stamp(Matrix &G, Matrix &B, Matrix &C,
                                           Matrix &D, Vector &i, Vector &e) {
  std::cerr << "VoltageControlledCurrentSource::stamp not implemented"
            << std::endl;
}

void CurrentControlledVoltageSource::stamp(Matrix &G, Matrix &B, Matrix &C,
                                           Matrix &D, Vector &i, Vector &e) {
  std::cerr << "CurrentControlledVoltageSource::stamp not implemented"
            << std::endl;
}

void CurrentControlledCurrentSource::stamp(Matrix &G, Matrix &B, Matrix &C,
                                           Matrix &D, Vector &i, Vector &e) {
  std::cerr << "CurrentControlledCurrentSource::stamp not implemented"
            << std::endl;
}

void IndependentVoltageSource::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D,
                                     Vector &i, Vector &e) {
  // Stamp the voltage source into the e vector
  e[voltageSourceIndex] += voltage;
}

void IndependentVoltageSource::setVoltageSourceIndex(int index) {
  voltageSourceIndex = index;
}

int IndependentVoltageSource::getVoltageSourceIndex() {
  return voltageSourceIndex;
}

void IndependentCurrentSource::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D,
                                     Vector &i, Vector &e) {
  int n1 = nodes[0]->getId();
  int n2 = nodes[1]->getId();

  // Positive entering node, n1 -> n2
  if (n1 != 0) {
    i[n1] -= current;
  }
  if (n2 != 0) {
    i[n2] += current;
  }
}

void Diode::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                  Vector &e) {
  std::cerr << "Diode::stamp not implemented" << std::endl;
}

double Diode::current() {
  double voltage = branches[0]->getVoltage();
  return Is * (exp(voltage / Vt) - 1);
}

double Diode::dynamicResistance() {
  double voltage = branches[0]->getVoltage();
  return Vt / Is * exp(voltage / Vt);
}

void NPN::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                Vector &e) {
  std::cerr << "NPN::stamp not implemented" << std::endl;
}

void PNP::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                Vector &e) {
  std::cerr << "PNP::stamp not implemented" << std::endl;
}

void NMOS::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                 Vector &e) {
  std::cerr << "NMOS::stamp not implemented" << std::endl;
}

void PMOS::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                 Vector &e) {
  std::cerr << "PMOS::stamp not implemented" << std::endl;
}

void OpAmp::stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i,
                  Vector &e) {
  std::cerr << "OpAmp::stamp not implemented" << std::endl;
}
