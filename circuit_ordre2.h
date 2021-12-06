#include "source.h"

class circuitO2{
public:

circuitO2();
~circuitO2();

virtual float f(float h, float temps, source *ve, float vs, float vs_line){};

//float* circuitO2::euler2(float u1, float u2, float h, float f);

protected:

private:
};

class circuitC:public circuitO2{
public:

circuitC();
circuitC(float r, float L, float c);
~circuitC();

float f(float temps, source* ve, float vs, float vs_line, float h);


protected:

float m_r;
float m_L;
float m_c;

private:
};

class circuitD:public circuitO2{
public:

circuitD();
circuitD(float r, float L, float c);
~circuitD();

float f(float temps, source* ve, float vs, float vs_line, float h);


protected:

float m_r;
float m_L;
float m_c;
source* m_pS;

private:
};
