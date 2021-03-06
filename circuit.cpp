#include<iostream>
#include<math.h>
#include <tgmath.h>
#include "circuit.h"

using namespace std;

//-------------------- Constructeur par default de classe m?re (seulement par default)


circuit::circuit(){
}

//-------------------- Fonction de la methode d'Euler premier ordre


float circuit::euler(float u, float h, float f)
{
   return (u + h*f);
}

//-------------------- Constructeur par default de classe circuit A (default et parametrise)



circuitA::circuitA(){
    r = 0;
    c = 0;
}

circuitA::circuitA(float rr, float cc){
    r = rr;
    c = cc;
    cout << r << endl;
    cout << c << endl;
}

//-------------------- Constructeur par default de classe circuit B (default et parametrise)

circuitB::circuitB(){
    r1 = 0;
    r2 = 0;
    c = 0;
    vbe = 0.6;
}

circuitB::circuitB(float rr1, float rr2, float cc, float vbee){
    r1 = rr1;
    r2 = rr2;
    c = cc;
    vbe = 0.6;
}

//-------------------- Fonction qui va definir la forme de la sortie et sa valeur a un temps fixe, en appellant la methode d'Euler (circuit A)

double circuitA::f(float temps, source *ve, float vs, float h){
    if (temps <= 0.0) {
        return 0;
    } else {
        double func = (ve->generer_onde(temps-h)-vs)*(20000000);
        return euler(vs,h,func);
    }
}

//-------------------- Fonction qui va definir la forme de la sortie et sa valeur a un temps fixe, en appellant la methode d'Euler (circuit B)

double circuitB::f(float temps, source *ve, float vs, float h){
    double func;
    if (temps == 0) return 0;
    else if (ve->generer_onde(temps) > vbe){
    func = ((1/(r1*c) + 1/(r2*c))*(-vs) + (ve->generer_onde(temps - h) - vbe)/(r1*c));
    } else func = (-vs/(r2*c));
     return euler(vs,h,func);
}
