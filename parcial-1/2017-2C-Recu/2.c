/*
Escribir una funcion que devuelve si un arreglo es capicua (es decir, si
sus elementos estan espejados). El prototipo es

int is_capicua (int* p1, unsigned int len);

siendo el ptr un puntero al primer elemento de un arreglo y len la
cantidad de elementos del arreglo.

Se debe resolver utilizando sintaxis de punteros y se deben validar los
parametros de entrada.
*/
#include <stdio.h>

int is_capicua (char* p1, unsigned int len) {

	int capicua = 1;
	int medio = len/2;
	len--;
	
	for (int i=0; i < medio; i++) {
	
		if (*(p1+i) != *(p1+(len-i))) {
			capicua = 0;
			break;
		}
		
	}

	return capicua;
}

int main() {
	char arr[] = "neuquen";
	char* p1;
	p1 = arr;

	if (is_capicua(p1, 7)) {
		printf("es capicua\n");
	}
	else {
		printf("no es capicua\n");
	}

	return 0;
}
