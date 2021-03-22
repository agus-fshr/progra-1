/*FUNCIONES

Las funciones permiten implementar programas modulares. En el lenguaje C las subrutinas de assembler
son reemplazadas por las llamadas funciones. Tienen algunas ventajas por sobre las subrutinas>
Implementan de forma natural
	-el pasaje de parametros por el Stack
	-la creacion y destruccion del Stack
	-la creacion y destruccion de variables locales en el Stack
	-el acceso a los parametros y las variables a traves del stack pointer
	-el programador ya no debe preocuparse por el tamano de las variables ni los offsets

La definicion de cualquier funcion respone a la siguiente sintacis:

tipo nombre(argumentos){
	bloque
}

nombre: nombre de la funcion
argumentos formales: nombre y tipo del parametro que recibe la funcion
bloque:contiene las sentencias que se ejecutan cuando la funcion es invocada
tipo: tipo devuelto por la funcion

ejemplo:*/
#include <stdio.h>
int main(void){

	int suma(int a, int b){ //a y b son los parametros formales
		int resultado;
		resultado = a+b;
		return resultado; //resultado es el valor que devuelve la funcion a traves del stack
	}
/*Cuando una funcion no devuelve nada se debe explicitar con void, y lo mismo si no recibe nada

En una PC los programas son llamados por el sistema operativo y tienen que devolver el estado en el que
terminaron.

0 -> sin error
!=0 -> con error

Es por esto que main debe tener la forma de 
int main(void){return 0;}

PROTOTIPO E INVOCACION

prototipo: deja declarado todo lo necesario para que la funcion ande. Es una ayuda que necesita el
compilador. Debe especificar que devuelve y que valores toma. La necesidad de esto viene del assembler, se
hace para saber cuanto espacio dejar en el Stack.

int suma(int, int)

invocacion: cada instancia en la que se llama a la funcion con ciertos parametros dados y que devuelve un
resultado.


Se puede invocar una funcion pasando como parametro valores en otro tipo de dato (seran casteados)
pero no se puede invocar declarando otro tipo de dato. Ejemplo para aclarar*/

	printf("Ejemplo de casteo en una funcion:\n----------------------------------------\n");
	
	int suma2(char n1, char n2){

		unsigned char bruh = 129, bruhampton = 1;
		int rta;

		rta = suma(bruh,bruhampton);
		printf("%d\n",rta);
		return rta;
	}
return 0;
}

/*Este programa es valido pero no devuelve lo que uno esperaria. Esto se debe a que se castea de char a
unsigned char.


Los parametros de una funcion se pasan POR VALOR. No importa el nombre de la variable. El stack recibe una
copia del valor. Luego existe una variable local resultado que tambien se encuentra en el stack y, por
lo tanto, desaparece cuando termina la funcion. La visibilidad de las variables queda confinada a la funcion.
Esto nos permite repetir nombres en otras funciones.

static permite crear variables que solo esten dentro del scope de una funcion pero que no mueren*/
