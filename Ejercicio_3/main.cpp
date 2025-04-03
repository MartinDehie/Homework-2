#include <iostream>
#include "Numero.h"

int main(){

    Entero e0(0),e1(4), e2(5);
    Entero e3 = e1 + e2;
    e3.toString(); 
    Entero e4 = e1 - e2;
    e4.toString(); 
    Entero e5 = e1 * e2;
    e5.toString(); 
    Entero e6 = e1 / e2;
    e6.toString();
    Entero e7 = e1 / e0; 
    e7.toString();

    Real r0(0),r1(2.25), r2(2.42);
    Real r3 = r1 + r2;
    r3.toString(); 
    Real r4 = r1 - r2;
    r4.toString(); 
    Real r5 = r1 * r2;
    r5.toString(); 
    Real r6 = r1 / r2;
    r6.toString();
    Real r7 = r1 / r0; 
    r7.toString();

    Imaginario i0(0,0),i1(2.25,2.55), i2(2.42,1.42);
    Imaginario i3 = i1 + i2;
    i3.toString(); 
    Imaginario i4 = i1 - i2;
    i4.toString(); 
    Imaginario i5 = i1 * i2;
    i5.toString(); 
    Imaginario i6 = i1 / i2;
    i6.toString();
    Imaginario i7 = i1 / i0; 
    i7.toString();

    return 0;
}