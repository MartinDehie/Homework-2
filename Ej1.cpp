#include "Crono.h"

int main() {
    Crono t1;
    Crono t2(3);
    Crono t3(3, 14);
    Crono t4(3, 14, 42);
    Crono t5(3, 14, 42, "p.m.");

    t1.mostrarCrono();
    t2.mostrarCrono();
    t3.mostrarCrono();
    t4.mostrarCrono();
    t5.mostrarCrono();

    return 0;
}