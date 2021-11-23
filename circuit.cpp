#include<iostream>
#include<math.h>
#include <tgmath.h>
#include "circuit.h"

using namespace std;

circuit::circuit(){
}


circuitA::circuitA(){
    r = 0;
    c = 0;
}

circuitA::circuitA(float rr, float cc){
    r = rr;
    c = cc;
}

circuitB::circuitB(){
    r1 = 0;
    r2 = 0;
    c = 0;
    vbe = 0.6;
}

float circuit::euler(float h, float temps, source *ve, float vs){
    return vs + h*f(temps,ve,vs);
}

float circuitA::f(float temps, source *ve, float vs){
    return (ve->generer_onde(temps) - vs)/(r*c);
}

float circuitB::f(float temps, source *ve, float vs){
    if (ve->generer_onde(temps) > vbe){
    return (-(1/(r1*c) + 1/(r2*c))*vs + (ve->generer_onde(temps) - vbe)/(r1*c));
    } else return (-vs/(r2*c));
}
