#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <memory>

#include "Estudiante.h" 

using namespace std;

#ifndef CURSO_H
#define CURSO_H

class Curso
{
    private:

        
        vector<shared_ptr<Estudiante>> Alumnos;

    public:
        string Nombre;
        bool add_Alumno(shared_ptr<Estudiante> alumno);
        bool delete_Alumno(int legajo);
        void mostrar_curso();
        int busqueda(int legajo);
        bool is_full();
        Curso copy(Curso c);
        Curso();
        Curso(string NN);

};


#endif