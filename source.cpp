#include<iostream>
#include<math.h>
#include <tgmath.h>
#include "source.h"

using namespace std;

//----------------------- Constructeurs de la classe mere (default et parametrise)
source::source(){
    phi = 0;
    vzero = 0;
};

source::source(float phi1, float vzero2){
    phi = phi1;
    vzero = vzero2;
};

//----------------------- Destructeurs de la classe mere (default et parametrise)

source::~source(){};

//----------------------- Getters de la classe mere (default et parametrise)

float source::get_phi(){
    return this->phi;
}

float source::get_vzero(){
    return this->vzero;
}

//----------------------- Constructeurs de la classe echellon (classe fille) (default et parametrise)

echelon::echelon():source(){};

echelon::echelon(float ph, float v0):source(ph,v0){};

//----------------------- Generateur d'onde rectangulaire (classe fille de source) (fonction virtual)

float echelon::generer_onde(float temps){
    if (temps > this->phi){
        return this->vzero;}
    else return 0;
    };


//----------------------- Constructeurs de la classe rectangulaire (classe fille) (default et parametrise)

rectangulaire::rectangulaire():source(){
    t = 0;
    };

rectangulaire::rectangulaire(float ph, float v0, float temps):source(ph,v0){
    t = temps;
};

//----------------------- Generateur d'onde rectangulaire (classe fille de source) (fonction virtual)

float rectangulaire::generer_onde(float temps){
    if(temps>(this->phi) && temps <(this->t + this->phi))
       {
        return this->get_vzero();
    }
    else return 0;
};

//----------------------- Constructeurs de la classe periodique (classe fille) (default et parametrise)

periodique::periodique():source(){
    periode = 0;
}
periodique::periodique(float ph, float v0, float periode1):source(ph,v0)
{
    periode = periode1;
};

//-----------------------  Destructeurs de la classe periodique (classe fille)

periodique::~periodique(){};

//----------------------- Getters de la classe periodique (classe fille)

float periodique::get_phi(){
    source::get_phi();
};

float periodique::get_vzero(){
    source::get_vzero();
};

float periodique::get_periode(){
    return this->periode;
}

//----------------------- Constructeurs de la triangulaire (classe fille de periodique) (default et parametrise)

triangulaire::triangulaire():periodique(){};

triangulaire::triangulaire(float ph, float v0, float period):periodique(ph,v0,period){};

//----------------------- Generateur d'onde triangulaire (classe fille de periodique) (fonction virtual)

float triangulaire::generer_onde(float temps){
    float coss = cos(2*3.1416*(temps-this->phi)/this->periode);
    return ((this->vzero)*acos(coss)/3.1416);
}

//----------------------- Constructeurs de la sinusoidal (classe fille de periodique) (default et parametrise)

sinusoidal::sinusoidal():periodique(){};

sinusoidal::sinusoidal(float ph, float v0, float period):periodique(ph,v0,period){};

//----------------------- Generateur d'onde sinusoidal (classe fille de periodique) (fonction virtual)

float sinusoidal::generer_onde(float temps){
    return vzero*sin(2*3.1416*temps/this->get_periode());
};


//----------------------- Constructeurs de la creneau (classe fille de periodique) (default et parametrise)

creneau::creneau():periodique(){
    duty_cycle = 0;
};

creneau::creneau(float ph, float v0, float period, float duty_cycle1):periodique(ph,v0,period){
    duty_cycle = duty_cycle1;
};

//----------------------- Generateur d'onde creneau (classe fille de periodique) (fonction virtual)

float creneau::generer_onde(float temps){

        double prov1, prov2;
        prov1 = floor((temps - this->phi)/(this->periode));
        prov2 = temps - prov1*this->periode;
        if(prov2 <= this->duty_cycle*periode){
            return (this->vzero);
        }else{
            return 0;
        }
};



