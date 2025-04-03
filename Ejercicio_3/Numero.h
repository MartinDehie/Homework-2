#ifndef NUMERO_H
#define NUMERO_H

using namespace std;

class Numero{
    public:
    virtual void toString() = 0;
    virtual Numero& operator+(Numero&) = 0;
    virtual Numero& operator-(Numero&) = 0;
    virtual Numero& operator*(Numero&) = 0;
    virtual Numero& operator/(Numero&) = 0;
};
class Entero : public Numero
{
private:
    int valor;
public:
    Entero(int v);
    Entero& operator+ (Numero& v) override;
    Entero& operator- (Numero& v) override;
    Entero& operator* (Numero& v) override;
    Entero& operator/ (Numero& v) override;
    int getValue();
    void toString() override;    
};


class Real: public Numero
{
private:
    double valor;
public:
    Real(double v);
    Real& operator+ (Numero& v) override;
    Real& operator- (Numero& v) override;
    Real& operator* (Numero& v) override;
    Real& operator/ (Numero& v) override;
    double getValue();
    void toString() override;    

};

class Imaginario: public Numero
{
private:
    double real,imaginario;
public:
    Imaginario(double r, double i);
    Imaginario& operator+ (Numero& v) override;
    Imaginario& operator- (Numero& v) override;
    Imaginario& operator* (Numero& v) override;
    Imaginario& operator/ (Numero& v) override;
    double getReal();
    double getImaginario();
    void toString() override;  
};



#endif