// Reescribir el programa del ejercicio 6 del TP2 (evaluación de números primos),
// permitiendo al usuario ingresar el número que se desea evaluar por teclado, y
// encapsulando el código que determina si un número es primo dentro de una
// función.

#include <stdio.h>

int es_primo(int);

int main(void) {

	int c;
	int numero;
	
	while((c = getchar()) != '\n'){

		if(c >= '0' && c <= '9'){
			numero *= 10.0;
			numero += c - '0';
		}
		
	}

	es_primo(numero);
	
}

int es_primo(int numero){
	
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
