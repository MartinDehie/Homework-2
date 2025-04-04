#include <iostream>
#include <limits>

using namespace std; 
#ifndef BANCO_H
#define BANCO_H

class Banco{
    protected:
        double balance;
        string titularCuenta;
    public:
        bool depositar(double d);
        virtual bool retirar(double d) = 0;
        virtual void mostrarInfo() = 0;
};


    class CajaDeAhorro: public Banco{
        CajaDeAhorro(string& NN,double SS);
        bool retirar(double d) override;
        void mostrarInfo()override;
    };

    class CuentaCorriente: public Banco{
        
        CuentaCorriente(string& NN,double SS);
        bool retirar(double d) override;
        void mostrarInfo()override;
    };

#endif