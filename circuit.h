#ifndef CIRCUIT_H_INCLUDED
#define CIRCUIT_H_INCLUDED

#include "source.h"

class circuit{
public:

circuit();

virtual float f(float temps, source* ve, float vs){};

float euler(float h, float temps, source *ve, float vs);

protected:
//float vs_line;
//float vs_0;


private:
};


class circuitA:public circuit{
public:

circuitA();
circuitA(float r, float c);

float f(float temps, source* ve, float vs);


protected:

//float vs_line;
//float vs_0;
float r;
float c;


private:
};

class circuitB:public circuit{
public:

circuitB();
circuitB(float r1, float r2, float c, float vbe);

float f(float temps, source* ve, float vs);



protected:
//float vs_line;
//float vs_0;
float r1;
float r2;
float c;
float vbe;


private:
};



#endif // CIRCUIT_H_INCLUDED
