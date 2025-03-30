#include "Curso.h"

    Estudiante::Estudiante(string NN,int LL, vector<notas> CC):nombre(NN),legajo(LL),calificaciones(CC){}
    string Estudiante::get_nombre(){return nombre;}
    int Estudiante::get_legajo(){return legajo;}
    float Estudiante::get_prom(){
        float suma = 0;
        for(vector<notas> i : calificaciones){
            suma += i.nota;
        }
        prom = suma/calificaciones.size();
        return prom;
    }

    void Curso::add_Alumno(Estudiante alumno){Alumnos.push_back(alumno);}
    void Curso::delete_Alumno(Estudiante alumno){
        auto i = find(Alumnos.begin(),Alumnos.end(),alumno);
        if (i != Alumnos.end()) {
            Alumnos.erase(i)
        }
    }
    void Curso::mostrar_Alumnos(){
        for(int i = 0;i<=Alumnos.size();i++){
            cout >> Alumnos[i].get_nombre();
        }
    }