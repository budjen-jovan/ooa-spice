#ifndef ELEMENT_H
#define ELEMENT_H

#include "../LinearAlgebra/Matrix.h"
#include "Branch.h"
#include <string>
#include <vector>

// Passive linear elements

class Resistor {
public:
  Resistor(std::string name, std::vector<Node *> nodes, double resistance)
      : name(name), nodes(nodes), resistance(resistance){};

  ~Resistor() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double resistance;
  std::vector<Branch *> branches; // Added vector of branches
};

class Capacitor {
public:
  Capacitor(std::string name, std::vector<Node *> nodes, double capacitance,
            double dt)
      : name(name), nodes(nodes), capacitance(capacitance), dt(dt){};

  ~Capacitor() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double capacitance;
  double dt;
  std::vector<Branch *> branches; // Added vector of branches
};

class Inductor {
public:
  Inductor(std::string name, std::vector<Node *> nodes, double inductance,
           double dt)
      : name(name), nodes(nodes), inductance(inductance), dt(dt){};

  ~Inductor() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);
  void setVoltageSourceIndex(int index);
  int getVoltageSourceIndex();

private:
  std::string name;
  std::vector<Node *> nodes;
  double inductance;
  double dt;
  int voltageSourceIndex;
  std::vector<Branch *> branches; // Added vector of branches
};

// Linear controlled sources

class VoltageControlledVoltageSource {
public:
  VoltageControlledVoltageSource(std::string name, std::vector<Node *> nodes,
                                 double av)
      : name(name), nodes(nodes), av(av){};

  ~VoltageControlledVoltageSource() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double av;
  std::vector<Branch *> branches; // Added vector of branches
};

class CurrentControlledVoltageSource {
public:
  CurrentControlledVoltageSource(std::string name, std::vector<Node *> nodes,
                                 double rm)
      : name(name), nodes(nodes), rm(rm){};

  ~CurrentControlledVoltageSource() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double rm;
  std::vector<Branch *> branches; // Added vector of branches
};

class VoltageControlledCurrentSource {
public:
  VoltageControlledCurrentSource(std::string name, std::vector<Node *> nodes,
                                 double gm)
      : name(name), nodes(nodes), gm(gm){};

  ~VoltageControlledCurrentSource() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double gm;
  std::vector<Branch *> branches; // Added vector of branches
};

class CurrentControlledCurrentSource {
public:
  CurrentControlledCurrentSource(std::string name, std::vector<Node *> nodes,
                                 double ai)
      : name(name), nodes(nodes), ai(ai){};

  ~CurrentControlledCurrentSource() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double ai;
  std::vector<Branch *> branches; // Added vector of branches
};

// Active elements

class IndependentVoltageSource {
public:
  IndependentVoltageSource(std::string name, std::vector<Node *> nodes,
                           double voltage)
      : name(name), nodes(nodes), voltage(voltage){};

  ~IndependentVoltageSource() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);
  void setVoltageSourceIndex(int index);
  int getVoltageSourceIndex();

private:
  std::string name;
  std::vector<Node *> nodes;
  double voltage;
  int voltageSourceIndex;
  std::vector<Branch *> branches; // Added vector of branches
};

class IndependentCurrentSource {
public:
  IndependentCurrentSource(std::string name, std::vector<Node *> nodes,
                           double current)
      : name(name), nodes(nodes), current(current){};

  ~IndependentCurrentSource() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double current;
  std::vector<Branch *> branches; // Added vector of branches
};

// Non-linear elements

class Diode {
public:
  Diode(std::string name, std::vector<Node *> nodes, double Is, double Vt)
      : name(name), nodes(nodes), Is(Is), Vt(Vt){};

  ~Diode() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

  double current();
  double dynamicResistance();

private:
  std::string name;
  std::vector<Node *> nodes;
  double Is;
  double Vt;
  std::vector<Branch *> branches; // Added vector of branches
};

class NPN {
public:
  NPN(std::string name, std::vector<Node *> nodes, double Is, double alpha_f,
      double alpha_r)
      : name(name), nodes(nodes), Is(Is), alpha_f(alpha_f), alpha_r(alpha_r){};

  ~NPN() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double Is;
  double alpha_f;
  double alpha_r;
  std::vector<Branch *> branches; // Added vector of branches
};

class PNP {
public:
  PNP(std::string name, std::vector<Node *> nodes, double Is, double alpha_f,
      double alpha_r)
      : name(name), nodes(nodes), Is(Is), alpha_f(alpha_f), alpha_r(alpha_r){};

  ~PNP() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double Is;
  double alpha_f;
  double alpha_r;
  std::vector<Branch *> branches; // Added vector of branches
};

class NMOS {
public:
  NMOS(std::string name, std::vector<Node *> nodes, double mu_n, double C_ox,
       double W, double L, double Vth, double lambda)
      : name(name), nodes(nodes), mu_n(mu_n), C_ox(C_ox), W(W), L(L), Vth(Vth),
        lambda(lambda){};

  ~NMOS() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double mu_n;
  double C_ox;
  double W;
  double L;
  double Vth;
  double lambda;
  std::vector<Branch *> branches; // Added vector of branches
};

class PMOS {
public:
  PMOS(std::string name, std::vector<Node *> nodes, double mu_p, double C_ox,
       double W, double L, double Vth, double lambda)
      : name(name), nodes(nodes), mu_p(mu_p), C_ox(C_ox), W(W), L(L), Vth(Vth),
        lambda(lambda){};

  ~PMOS() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  double mu_p;
  double C_ox;
  double W;
  double L;
  double Vth;
  double lambda;
  std::vector<Branch *> branches; // Added vector of branches
};

class OpAmp {
public:
  OpAmp(std::string name, std::vector<Node *> nodes)
      : name(name), nodes(nodes){};

  ~OpAmp() = default;

  void stamp(Matrix &G, Matrix &B, Matrix &C, Matrix &D, Vector &i, Vector &e);

private:
  std::string name;
  std::vector<Node *> nodes;
  std::vector<Branch *> branches; // Added vector of branches
};

#endif // ELEMENT_H
