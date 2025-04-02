#ifndef NUMERO_H
#define NUMERO_H

using namespace std;

class Numero{
    public:
    virtual void showValue() = 0;
};
class Entero : public Numero
{
private:
    int valor;
public:
    Entero(int v);
    Entero& operator+ (Entero& e);
    Entero& operator- (Entero& e);
    Entero& operator* (Entero& e);
    Entero& operator/ (Entero& e);
    int getValue();
    void showValue() override;    
};


class Real: public Numero
{
private:
    double valor;
public:
    Real(double v);
    Real& operator+ (Real& r);
    Real& operator- (Real& r);
    Real& operator* (Real& r);
    Real& operator/ (Real& r);
    double getValue();
    void showValue() override;    

};

class Imaginario: public Numero
{
private:
    double real,imaginario;
public:
    Imaginario(double r, double i);
    Imaginario& operator+ (Imaginario& e);
    Imaginario& operator- (Imaginario& e);
    Imaginario& operator* (Imaginario& e);
    Imaginario& operator/ (Imaginario& e);
    double getReal();
    double getImaginario();
    void showValue() override;  
};



#endif