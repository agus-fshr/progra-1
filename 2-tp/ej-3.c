#include <stdio.h>

#define TEMPER 15

int main(void){
	int temp = TEMPER;

	if(30 <= temp && temp <= 90)
		printf("de alta papurri\n");
	else if(15 <= temp && temp < 30)
		printf("media pila\n");
	else if(0 <= temp && temp < 15)
		printf("la baja\n");
	else				/*si es > 90 o < 0*/
		printf("kya\n");

	return 0;

}
