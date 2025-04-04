#include "Curso.h"
void mostrar_cursos(vector<Curso> c){
    if (c.empty()) {
        cout << "No hay cursos disponibles.\n";
        return;
    }
    cout << "Cursos disponibles:\n";
    for (int i = 0; i < c.size(); ++i) {
        cout << i + 1 << ": " << c[i].Nombre << endl;
    }
}

int main(){
    int opciones;

    vector<Curso> Lista_cursos;
    string NN;
    int LL;
    double nota;
    string materia;
    vector<notas> CC;
    bool j;
    char i;
    int k;
    int cc;
    Estudiante e(NN,LL,CC);
    Curso c(NN);


    while(true){
        cout << R"(Seleccione entre las siguientes opciones: 
1: Crear un curso.
2: Eliminar un curso.
3: Seleccionar un curso.
4: Mostras los cursos.
5: Salir.)"<< endl;
        cin >> opciones;
        try{
            if (cin.fail()) throw runtime_error("Debe ingresar un número.");
        }catch(const exception &e){
            cout << e.what() << endl;
            cin.clear();// Restablece el estado de cin
        }        
        switch (opciones)
        {
            case 1:
                cin.ignore();
                cout <<"Ingrese el nombre del curso: ";
                getline(cin,NN);  
                c = Curso(NN);
                Lista_cursos.push_back(c);
                cout << "Curso creado con éxito" <<endl;
                break;
            case 2:
                mostrar_cursos(Lista_cursos);
                cout <<"ingrese el número del curso que desea eliminar: ";
                cin >> cc;
                Lista_cursos.erase(Lista_cursos.begin() + cc - 1);
                break;
            case 3:
                mostrar_cursos(Lista_cursos);
                cout << "Seleccione el curso";
                cin >> cc;
                while(true){
                cout << R"(Seleccione entre las siguientes opciones: 
1: Inscribir a un alumno.
2: Desinscribir a un alumno.
3: Buscar alumno.
4: capacidad del curso.
5: Imprimir el curso.
6: Volver.)"<< endl;
                cin >> opciones;
    
                try{
                if (cin.fail()) throw runtime_error("Debe ingresar un número.");
                }catch(const exception &e){
                cout << e.what() << endl;
                cin.clear();// Restablece el estado de cin
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (opciones)
                {
                    case 1:
                    
                        cout <<"Ingrese el nombre del alumno: ";
                        getline(cin, NN);
                        cout <<"Ingrese el número de legajo del aulumno: ";
                        cin >> LL;  
                        while(true){
                            cout <<"Ingrese el nombre de la materia: ";
                            cin >> materia;
                            cout <<"Ingrese la nota de la materia: ";
                            cin >> nota;
                            CC.push_back({materia,nota});
                            cout <<"¿Desea agregar otra materia? (S/N): ";
                            cin >> i;
                            if(i != 'S')
                                break;
                        }
                        e = Estudiante(NN, LL, CC);
                        
                        j = Lista_cursos[cc-1].add_Alumno(make_shared<Estudiante>(e));
                        if (j)
                            cout <<"Alumno inscripto con éxito"<< endl;
                        else
                            cout <<"Alumno inscripto sin éxito"<< endl;
                        break;
                    case 2:
                        cout <<"Ingrese el número de legajo del aulumno: ";
                        cin >> LL;
                        
                        j = Lista_cursos[cc-1].delete_Alumno(LL);
                        if (j)
                            cout <<"Alumno desinscripto con éxito"<< endl;
                        else
                            cout <<"Alumno desinscripto sin éxito"<< endl;
                        break;
                    case 3:
                        cout <<"Ingrese el número de legajo del aulumno: ";
                        cin >> LL;
                        k = Lista_cursos[cc-1].busqueda(LL);
                        if (k != -1)
                            cout <<"Alumno inscripto en el curso"<< endl;
                        else
                            cout <<"Alumno no inscripto en el curso"<< endl;
                        break;
                    case 4:
                        j = Lista_cursos[cc-1].is_full();
                        if (j)
                            cout <<"El curso no tiene cupos disponibles"<< endl;
                        else
                            cout <<"El curso tiene cupos disponibles"<< endl;
                        break;
                    case 5:
                        Lista_cursos[cc-1].mostrar_curso();
                        break;
                    case 6:
                        break;
                    default:
                    cout << "Debe ingresar un valor válido." << endl;
                    break;
                }
                if (opciones == 6) break;
        }
                break;
            case 4:
                mostrar_cursos(Lista_cursos);
                break;
            case 5:
                return 0;
            default:
              cout << "Debe ingresar un valor válido." << endl;
              break;
          }
    }
}