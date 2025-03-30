#include "Crono.h"

int main() {

    Crono c1;
    Crono c2(10);
    Crono c3(10, 30);
    Crono c4(10, 30, 45);
    Crono c5(10, 30, 45, "a.m.");

    cout << "Prueba de constructores:" << endl;
    c1.mostrarCrono();
    c2.mostrarCrono();
    c3.mostrarCrono();
    c4.mostrarCrono();
    c5.mostrarCrono();

    Crono t1;
    t1.menu();

    return 0;
}