/*
Escribir una funcion que imprima un rectangulo de nxm en pantalla
usando asteriscos y espacios en blanco. El prototipo es

void print_rectangulo(unsigned char n, unsigned char m);

siendo n la cantidad de filas y m columnas. Se deben validar los
parametros de entrada y no se permite utilizar arreglos ni matrices.
*/

#include <stdio.h>

void print_rectangulo(unsigned char n, unsigned char m) {

	for (int linea=1; linea<=n; linea++){
	
		if ((linea == 1) || (linea == (n))) {
			for(int j=0; j<m; j++){
			printf("*");
			}
		}
		else{
			printf("*");
			for (int j=1; j<(m-1); j++){
				printf(" ");
			}
			printf("*");
		}
		
		printf("\n");
		
	}
}

int main() {
	print_rectangulo(N, M);
	return 0;
}

/*

*********
*       * 3x9
*********

*/
