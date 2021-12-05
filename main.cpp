#include<iostream>
#include "source.h"
#include "circuit.h"
#include <math.h>
#include <tgmath.h>

using namespace std;

int main()
{


    circuitA *ckta;

    source *pS;

    ckta = new circuitA(50,pow(10,-9));
    pS = new sinusoidal(0,1,120*pow(10,-9));
    float last = 0;
    FILE * ve;
    FILE * vs;

//float trace_source()
//{
    int npas=10000;
float t,dt=(500*pow(10,-9))/float(npas);

ve=fopen("ve", "wt");
for(int i=0;i<npas+1;i++)
{
t=float(i)*3.141519265*dt;
fprintf(ve,"%.15f %.15f \n",t,pS->generer_onde(t));
}
fclose(ve);

//Generer tension de sortie


vs=fopen("vs", "wt");
for(int i=0;i<npas+1;i++)
{
t=float(i)*3.141519265*dt;
last = ckta->f(t,pS,last,dt);
fprintf(vs,"%.15f %.15f \n",t,last);
}
fclose(vs);

return 0;
};


