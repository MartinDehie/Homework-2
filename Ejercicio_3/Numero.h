#ifndef NUMERO_H
#define NUMERO_H

class Numero{
    public:
    virtual suma() = 0;
    virtual resta() = 0;
    virtual multiplicación() = 0;
    virtual división() = 0;
};
class Entero : public Numero
{
private:
    int valor;
public:
    Entero(int v);
    Numero suma(Entero e)override;
    Numero resta(Entero e)override;
    Numero multiplicación(Entero e)override;
    Numero división(Entero e)override;    
};

class Real: public Numero
{
private:
    double valor;
public:
    Real(double v);
    Numero suma(Real r)override;
    Numero resta(Real r)override;
    Numero multiplicación(Real r)override;
    Numero división(Real r)override;

};

class Imaginario: public Numero
{
private:
    double real,imaginario;
public:
    Imaginario(double r, double i);
    Numero suma(Imaginario i)override;
    Numero resta(Imaginario i)override;
    Numero multiplicación(Imaginario i)override;
    Numero división(Imaginario i)override;
};



#endif