#include "operations.h"


float suma(float a, float b){
		return a+b;	
}

float resta(float a, float b){
		return a-b;
}

float division(float a, float b){
		return a/b;
}

float mutiplicacion(float a, float b){
		return a*b;
}

float potencia(float a, int b){
		int i, ans = 1;
		for (i=0; i<b; i++){
				ans *= a;
		}
		return ans;
}

#define N_TERM 8
float sen(float a){
    float ans, termino;
    for (int i=0; i<N_TERM; i++) {
        int exp = 2*i + 1;                            //esto calcula el exponente y el argumento del factorial
        termino = potencia(a, exp) / factorial(exp);     //calcula el valor absoluto de cada termino
        if ((i%2) == 0){                              //los terminos pares suman
            ans += termino;
        }
        else {                                        //los terminos impares restan
            ans -= termino;
        }
    }
    return ans;
}

float factorial(int a){
    int ans = 1;                                      //comienza ans en 1 por si quiere calcular 0!
    int term = a;
    while (term != 1){                                //evita mutiplicar por cero y se detiene en term == 1
        ans = ans * (term);                           //actualiza el valor de ans
        term--;                                       //pasa al siguiente factor del factorial
    }
    return ans;
}

