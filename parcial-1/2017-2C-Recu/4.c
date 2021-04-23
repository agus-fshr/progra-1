/*
Teniendo en cuenta que los valores enteros en la tabla ASCII para los simbolos
'a' y 'A' son 97 y 65 respectivamente...

Compila el siguiente programa? Si la respuesta es si, que imprime la expresion.
Justifique su respuesta.
*/

#include <stdio.h>

enum PUNTUACION {EN1='a', EN2='A', EN3};

int main(void) {
	printf("%d, %d, %d\n", EN1, EN2, EN3);
	return(0);
}
