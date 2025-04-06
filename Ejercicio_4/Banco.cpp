#include "Banco.h"

Banco:: Banco(string NN, double SS): titularCuenta(NN), balance(SS) {}

CajaDeAhorro:: CajaDeAhorro(string NN,double SS): Banco(NN, SS) {}

void Banco::depositar(double d){
    balance += d;
    cout << "Deposito realizado con éxito." << endl;
    return;
}
void CajaDeAhorro:: retirar(double d) {
    if (d > balance){
        cout << "Fondos insuficientes en Caja de Ahorro." << endl;
        return;
    }
    else{
        balance -= d;
        cout << "Retiro realizado con éxito." << endl;
        return;
    }
}
void CajaDeAhorro:: mostrarInfo(){
    if (count > 2)
        balance -= 20;
    else
        count ++;
    cout << "Titular de la cuenta: " << titularCuenta << "." << endl;    
    cout << "Balance: $" << balance << "." << endl;
    cout << "Tipo de cuenta: Caja de ahorro." << endl;
}
CuentaCorriente:: CuentaCorriente(string NN,double SS,CajaDeAhorro* CAA): Banco(NN, SS), cajaAhorroAsociada(CAA){}

void CuentaCorriente:: retirar(double d){
    if (d <= balance) {
        balance -= d;
        cout << "Retiro de $" << d << " de Cuenta Corriente." << endl;
        cout << "Retiro total de $" << d << " exitoso." << endl;
    } else {
        double totalDisponible = balance + cajaAhorroAsociada->balance;
        if(d <= totalDisponible){
            cout << "Retiro de $" << balance << " de Cuenta Corriente." << endl;
            double temp = d - balance;
            balance = 0;
            cout << "Retiro de $" << temp << " de Caja de ahorro." << endl;
            cajaAhorroAsociada->balance -= temp;
            cout << "Retiro total de $" << d << " exitoso." << endl;
        }
        else{
            cout << "No hay suficiente dinero ni en Cuenta Corriente ni en Caja de Ahorro." << endl;
        }
    }
}
void CuentaCorriente:: mostrarInfo(){
    cout << "Titular de la cuenta: " << titularCuenta << "." << endl;    
    cout << "Balance: $" << balance << "." << endl;
    cout << "Tipo de cuenta: Cuenta corriente." << endl;
}