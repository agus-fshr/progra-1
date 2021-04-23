/*
Escribir una funcion llamada piramide que imprime en pantalla una matriz
de nxn con formato de piramide. La funcion recibe el parametro de n y no
devuelve nada. Debe funcionar para todo 1 <= n <= 25
*/

void piramide (unsigned char n) {

	int medio = n/2;
	int max;

	for (int fila=0; fila<n; fila++){

		if  (fila <= n) {
			max = fila+1;
		}
		else {
			max = abs(n - fila-1);
		}

		
	}
}
