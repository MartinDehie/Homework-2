#include "Banco.h"

int main(){
    int opcion;
    string nombre;
    double monto;

    cout << "Ingrese el nombre del titular: ";
    getline(cin, nombre);

    CajaDeAhorro* caja = new CajaDeAhorro(nombre, 0);
    CuentaCorriente corriente = CuentaCorriente(nombre, 0, caja);

    while (true) {
        cout << "\n---- MENÚ ----" << endl;
        cout << "1-> Depositar en Caja de Ahorro" << endl;
        cout << "2-> Depositar en Cuenta Corriente" << endl;
        cout << "3-> Retirar desde Caja de Ahorro" << endl;
        cout << "4-> Retirar desde Cuenta Corriente" << endl;
        cout << "5-> Mostrar info de Caja de Ahorro" << endl;
        cout << "6-> Mostrar info de Cuenta Corriente" << endl;
        cout << "0-> Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 0) {
            break;
        }

        switch (opcion) {
            case 1:
                cout << "Monto a depositar en Caja de Ahorro: $";
                cin >> monto;
                caja->depositar(monto);
                break;
            case 2:
                cout << "Monto a depositar en Cuenta Corriente: $";
                cin >> monto;
                corriente.depositar(monto);
                break;
            case 3:
                cout << "Monto a retirar de Caja de Ahorro: $";
                cin >> monto;
                caja->retirar(monto);
                break;
            case 4:
                cout << "Monto a retirar de Cuenta Corriente: $";
                cin >> monto;
                corriente.retirar(monto);
                break;
            case 5:
                caja->mostrarInfo();
                break;
            case 6:
                corriente.mostrarInfo();
                break;
            default:
                cout << "Opción inválida->" << endl;
        }
    }

    return 0;
}