#include <stdio.h>

/*
En el caso que se deba trabajar con un conjunto de elementos, seria bastante desprolijo crear
multiples variables. Para esto se utilizan los arreglos.
Un arreglo se define como una coleccion ordenada de elementos del mismo tipo.

En C una variable tipo arreglo se define de la siguiente manera:

tipo nombre_arreglo [CANT_ELEMS];
*/

unsigned int nombre_de_arreglo [10]; // Esto crea un arreglo de 10 unsigned ints

/*
un arreglo, igual que cualquier variable, se puede definir e inicializar simultaneamente, colocando en
una lista los valores iniciales entre llaves, separados por coma.

tipo nombre_arreglo[] = {VAL1, VAL2, VAL3};

Para strings se puede dejar solamente las ""
*/

int otro_arreglo [] = {123, 543, 546};
char string_arreglo[] = "Hello, World!"; // Esto tiene el ultimo elemento del terminador

/*
Para acceder a los elementos de un arreglo se utiliza indice.
EnC, el primer elemento es el cero. Si el arreglo tiene N elementos el indice puede tomar sucesivamente valores
hasta el N-1.

Se usa la notacion arreglo[i]
*/

int elemento_random = otro_arreglo[1]; // 543


/*
MATRICES
Arreglos de arreglos

La definicion de una matriz o arreglo bidimensional es

tipo nombre_matriz [CANT_FILAS] [CANT_COLUMNAS];
*/
unsigned int nombre_matriz [4] [10]; // Matriz de 4 elementos donde cada uno es un arreglo de 10 elementos
/*
int mat [2] [4] = {{1, 2, 3, 4}, {10, 9, 8, 7}};

Hay que fijar siempre las columnas.
*/
