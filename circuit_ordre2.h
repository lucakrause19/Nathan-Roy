#include "source.h"

class circuitO2{
public:

circuitO2();
~circuitO2();

virtual float f(float temps, source* ve, float vs){};

float f(float h, float temps, source *ve, float vs, float vs_line);

protected:

source *m_pS;

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
source* m_pS;

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
