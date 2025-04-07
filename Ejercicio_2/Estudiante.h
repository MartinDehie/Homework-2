#include <iostream>
#include <string>
#include <vector>

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#pragma once

using namespace std;

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
        bool operator<(const Estudiante& otro) const ;
        friend ostream& operator<<(ostream& os, const Estudiante& est);

};
#endif