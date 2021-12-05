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
};

class periodique: public source{

public:
periodique();
periodique(float phi, float vzero, float periode);
~periodique();
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
float generer_onde(float temps);
};

class creneau: public periodique{

public:
creneau();
creneau(float phi, float vzero, float periode, float duty_cycle);
~creneau(){};
float generer_onde(float temps);

protected:
float duty_cycle;
};

class sinusoidal: public periodique{

public:
sinusoidal();
sinusoidal(float phi, float vzero, float periode);
~sinusoidal(){};
float generer_onde(float temps);
};



class rectangulaire: public source{

public:
rectangulaire();
rectangulaire(float phi, float vzero, float t);
~rectangulaire(){};
float generer_onde(float temps);

protected:
float t;
};

class echelon: public source{

public:
echelon();
echelon(float phi, float vzero);
~echelon(){};
float generer_onde(float temps);
};
