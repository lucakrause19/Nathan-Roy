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

    ckta = new circuitA(50,pow(1,-9));
    pS = new rectangulaire(0,10,2);
    float v_s = 0;
    FILE * ve;
    FILE * vs;
    int npas=10000;
float t,dt=1./float(npas);

ve=fopen("ve", "wt");
for(int i=0;i<npas+1;i++)
{
t=float(i)*3.141519265*dt;
fprintf(ve,"%f %f \n",t,pS->generer_onde(t));
}
fclose(ve);

vs=fopen("vs", "wt");
for(int i=0;i<npas+1;i++)
{
t=float(i)*3.141519265*dt;
fprintf(vs,"%f %f \n",t,ckta->f(t,pS,v_s,dt));
v_s = ckta->f(t,pS,v_s,dt);
}
fclose(vs);

return 0;
}

