#include "Curso.h"

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

    void Curso::menu(){
        int opciones;

        string NN;
        int LL;
        double nota;
        string materia;
        vector<notas> CC;
        bool j;
        char i;
        int k;
        Estudiante e(NN,LL,CC);
              
        while(true){
            cout << R"(Seleccione entre las siguientes opciones: 
  1: Inscribir a un alumno.
  2: Desinscribir a un alumno.
  3: Buscar alumno.
  4: capacidad del curso.
  5: Imprimir el curso.
  6: Salir.)"<< endl;
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
                    
                    j = add_Alumno(make_shared<Estudiante>(e));
                    if (j)
                        cout <<"Alumno inscripto con éxito"<< endl;
                    else
                        cout <<"Alumno inscripto sin éxito"<< endl;

                    break;
                case 2:
                    cout <<"Ingrese el número de legajo del aulumno: ";
                    cin >> LL;
                    
                    j = delete_Alumno(LL);
                    if (j)
                        cout <<"Alumno desinscripto con éxito"<< endl;
                    else
                        cout <<"Alumno desinscripto sin éxito"<< endl;
                    break;
                case 3:
                    cout <<"Ingrese el número de legajo del aulumno: ";
                    cin >> LL;

                    k = busqueda(LL);
                    if (k != -1)
                        cout <<"Alumno inscripto en el curso"<< endl;
                    else
                        cout <<"Alumno no inscripto en el curso"<< endl;
                    break;
                case 4:
                    j = is_full();
                    if (j)
                        cout <<"El curso no tiene cupos disponibles"<< endl;
                    else
                        cout <<"El curso tiene cupos disponibles"<< endl;
                    break;
                case 5:
                    mostrar_curso();
                    break;
                case 6:
                    return;
                default:
                  throw runtime_error("Debe ingresar un valor válido.");
                  break;
              }
            }
    }

    Curso Curso::copy(Curso c){
        Curso nuevoCurso;
        for (shared_ptr<Estudiante> alumno : c.Alumnos) {
            nuevoCurso.Alumnos.push_back(make_shared<Estudiante>(*alumno));
        }
        return nuevoCurso;
    }