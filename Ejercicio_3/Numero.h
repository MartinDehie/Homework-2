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
    Numero suma()
    
};

class Real: public Numero
{
private:
    double valor;
public:
    Real(double v);

};

class Imaginario: public Numero
{
private:
    double real,imaginario;
public:
    Imaginario(double real, double imaginario);

};



#endif