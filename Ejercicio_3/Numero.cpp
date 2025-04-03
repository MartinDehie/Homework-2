#include "Numero.h"
#include <iostream>

Entero:: Entero(int v): valor(v){}
Entero& Entero::operator +(Numero& e){
    Entero* temp = dynamic_cast<Entero*>(&e);
    this->valor += temp->valor;
    return *this;
}
Entero& Entero::operator -(Numero& e){
    Entero* temp = dynamic_cast<Entero*>(&e);
    this->valor -= temp->valor;
    return *this;
}
Entero& Entero::operator *(Numero& e){
    Entero* temp = dynamic_cast<Entero*>(&e);
    this->valor = this->valor * temp->valor;
    return *this;
}
Entero& Entero::operator /(Numero& e){
    Entero* temp = dynamic_cast<Entero*>(&e);
    try {
        if (temp->valor == 0) {
            throw std::runtime_error("Error: División por cero en números enteros.");
        }
        this->valor = this->valor/temp->valor;
        }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        this->valor = 0;
    }
    return *this;
}
int Entero::getValue() {
    return this->valor;
}

void Entero::toString() {
    cout << "EL valor es: " << this->getValue() << endl;
}

Real:: Real(double v): valor(v){}

Real& Real::operator +(Numero& r){
    Real* temp = dynamic_cast<Real*>(&r);
    this->valor += temp->valor;
    return *this;
}
Real& Real::operator -(Numero& r){
    Real* temp = dynamic_cast<Real*>(&r);
    this->valor -= temp->valor;
    return *this;
}
Real& Real::operator *(Numero& r){
    Real* temp = dynamic_cast<Real*>(&r);
    this->valor = this->valor * temp->valor;
    return *this;
};
Real& Real::operator /(Numero& r){
    Real* temp = dynamic_cast<Real*>(&r);
    try {
        if (temp->valor == 0) {
            throw std::runtime_error("Error: División por cero en números reales.");
        }
        this->valor = this->valor/temp->valor;
        }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        this->valor = 0;
    }
    return *this;
}
double Real::getValue() {
    return this->valor;
}
void Real::toString() {
    cout << "EL valor es: " << this->getValue() << endl;
}

Imaginario:: Imaginario(double r,double i): real(r), imaginario(i){}

Imaginario& Imaginario::operator +(Numero& i){
    Imaginario* temp = dynamic_cast<Imaginario*>(&i);
    this->real += temp->real;
    this->imaginario += temp->imaginario;
    return *this;
}
Imaginario& Imaginario::operator -(Numero& i){
    Imaginario* temp = dynamic_cast<Imaginario*>(&i);
    this->real -= temp->real;
    this->imaginario -= temp->imaginario;
    return *this;
}
Imaginario& Imaginario::operator *(Numero& i){
    Imaginario* temp = dynamic_cast<Imaginario*>(&i);
    this->real = (this->real*temp->real) - (this->imaginario * temp->imaginario);
    this->imaginario -= (this->real*temp->imaginario) - (this->imaginario * temp->real);
    return *this;
};
Imaginario& Imaginario::operator /(Numero& i){
    Imaginario* temp = dynamic_cast<Imaginario*>(&i);
    double denom = (temp->real * temp->real) + (temp->imaginario * temp->imaginario) ;
    try {
        if (denom == 0) {
            throw std::runtime_error("Error: División por cero en números imaginarios.");
        }

        this->real = ((this->real * temp->real) + (this->imaginario * temp->imaginario)) / denom;
        this->imaginario = ((this->imaginario * temp->real) - (this->real * temp->imaginario)) / denom;
        
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        this->real = 0;
        this->imaginario = 0;
    }
    return *this;
}
double Imaginario::getReal() {
    return this->real;
}
double Imaginario::getImaginario() {
    return this->imaginario;
}
void Imaginario::toString() {
    cout << "EL valor es: " << this->getReal() << (imaginario >= 0 ? " + " : " - ") << abs(this->getImaginario())<< "i"<< endl;
}