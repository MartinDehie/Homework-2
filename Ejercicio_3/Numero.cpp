#include "Numero.h"
#include <iostream>

Entero:: Entero(int v): valor(v){}
Entero& Entero::operator +(Entero& e){
    this->valor += e.valor;
    return *this;
}
Entero& Entero::operator -(Entero& e){
    this->valor -= e.valor;
    return *this;
}
Entero& Entero::operator *(Entero& e){
    this->valor = this->valor * e.valor;
    return *this;
}
Entero& Entero::operator /(Entero& e){
    if(e.valor == 0)
        throw runtime_error("División por cero.");
    this->valor = this->valor/e.valor;
    return *this;
}
int Entero::getValue() {
    return this->valor;
}

void Entero::showValue() {
    cout << "EL valor es: " << this->getValue() << endl;
}

Real:: Real(double v): valor(v){}

Real& Real::operator +(Real& r){
    this->valor += r.valor;
    return *this;
}
Real& Real::operator -(Real& r){
    this->valor -= r.valor;
    return *this;
}
Real& Real::operator *(Real& r){
    this->valor = this->valor * r.valor;
    return *this;
};
Real& Real::operator /(Real& r){
    if(r.valor == 0)
        throw runtime_error("División por cero.");
    this->valor = this->valor/r.valor;
    return *this;
}
double Real::getValue() {
    return this->valor;
}
void Real::showValue() {
    cout << "EL valor es: " << this->getValue() << endl;
}

Imaginario:: Imaginario(double r,double i): real(r), imaginario(i){}

Imaginario& Imaginario::operator +(Imaginario& i){
    this->real += i.real;
    this->imaginario += i.imaginario;
    return *this;
}
Imaginario& Imaginario::operator -(Imaginario& i){
    this->real -= i.real;
    this->imaginario -= i.imaginario;
    return *this;
}
Imaginario& Imaginario::operator *(Imaginario& i){
    this->real = (this->real*i.real) - (this->imaginario * i.imaginario);
    this->imaginario -= (this->real*i.imaginario) - (this->imaginario * i.real);
    return *this;
};
Imaginario& Imaginario::operator /(Imaginario& i){
    double denom = (i.real * i.real) + (i.imaginario * i.imaginario) ;
    if(denom == 0)
        throw runtime_error("División por cero.");
    this->real = ((this->real* i.real) + this->imaginario * i.imaginario)/denom;
    this->imaginario = ((this->imaginario*i.real) + (this->real * i.imaginario))/denom;
    return *this;
}
double Imaginario::getReal() {
    return this->real;
}
double Imaginario::getImaginario() {
    return this->imaginario;
}
void Imaginario::showValue() {
    cout << "EL valor es: " << this->getReal() << (imaginario >= 0 ? " + " : " - ") << abs(this->getImaginario())<< "i"<< endl;
}