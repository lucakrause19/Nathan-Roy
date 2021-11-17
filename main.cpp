#include<iostream>
#include "source.h"
#include <math.h>
#include <tgmath.h>

using namespace std;

int main()
{
    creneau a(0.3,10,2*3.14,0.45);

    cout << "SEXTA FEIRA DOS CRIAAAAAAAA CAI CAI CAI CAI ";
    FILE * fich;
int npas=100000;
float t,dt=12/float(npas);
fich=fopen("ve","wt");
for(int i=0;i<npas+1;i++)
{
t=float(i)*dt;
fprintf(fich,"%f %f \n",t,a.generer_onde(t));
}
fclose(fich);
return 0;
};
