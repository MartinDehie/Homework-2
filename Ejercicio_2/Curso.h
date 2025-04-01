#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <memory>

using namespace std;

#ifndef CURSO_H
#define CURSO_H


struct notas{
    string materia;
    double nota;
};

class Estudiante{
    private:

        string nombre;
        int legajo;
        double prom;
        vector<notas> calificaciones;

    public:

        Estudiante(string NN,int LL, vector<notas> CC);
        string get_nombre();
        int get_legajo();
        double get_prom();

};
class Curso
{
    private:

        vector<shared_ptr<Estudiante>> Alumnos;

    public:

        bool add_Alumno(shared_ptr<Estudiante> alumno);
        bool delete_Alumno(int legajo);
        void mostrar_curso();
        int busqueda(int legajo);
        bool is_full();
        void menu();
        Curso copy(Curso c);
};


#endif