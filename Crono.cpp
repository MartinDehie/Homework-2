#include "Crono.h"

        Crono::Crono(): horas(0), minutos(0), segundos(0), periodo("a.m."){}

        Crono::Crono(int HH): horas(HH), minutos(0), segundos(0), periodo("a.m."){}

        Crono::Crono(int HH,int MM): horas(HH), minutos(MM), segundos(0), periodo("a.m."){}

        Crono::Crono(int HH,int MM,int SS): horas(HH), minutos(MM), segundos(SS), periodo("a.m."){}

        Crono::Crono(int HH,int MM,int SS, string p): horas(HH), minutos(MM), segundos(SS), periodo(p){}

        void Crono::mostrarCrono() const{
            cout << std::setw(2) << std::setfill('0') << horas << "h, "
              << std::setw(2) << std::setfill('0') << minutos << "m, "
              << std::setw(2) << std::setfill('0') << segundos << "s "
              << periodo << std::endl;
        }