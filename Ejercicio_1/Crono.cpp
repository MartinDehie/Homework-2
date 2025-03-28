#include "Crono.h"

        Crono::Crono(): horas(0), minutos(0), segundos(0), periodo(""){}

        Crono::Crono(int HH): horas(HH % 24), minutos(0), segundos(0), periodo(""){}

        Crono::Crono(int HH,int MM): horas(HH % 24), minutos(MM), segundos(0), periodo(""){}

        Crono::Crono(int HH,int MM,int SS): horas(HH % 24), minutos(MM), segundos(SS), periodo(""){}

        Crono::Crono(int HH,int MM,int SS, string p): horas(HH % 24), minutos(MM), segundos(SS), periodo(p){}

        void Crono::mostrarCrono(){
          if(minutos >= 60){
            horas = horas + 1*(minutos/60);
            minutos = minutos % 60;
          }
          if(segundos >= 60){
            minutos = minutos + 1*(segundos/60);
            segundos = segundos % 60;
          }
          if(periodo != ""){
            if(horas>= 12 && periodo == "a.m.")
              periodo = "p.m.";
            else if(horas>= 12 && periodo == "p.m.")
              periodo = "a.m.";
            horas = horas % 12;
          }else{horas = horas % 24;}
          
            cout << setw(2) << setfill('0') << horas << ":"
              << setw(2) << setfill('0') << minutos << ":"
              << setw(2) << setfill('0') << segundos << " "
              << periodo << endl;
        }
        void Crono::setHH(int HH){horas += HH;}
        void Crono::setMM(int MM){minutos += MM;}
        void Crono::setSS(int SS){segundos += SS;}
        void Crono::setp(string p){periodo = p;}