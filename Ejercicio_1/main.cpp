#include "Crono.h"

int main() {
    Crono t1(13, 14, 42);
    t1.mostrarCrono();
    t1.setHH(11);
    t1.mostrarCrono();
    t1.setMM(5);
    t1.mostrarCrono();
    t1.setSS(5);
    t1.mostrarCrono();
    

    return 0;
}