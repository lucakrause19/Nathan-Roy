#include<iostream>
#include<math.h>
#include <tgmath.h>
#include "source.h"

using namespace std;

source::source(){
    phi = 0;
    vzero = 0;
};

source::source(float phi1, float vzero2){
    phi = phi1;
    vzero = vzero2;
};

source::~source(){};

float source::get_phi(){
    return this->phi;
}

float source::get_vzero(){
    return this->vzero;
}

periodique::periodique():source(){
    periode = 0;
}
periodique::periodique(float ph, float v0, float periode1):source(ph,v0)
{
    periode = periode1;
    cout << periode<<endl;  //this->get_periode() << endl;
    cout << vzero<<endl;    //this->get_vzero();
    cout << phi<<endl;
};

periodique::~periodique(){};

float periodique::get_phi(){
    source::get_phi();
};

float periodique::get_vzero(){
    source::get_vzero();
};

float periodique::get_periode(){
    return this->periode;
}

echelon::echelon():source(){};

echelon::echelon(float ph, float v0):source(ph,v0){};

triangulaire::triangulaire():periodique(){};

triangulaire::triangulaire(float ph, float v0, float period):periodique(ph,v0,period){};

float triangulaire::generer_onde(float temps){
    float coss = cos(2*3.1416*(temps-this->phi)/this->periode);
    return ((this->vzero)*acos(coss)/3.1416);
}

float echelon::generer_onde(float temps){
    if (temps > this->phi){
        return this->vzero;}
    else return 0;
    };


sinusoidal::sinusoidal()    //:periodique(){/*cout << periode << endl;*/} ; //:periodique(){};
{}

sinusoidal::sinusoidal(float ph, float v0, float period):periodique(ph,v0,period){
    cout << endl;
    cout << phi << "  " << vzero << "  " << periode << endl;
};

rectangulaire::rectangulaire():source(){
    t = 0;
    };

rectangulaire::rectangulaire(float ph, float v0, float temps):source(ph,v0){
    t = temps;
    cout << endl;
    cout << phi << "  " << vzero << "  "  <<  t<< endl;
};

float rectangulaire::generer_onde(float temps){
    if(temps>(this->phi) && temps <(this->t + this->phi))
       {
        return this->get_vzero();
    }
    else return 0;
};


creneau::creneau():periodique(){
    duty_cycle = 0;
};

creneau::creneau(float ph, float v0, float period, float duty_cycle1):periodique(ph,v0,period){
    duty_cycle = duty_cycle1;
};


float sinusoidal::get_periode(){
    periodique::get_periode();
};

float sinusoidal::get_vzero(){
    periodique::get_vzero();
};

float sinusoidal::get_phi(){
    periodique::get_phi();
};

float sinusoidal::generer_onde(float temps){
    return vzero*sin(2*3.1416*temps/this->get_periode() + this->get_periode());
};

float creneau::generer_onde(float temps){
    int prov = floor(temps/this->periode);
    int prov_temps = temps - prov*periode;
    if (prov_temps< this->phi)
        return 0;
        else if(temps>this->phi && temps <(this->phi + this->duty_cycle)) //((this->phi)/(2*3.1416)*this->periode)+this->duty_cycle*this->periode)){
        return this->vzero;
        };

