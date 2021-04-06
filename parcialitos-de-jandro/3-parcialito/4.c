#include <stdio.h>

#define M 5

double entrada[][M];

double valor_absoluto(double);
double norma_1(int);

int la_funcion(double entrada[][M], n){
	float current_max = norma_1;
	int current_winner = 0;
	for (int b = 0; b<=(n-1); b++) {
		if (norma_1(b)>current_max){
			current_max = norma_1(b);
			current_winner = b;
		}
	}
	return current_winner;
}

double norma_1(int n){
	double resultado = 0;
	for (int i = 0; i<=(M-1); i++){
		resultado += valor_absoluto(entrada[n][i]);
	}
}


double valor_absoluto(double x) {
	if(x<0){
		return -x;
	}
	else{
		return x;
	}
	
}
