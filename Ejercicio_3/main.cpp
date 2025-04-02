#include <iostream>
#include "Numero.h"

int main(){

    Imaginario i1(1,1), i2(2,2.55);
    Imaginario i3 = i1 - i2;

    i3.showValue(); 

    return 0;
}