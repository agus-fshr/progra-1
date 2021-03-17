#include <stdio.h>

int main(void){

	int m = 5; //nro de filas
	int n = 5; //nro de columnas
	int col, fil; //contadores

	for(fil=0; fil<m; fil++){ //este for controla la fila en la cual se escribe, incrementando de a 1, hasta llegar al m filas

		for(col=1; col<=n; col++) //este for controla el texto dentro de cada fila, es decir, las columnas
			printf("%d  ", col+fil); //hace col+fil para escribir con el incremento que le corresponde a cada fila

		printf("\n"); //pasa a la siguiente fila
	}

	return 0;
}
/*Mientras se haga con nros de un digito, dejamos el codigo con espacios entre los elementos de las filas, aunque para nros mas grandes,
\t asegura que el espaciado entre columnas sea uniforme.*/
