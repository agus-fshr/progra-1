/*
Flujo de Programa:
---------------------------------------

BLOQUE IF
El bloque if, como su nombre lo indica, permite la ejecucion condicional de una
expresion. A continuacion se muestra la sintaxis:

if  (condicion)
	expresion;

Junto con el bloque if, viene el bloque ELSE. Este se ejecuta en el caso contrario de
la condicion del IF*/

#include <stdio.h>
int main (void){
	int a = -5;
	printf("Ejemplo de un IF basico\n-------------------------------\n");
	printf("Se inicia a con un valor de %d\n", a);
	if (a>0)
		printf("a es positivo\n");
	else
		printf("a es negativo\n");
/*Tambien existe el bloque IF-ELSEIF. Esto permite anidar condiciones, tiene la
sintaxis que se muestra a continuacion

if (cond1)
	expr1;
else if (cond2)
	expr2;
else
	expr3

un ejemplo*/

	int b = 0;
	printf("\n\nEjemplo de un IF con ELSE IF\n--------------------------------------\n");
	printf("Se inicia la variable b con un valror de %d\n", b);
	if (b>0)
		printf("b es positivo\n");
	else if (b==0)
		printf("b es cero\n");
	else
		printf("b es negativo\n");

/*Tambien se puede anidar bloques condicionales:
if (device_moves == 0)
	if (device_should_move == 0)
		printf("No problem\n");
	else
		printf("use silver tape\n");
else
	if (device_should_move != 0)
		printf("no problem\n");
	else
		printf("use wd40\n");

Para incluir mas de una instruccion en un if, se usan llaves

int signo;
if (a>=0) {
	printf("a es positivo\n");
	signo = 1;
}
else {
	printf("a es negativo");
	signo = -1;
}



SWITCH-CASE

El bloque switch-case tiene como principal uso la evaluacion de varias opciones
discretas. Tiene como objetivo el reemplazo de ciertos casos de los bloques de
if ... else if ... else

Su forma basica es la siguiente

switch (variable){
	case cond_cte1: expressions; break;
	case cond_cte2: expressions; break;
	default: expressions; break;
}
El valor de la variable sera comparado contras las condiciones constantes para
determinar cual expresion se ejecutara. Las condiciones deben ser distintas entre
si, y si bien pueden tomar la forma de expresiones, deben ser definidas en "tiempo 
de compilacion (es decir que solo pueden depender de otras constantes)

El caso default se ejecutara cuando la expresion no se corresponda con ninguna de
la condiciones anteriores."
*/

int c = 1;
printf("\n\nAhora viene el ejemplo con SWITCH-CASE\n-------------------------\n");
printf("Se inicia c con un valor de %d\n", c);
switch (c) {
	case 0:
		printf("c vale cero\n");
		break;
	case 1:
		printf("c vale 1\n");
		break;
	case 2:
		printf("c vale 2\n");
		break;
	default:
		printf("c no vale ni 1, ni 2, ni 0\n");
		break;
}
/*El bloque WHILE se ejecuta mientras la expresion sea verdadera y luego se
reevalua, si es falsa, se saltea. Un ejemplo que escribe los nros del 1 al 10*/
printf("\n\nAhora un ejemplo con WHILE\n---------------------------------\n");
int d = 1;
printf("Se inicia d con un valor de %d\n", d);
while (d<=10){
printf("%d\n", d++);
}
/*El bloque FOR tiene como objetivo la repeticion de un segmento de codigo una
determinada cantidad de veces. La forma basica del mismo es...

for (exp1;exp2;exp3)
	exp4;

La exp1 se considera la inicializacion, la exp2 es la a evaluar, la exp3 es la que se
relaciona con la actualizacion del contador asociado. Si se dejan vacias, se ejecuta
infinitamente la exp4.

El lenguaje C tiene un operador break para romper el ciclo en la linea en que se
encuentra. Se sale del ciclo mas interno donde se encuentre en break.

El operador continue, por el contrario, hace saltar "a la exp3", es decir, deja de
ejecutar las expresiones y vuelve a la condicion para evaluar el siguiente loop.


BUENAS PRACTICAS:
-evitar el uso de break y continue
-evitar usar la directiva goto
*/
	return 0;
}
