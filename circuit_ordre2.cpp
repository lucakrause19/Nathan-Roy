#include "circuit_ordre2.h"


circuitO2::circuitO2(){
};

circuitO2::~circuitO2(){};

circuitC::circuitC(){
    m_r = 0;
    m_L = 0;
    m_c = 0;
};

circuitC::circuitC(float r, float L, float c){
    m_r = r;
    m_L = L;
    m_c = c;
};

float circuitC::f(float temps, source* ve, float vs, float vs_line, float h){
    return (-m_r/m_L)*vs_line + (ve->generer_onde(temps) - vs)/(m_L*m_c);
};

circuitD::circuitD(){
    m_r = 0;
    m_L = 0;
    m_c = 0;
};

circuitD::circuitD(float r, float L, float c){
    m_r = r;
    m_L = L;
    m_c = c;
};

float circuitD::f(float temps, source* ve, float vs, float vs_line, float h){
    float ve_line = (ve->generer_onde(temps) - ve->generer_onde(temps - h*temps))/h;
    return (ve_line - vs)/(m_L*m_c) - vs/(m_L*m_c);
};
