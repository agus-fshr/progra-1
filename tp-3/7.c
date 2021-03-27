#include <stdio.h>

#define NRO_DE_TERMS 500

double potencia(double base, int exponente) {
    int i;
    double resultado = 1;
    for(i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

double factorial(int numero) {
    int i;
    double resultado = 1;
    if(numero >= 0) {
        for(i = numero; i > 0; i--) {
            resultado *= i;
        }
    }
    return resultado;
}

double polin_taylor(float x, int num_terminos) {
    double ans = 0;
	int term;
    for(term = num_terminos; term >= 0; term--){
        ans += potencia(x, term)/factorial(term);
    }
    return ans;
}

int main(void) {
    double x = 0.5;

    double respuesta = polin_taylor(x, NRO_DE_TERMS);

    printf("e^(%f) da aproximadamente %.10f\n", x, respuesta);

    return 0;
}
