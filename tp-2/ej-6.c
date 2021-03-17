/*
    TP2 - Ejercicio 6 - Grupo 7 (FISHER, MARTINEZ TANOIRA, SBRUZZI, OMS)
    Consigna:
        Escribir un programa que imprima en pantalla si un número es 
		primo o no (un número natural es primo si posee exactamente dos divisores).
	
	Nota 1:
		Si un numero no es primo, entonces tiene algun divisor entre 2 y su raiz cuadrada. 
		A partir del 4, la raíz cuadrada de todo número es menor a su mitad 
		(y en el caso de 2 y 3, se cubren los casos usando la mitad + 1). 
		Esto permite que, en el caso de que el numero sea primo, el programa no chequee valores innecesariamente.

		Ref: https://stackoverflow.com/questions/5811151/why-do-we-check-up-to-the-square-root-of-a-prime-number-to-determine-if-it-is-pr
		Adicionalmente consultamos la validez de esto con un ayudante de catedra.
*/

#include <stdio.h>

int main(void){

	int numero = 997; 		//nro a analizar
	int primo = 1; 			//"booleano" de primo o no
	int i; 					//contador

	if(numero >= 1){ 						//chequea si el nro ingresado cumpla las condiciones mínimas para ser primo
		for (i = 2; i < numero/2+1; i++){ 	//se verifican los nros desde 2 hasta la mitad del num, esto se basa en la idea de la raiz cuadrada (nota 1)
			if (numero % i == 0){			//si el resto de dividir nro por otro numero es 0, 
				primo = 0;					//	entonces ese es divisor distinto de nro y 1, entonces no es primo
				break; 						//sale del loop, para evitar calculo innecesario (especialmente con no primos de gran valor)
			}
		}
		if (primo)
			printf("El numero %d es primo.\n", numero);
		else
			printf("El numero %d no es primo.\n", numero);
	} else
		printf("El numero solicitado no es natural, por ende, no puede ser primo.\n"); //por definición de numeros primos

	return 0;
}


