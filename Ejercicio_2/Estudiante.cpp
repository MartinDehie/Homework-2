#include "Estudiante.h"
    
    Estudiante::Estudiante(string NN,int LL, vector<notas> CC):nombre(NN),legajo(LL),calificaciones(CC){}
    string Estudiante::get_nombre(){return nombre;}
    int Estudiante::get_legajo(){return legajo;}
    double Estudiante::get_prom(){
        double suma = 0;
        for(notas i : calificaciones){
            suma += i.nota;
        }
        prom = suma/calificaciones.size();
        return prom;
    }
    bool Estudiante:: operator<(const Estudiante& otro) const {
        return this->nombre < otro.nombre;
    }
    ostream& operator<<(ostream& os, const Estudiante& est) {
        os << "Nombre: " << est.nombre << ", Legajo: " << est.legajo;
        return os;
    }