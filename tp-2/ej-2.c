#include <stdio.h>

int main(void){

	int x = 5;
	while(x > 0);
	printf("%d", x--);
	return 0;

}


/*no imprime nada porque tiene un ; despues del while, cosa que hace que
no salga nunca del mismo*/
