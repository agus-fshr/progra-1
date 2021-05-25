// Escribir el código de la función recursiva dec2bin() que recibe un número como
// argumento y lo imprime en la pantalla en binario.
#include <stdio.h>
void dec2bin(unsigned int dec);

#ifndef NRO
#error "NRO is not defined"
#endif

int main() {
    printf("Leelo de atras para adelante xd \n");
    dec2bin(NRO);
    printf("\n");
}

void dec2bin(unsigned int dec) {
    if (dec < 2) {
        printf("%d", dec);
    }
    else {  
        dec2bin(dec/2);
        printf("%d", dec%2);
    }
}