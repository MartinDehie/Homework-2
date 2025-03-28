#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#ifndef CRONO_H
#define CRONO_H
class Crono{
    private:

        int horas;
        int minutos;
        int segundos;
        string periodo;
        
    public:

        Crono();
        Crono(int HH);
        Crono(int HH,int MM);
        Crono(int HH,int MM,int SS);
        Crono(int HH,int MM,int SS, string p);
        void setHH();
        void setMM();
        void setSS();
        void setp();
        void mostrarCrono();
        void menu();
}; 
#endif