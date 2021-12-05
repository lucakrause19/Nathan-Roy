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
    cout << r << endl;
    cout << c << endl;
}

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


float circuit::euler(float u, float h, float f)
{
   return (u + h*f);
}


float circuitA::f(float temps, source *ve, float vs, float h){
    //cout<<vs<<endl;
    //int a;
    //cin>>a;
    if (temps <= 0) return 0;
    else {  float func = (ve->generer_onde(temps - h) - vs)/(r*c);
            return euler(vs,h,func);
}
}


//float Circuit_A::v_s(float lastValue, float temps, float dt, Source *source)
//{
//    if (temps <= 0.0) {
//        return 0;
//    } else {
//        float f = (source->v_e(temps-dt)-lastValue)/(m_R*m_C);
//        return Euler1(lastValue, dt, f);
//    }
//}


float circuitB::f(float temps, source *ve, float vs, float h){
    //cout<<vs<<endl;
    float func;
    if (temps == 0) return 0;
    else if (ve->generer_onde(temps) > vbe){
    func = (-(1/(r1*c) + 1/(r2*c))*vs + (ve->generer_onde(temps - h) - vbe)/(r1*c));
    } else func = (-vs/(r2*c));
     return euler(vs,h,func);
}
