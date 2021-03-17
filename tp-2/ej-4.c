#include <stdio.h>

int main(void) {
	int a = 0;
	printf("Hecho con un while\n---------------------------\n");

	while (a < 10)
		printf("%d  ",a++);
	printf("\n\n");


	printf("Hecho con un for\n---------------------------\n");

	for(a=0; a<10; a++)
		printf("%d  ",a);
	printf("\n");

	return 0;

}
