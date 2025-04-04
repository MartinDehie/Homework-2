#include "Curso.h"
#include "Estudiante.cpp"

    Curso::Curso(string NN):Nombre(NN){}
    Curso::Curso():Nombre(""){}

    bool Curso::add_Alumno(shared_ptr<Estudiante> alumno){
        int i = busqueda(alumno->get_legajo());
        if(i == -1 && Alumnos.size() < 20){
            Alumnos.push_back(alumno);
            return true;}
        return false;
    }
    bool Curso::delete_Alumno(int legajo){
        int i = busqueda(legajo);
        if (i != -1){
            Alumnos.erase(Alumnos.begin() + i);
            return true;
        }
        return false;
    }
    bool comparar_por_nombre(shared_ptr<Estudiante> a, shared_ptr<Estudiante> b) {
        return a->get_nombre() < b->get_nombre();
    }
    void Curso::mostrar_curso(){
        sort(Alumnos.begin(), Alumnos.end(), comparar_por_nombre);
        for(int i = 0;i<Alumnos.size();i++)
            cout << Alumnos[i]->get_nombre() << endl;
        return;
    }
    int Curso::busqueda(int legajo){
        for(int i = 0;i< Alumnos.size();i++){
            if(Alumnos[i]->get_legajo() == legajo)
                return i;
        }return -1;
    }
    bool Curso::is_full(){return Alumnos.size() >= 20;}

    Curso Curso::copy(Curso c){
        Curso nuevoCurso(c.Nombre + "-copy");
        for (shared_ptr<Estudiante> alumno : c.Alumnos) {
            nuevoCurso.Alumnos.push_back(make_shared<Estudiante>(*alumno));
        }
        return nuevoCurso;
    }