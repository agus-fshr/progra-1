#include <stdio.h>

int main() {

	int M[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	for (int n = 0; n<=2; n++){
		for (int m = 0; m<=2; m++){
			printf("%d  ",M[n][m]);
		}
		printf("\n");
	}
}
