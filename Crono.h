#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#ifndef CRONO_H
#define CRONO_H
class Crono{

    public:

        Crono();
        Crono(int HH);
        Crono(int HH,int MM);
        Crono(int HH,int MM,int SS);
        Crono(int HH,int MM,int SS, string p);
        void mostrarCrono() const;

    private:

        int horas;
        int minutos;
        int segundos;
        string periodo;

}; 
#endif