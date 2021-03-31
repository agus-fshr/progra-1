/*
    TP2 - Ejercicio 7 - Grupo 7 (FISHER, MARTINEZ TANOIRA, SBRUZZI, OMS)
    Consigna:
        Dadas las variables m (cantidad de filas) y n (cantidad de
			columnas), imprimir en pantalla una matriz de números crecientes de izquierda a
			derecha y de arriba hacia abajo. Ejemplo con m=5, n=4:
			1 2 3 4
			2 3 4 5
			3 4 5 6
			4 5 6 7
			5 6 7 8

	Nota 1:
		El if que esta dentro del for sirve unicamente para poner tabs cuando mas de un numero de dos o mas digitos en la matriz.
		Cuando no los haya, usa dos espacios para separar las columnas. Es completamente estetico y, quizas, innecesario.
*/

#include <stdio.h>

int main(void){

	int m = 9; 		//num de filas
	int n = 3; 		//num de columnas
	int col, fil; 	//contadores

	for(fil = 0; fil < m; fil++){ 			//for que controla la fila actual, incrementando de a 1, hasta llegar al m filas

		for(col = 1; col <= n; col++){ 		//for que controla el texto dentro de cada fila: las columnas
			if(n+m-2<10){					//Nota 1
				printf("%d  ", col+fil);	//hace col+fil para escribir con el incremento(offset) que le corresponde a cada fila
			}
			else{
				printf("%d\t", col+fil);
			}
		}
		printf("\n"); 						//pasa a la siguiente fila
	}

	return 0;
}
