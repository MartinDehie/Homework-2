#include <iostream>
#include <limits>

using namespace std; 
#ifndef BANCO_H
#define BANCO_H

#pragma once

class Banco{
    protected:
        double balance;
        string titularCuenta;
    public:
        Banco(string NN, double SS);
        void depositar(double d);
        virtual void retirar(double d) = 0;
        virtual void mostrarInfo() = 0;
};


    class CajaDeAhorro: public Banco{
    public:
        CajaDeAhorro(string NN,double SS);
        void retirar(double d) override;
        void mostrarInfo()override;
        int count = 0;

        friend class CuentaCorriente;
    };

    class CuentaCorriente: public Banco{
    private:
        CajaDeAhorro* cajaAhorroAsociada;
    public:
        CuentaCorriente(string NN,double SS,CajaDeAhorro* CAA);
        void retirar(double d) override;
        void mostrarInfo()override;
    };

#endif