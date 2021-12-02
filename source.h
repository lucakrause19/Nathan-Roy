#include <iostream>
#pragma once

using namespace std;

class source{
public:

source();
source(float phi, float vzero);
~source();

virtual float generer_onde(float temps){};   //{};
virtual float get_phi();
virtual float get_vzero();

protected:

float phi;
float vzero;


private:
virtual ostream& print(ostream &O) const{};

};

class periodique: public source{

public:
periodique();
periodique(float phi, float vzero, float periode);
~periodique();
ostream& print(ostream &O) const{};
float generer_onde(float temps)=0;   //{};
float get_vzero();
float get_phi();
virtual float get_periode();

protected:
float periode;
};

class triangulaire: public periodique{

public:
triangulaire();
triangulaire(float phi, float vzero, float periode);
~triangulaire(){};
ostream& print(ostream &O) const{};
float generer_onde(float temps);
};

class creneau: public periodique{

public:
creneau();
creneau(float phi, float vzero, float periode, float duty_cycle);
~creneau(){};
ostream& print(ostream &O) const{};
float generer_onde(float temps);

protected:
float duty_cycle;
};

class sinusoidal: public periodique{

public:
sinusoidal();
sinusoidal(float phi, float vzero, float periode);
~sinusoidal(){};
ostream& print(ostream &O) const{};
float generer_onde(float temps);
float get_vzero();
float get_phi();
float get_periode();

};



class rectangulaire: public source{

public:
rectangulaire();
rectangulaire(float phi, float vzero, float t);
~rectangulaire(){};
ostream& print(ostream &O) const{};
float generer_onde(float temps);

protected:
float t;
};

class echelon: public source{

public:
echelon();
echelon(float phi, float vzero);
~echelon(){};
ostream& print(ostream &O) const{};
float generer_onde(float temps);
};
