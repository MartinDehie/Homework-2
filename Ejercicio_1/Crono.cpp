#include "Crono.h"
        Crono::Crono(): horas(0), minutos(0), segundos(0), periodo(""){}

        Crono::Crono(int HH): horas(HH), minutos(0), segundos(0), periodo(""){ValidarDatos(horas,minutos,segundos,periodo);}

        Crono::Crono(int HH,int MM): horas(HH), minutos(MM), segundos(0), periodo(""){ValidarDatos(horas,minutos,segundos,periodo);}

        Crono::Crono(int HH,int MM,int SS): horas(HH), minutos(MM), segundos(SS), periodo(""){ValidarDatos(horas,minutos,segundos,periodo);}

        Crono::Crono(int HH,int MM,int SS, string p): horas(HH), minutos(MM), segundos(SS), periodo(p){ValidarDatos(horas,minutos,segundos,periodo);}

        void Crono::ValidarDatos(int HH, int MM, int SS, const string& p){
          if (p != "" && p != "a.m." && p != "p.m.") {
            throw runtime_error("Periodo inválido. Debe ser 'a.m.' o 'p.m.'.");
          }
          if (p == "") {  // Formato 24 horas
              if (HH < 0 || HH > 23) throw runtime_error("Hora inválida (0-23).");
          } else {  // Formato 12 horas
              if (HH < 1 || HH > 12) throw runtime_error("Hora inválida (1-12)");
          }
          if (MM < 0 || MM > 59) throw runtime_error("Minutos inválidos (0-59).");
          if (SS < 0 || SS > 59) throw runtime_error("Segundos inválidos (0-59).");
      
          horas = HH;
          minutos = MM;
          segundos = SS;
          periodo = p;
        }
        
        void Crono::mostrarCrono(){        
            cout << setw(2) << setfill('0') << horas << ":"
              << setw(2) << setfill('0') << minutos << ":"
              << setw(2) << setfill('0') << segundos << " "
              << periodo << endl;
        }
        
        void Crono::setHH(){
          if(periodo == ""){
            while (true)
            { try{
                cout << "Ingrese la hora (0-23): ";
                cin >> horas;

                if (cin.fail()) throw runtime_error("Debe ingresar un número.");
                if(0 > horas || horas > 23) throw runtime_error("Ingrese una hora válida (0-23).");
                break;

              }catch(const exception &e){
                cout << e.what() << endl;
                cin.clear();// Restablece el estado de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n');// Limpia el búfer
              }
            }
          }else{
            while (true)
            {
              try{
                cout << "Ingrese la hora (1-12): ";
                cin >> horas;

                if (cin.fail()) throw runtime_error("Debe ingresar un número.");
                if(0 > horas || horas > 12) throw runtime_error("Ingrese una hora válida (1-12).");
                break;

              }catch(const exception &e){
                cout << e.what() << endl;
                cin.clear();// Restablece el estado de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n');// Limpia el búfer
              }
            }
          }
        }

        void Crono::setMM(){
          while(true){
            try{
              cout << "Ingrese los minutos (0-59): ";
              cin >> minutos;

              if (cin.fail()) throw runtime_error("Debe ingresar un número.");
              if(0 > minutos || minutos > 60) throw runtime_error("Ingrese unos minutos validos (0-59).");
              break;

            }catch(const exception &e){
              cout << e.what() << endl;
              cin.clear();// Restablece el estado de cin
              cin.ignore(numeric_limits<streamsize>::max(), '\n');// Limpia el búfer
            }
          }
        }
        void Crono::setSS(){
          while(true){
            try{
              cout << "Ingrese los segundos (0-59): ";
              cin >> segundos;

              if (cin.fail()) throw runtime_error("Debe ingresar un número.");
              if(0 > segundos || segundos > 60) throw runtime_error("Ingrese unos segundos validos (0-59).");
              break;

            }catch(const exception &e){
              cout << e.what() << endl;
              cin.clear();// Restablece el estado de cin
              cin.ignore(numeric_limits<streamsize>::max(), '\n');// Limpia el búfer
            }
          }
        }
        
        void Crono::setp(){
          while(true){
          cout << "Ingrese el periodo 'a.m.' / 'p.m.'(no completar para formato de 24hs): ";
          getline(cin, periodo);
            if(periodo != "" && periodo != "p.m." && periodo != "a.m."){
              cout << "Ingrese un valor valido"<< endl;
            }else{break;}
          }
        }

        void Crono::menu(){
          setp();
          setHH();
          setMM();
          setSS();
          mostrarCrono();

          int opciones;
          while(true){
          cout << R"(Seleccione entre las siguientes opciones: 
1: Cambiar el periodo ('a.m.' / 'p.m.').
2: Cambiar la hora.
3: Cambiar los minutos.
4: Cambiar los segundos.
5: Salir)"<< endl;
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
              setp();
              setHH();
              break;
            case 2:
              setHH();
              break;
            case 3:
              setMM();
              break;
            case 4:
              setSS();
              break;
            case 5:
              return;
            default:
              throw runtime_error("Debe ingresar un valor válido.");
              break;
            }
            mostrarCrono();
          }
        }