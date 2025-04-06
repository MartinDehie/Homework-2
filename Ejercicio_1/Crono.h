#include <iomanip>
#include <iostream>
#include <string>
#include <limits>

#pragma once

using namespace std;

#ifndef CRONO_H
#define CRONO_H
class Crono{
    private:

        int horas;
        int minutos;
        int segundos;
        string periodo;
        void setHH();
        void setMM();
        void setSS();
        void setp();
        void ValidarDatos(int HH, int MM, int SS, const string& p);
        
    public:

        Crono();
        Crono(int HH);
        Crono(int HH,int MM);
        Crono(int HH,int MM,int SS);
        Crono(int HH,int MM,int SS, string p);
        void mostrarCrono();
        void menu();
}; 
#endif