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


float circuit::euler(float u_n, float h, float f)
{
   return (u_n + h*f);
}


float circuitA::f(float temps, source *ve, float vs, float h){
    //cout<<vs<<endl;
    //int a;
    //cin>>a;
    if (temps == 0) return 0;
    else {  float f = (ve->generer_onde(temps - h) - vs)/(r*c);
            return euler(vs,h,f);
}
}

float circuitB::f(float temps, source *ve, float vs, float h){
    //cout<<vs<<endl;
    if (temps == 0) return 0;
    else if (ve->generer_onde(temps) > vbe){
    return (-(1/(r1*c) + 1/(r2*c))*vs + (ve->generer_onde(temps - h) - vbe)/(r1*c));
    } else return (-vs/(r2*c));
}
