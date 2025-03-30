#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef CURSO_H
#define CURSO_H


struct notas{
    string materia;
    float nota;
};

class Estudiante{
    private:

        string nombre;
        int legajo;
        float prom;
        vector<notas> calificaciones;

    public:

        Estudiante(string NN,int LL, vector<notas> CC);
        string get_nombre();
        int get_legajo();
        float get_prom();

};
class Curso
{
    private:

        vector<Estudiante> Alumnos;

    public:

        void add_Alumno(Estudiante alumno);
        void delete_Alumno(Estudiante alumno);
        void mostrar_Alumnos();

};


#endif