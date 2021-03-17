#include <stdio.h>

int main(void){

        int nro = 997; //nro a chequear si es primo
        int primo = 1; //"booleano" de primo o no
        int i; //contador

	if(nro>=1){ //chequea si el nro ingresado puede ser primo

        	for (i=2; i<nro/2+1; i++){ //se chequean los nros desde 2 hasta la mitad de nro, esto se basa en la idea de la raiz cuadrada (mas sobre esto abajo)
                	if (nro%i==0){ //si el resto de dividir nro por otro numero es 0, entonces ese es divisor distinto de nro y 1, entonces no es primo
				primo = 0;
				break; //sale del loop, para evitar calculo innecesario
                       		}
        	}

        	if (primo == 1)
                	printf("El nro %d es primo\n", nro);
        	else
                	printf("El nro %d no es primo\n", nro);
	}
	else
		printf("El numero solicitado no es natural, por ende, no puede ser primo.\n");

        return 0;
        }

/*
Si un nro no es primo, entonces tiene algun divisor entre 2 y su raiz cuadrada, a partir del 4, todos los nros tienen su raiz cuadrada, menor
a su mitad. Esta particion la hacemos para evitar que, en el caso de que nro sea primo, el programa no chequee valores innecesariamente.

https://stackoverflow.com/questions/5811151/why-do-we-check-up-to-the-square-root-of-a-prime-number-to-determine-if-it-is-pr
Tambien, consultamos la validez de esto con un ayudante de catedra.
*/
