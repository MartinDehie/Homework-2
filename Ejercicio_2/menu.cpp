#include "Curso.h"
#include "Estudiante.h"
#include "menu.h"

void mostrar_menu_principal() {
    cout << "1. Crear nuevo curso" << endl;
    cout << "2. Seleccionar curso existente" << endl;
    cout << "3. Eliminar curso" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecciona una opcion: ";
}

void mostrar_menu_curso() {
    cout << "1. Agregar estudiante" << endl;
    cout << "2. Eliminar estudiante" << endl;
    cout << "3. Mostrar curso" << endl;
    cout << "4. Ver si el curso esta lleno" << endl;
    cout << "5. Copiar curso" << endl;
    cout << "6. Volver al menu principal" << endl;
    cout << "Selecciona una opcion: ";
}

void menu() {
    vector<Curso> cursos;
    string nombreCurso;
    int opcionPrincipal;

    while (true) {
        mostrar_menu_principal();
        cin >> opcionPrincipal;
        cin.ignore();

        if (opcionPrincipal == 1) {
            cout << "Nombre del nuevo curso: ";
            getline(cin, nombreCurso);
            bool existe = false;
            for (Curso& c : cursos) {
                if (c.get_nombre() == nombreCurso) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                cursos.push_back(Curso(nombreCurso));
                cout << "Curso creado con exito." << endl;
            } else {
                cout << "El curso ya existe." << endl;
            }

        } else if (opcionPrincipal == 2) {
            if (cursos.empty()) {
                cout << "No hay cursos disponibles." << endl;
                continue;
            }

            cout << "Cursos disponibles:" << endl;
            for (Curso& c : cursos) {
                cout << "- " << c.get_nombre() << endl;
            }

            cout << "Nombre del curso a administrar: ";
            getline(cin, nombreCurso);

            int index = -1;
            for (int i = 0; i < cursos.size(); ++i) {
                if (cursos[i].get_nombre() == nombreCurso) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "Curso no encontrado." << endl;
            } else {
                Curso& curso = cursos[index];
                Curso copia;
                int opcionCurso;

                while (true) {
                    mostrar_menu_curso();
                    cin >> opcionCurso;
                    cin.ignore();

                    if (opcionCurso == 1) {
                        string nombre;
                        int legajo;
                        int Nota;

                        cout << "Nombre: ";
                        getline(cin, nombre);
                        cout << "Legajo: ";
                        cin >> legajo;
                        cout << "Nota: ";
                        cin >> Nota;
                        vector<notas> califs;

                        
                        double n;
                        cout << "Nota: ";
                        cin >> n;
                        cin.ignore();
                        califs.push_back({curso.get_nombre(), n});

                        shared_ptr<Estudiante> e = make_shared<Estudiante>(nombre, legajo, califs);
                        if (curso.add_Alumno(e))
                            cout << "Estudiante agregado con exito." << endl;
                        else
                            cout << "No se pudo agregar al estudiante (ya existe o el curso esta lleno)." << endl;

                    } else if (opcionCurso == 2) {
                        int legajo;
                        cout << "Legajo del estudiante a eliminar: ";
                        cin >> legajo;
                        if (curso.delete_Alumno(legajo))
                            cout << "Estudiante eliminado con exito." << endl;
                        else
                            cout << "Estudiante no encontrado." << endl;

                    } else if (opcionCurso == 3) {
                        cout << "Estudiantes en el curso:" << endl;
                        curso.mostrar_curso();

                    } else if (opcionCurso == 4) {
                        if (curso.is_full())
                            cout << "El curso esta lleno." << endl;
                        else
                            cout << "El curso tiene espacio disponible." << endl;

                    } else if (opcionCurso == 5) {
                        copia = curso.copy(curso);
                        cout << "Curso copiado exitosamente." << endl;
                        cout << "Contenido del curso copiado:" << endl;
                        copia.mostrar_curso();
                    } else if (opcionCurso == 6) {
                        break;
                    }
                }
            }

        } else if (opcionPrincipal == 3) {
            if (cursos.empty()) {
                cout << "No hay cursos disponibles." << endl;
                continue;
            }

            cout << "Cursos disponibles:" << endl;
            for (Curso& c : cursos) {
                cout << "- " << c.get_nombre() << endl;
            }
            cout << "Nombre del curso a eliminar: ";
            getline(cin, nombreCurso);
            bool eliminado = false;
            for (int i = 0; i < cursos.size(); ++i) {
                if (cursos[i].get_nombre() == nombreCurso) {
                    cursos.erase(cursos.begin() + i);
                    eliminado = true;
                    cout << "Curso eliminado con exito." << endl;
                    break;
                }
            }
            if (!eliminado) {
                cout << "Curso no encontrado." << endl;
            }

        } else if (opcionPrincipal == 4) {
            break;
        }
    }

    return;
}
