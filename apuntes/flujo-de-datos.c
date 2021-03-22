/*FLUJO DE DATOS

Un flujo de datos (stream) es una fuente o destino de datos.
Cuando comienza la ejecucun del programa se crean automaticamente los siguientes flujos de datos.
	-stdin
	-stdin
	-stderr

Para poder hacer uso de las librerias de entrada y salida que posee C, es necesario incluir una libreria
*/
#include <stdio.h>

/*Esto incluye las funciones...*/
// getchar();

/*El prototipo es int getchar(void)
La funcion getchar regresa el siguiente caracter del stdin como unsigned char o EOF*/
int main(void){
	printf("Ejemplo de traer un valor con getchar()\n------------------------------\n");
	int c = getchar();
	printf("el char que me tipeaste: %d\n", c);

	return 0;
}
/*getchar() espera que haya algo en el buffer de salida. Al apretar enter es que el texto de la consola
que se escribio. Lo primero que entra es lo primero que sale. Tambien se puede ingresar un archivo en
getchar() haciendo ./program < archivo.txt Para leer el archivo se hace un while y se chequea que sea
distinto de enter o EOF*/

// putchar();

/*Su proposito es transferir el contenido de una variable desde la memoria al dispositivo de salida.
> archivo.txt redirecciona la salida standard*/
