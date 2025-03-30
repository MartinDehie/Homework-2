#include "Curso.h"

int main(){
    Curso curso;

    // Agregar estudiantes
    Estudiante e1("Juan", 1,{});
    Estudiante e2("Maria", 2,{});
    Estudiante e3("Pedro", 3,{});
    
    curso.add_Alumno(e1);
    curso.add_Alumno(e2);
    curso.add_Alumno(e3);

    cout << "Alumnos antes de eliminar:" << endl;
    curso.mostrar_Alumnos();

    // Eliminar estudiante
    curso.delete_Alumno(e2); // Deberíamos eliminar a "Maria"

    cout << "\nAlumnos después de eliminar:" << endl;
    curso.mostrar_Alumnos();

    // Intentar eliminar un estudiante que no existe
    Estudiante e4("Ana", 4);
    curso.delete_Alumno(e4); // No hay ningún estudiante con ID 4

    cout << "\nAlumnos después de intentar eliminar uno no existente:" << endl;
    curso.mostrar_Alumnos();

    return 0;
}