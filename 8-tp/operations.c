#include "operations.h"
#include <stdio.h>


static double grad_to_rad(double a);

double sum(double a, double b){
    return a+b;	
}

double substraction(double a, double b){
    return a-b;
}

double division(double a, double b){
    return a/b;
}

double product(double a, double b){
    return a*b;
}

double integer_power(double a, int b){
    int i;
    double ans = 1;
    for (i=0; i<b; i++){
        ans *= a;
    }
    return ans;
}

#define N_TERM 30
double sin(double a){
    double ans = 0, termino = 0;
    double rad = grad_to_rad(a);
    int i;
    for (i=0; i<N_TERM; i++) {
        int exp = 2*i + 1;                            //esto calcula el exponente y el argumento del factorial
        int sign = i%2 == 0 ? 1 : -1;
        termino = sign * integer_power(rad, exp) / factorial(exp);     //calcula el valor absoluto de cada termino
        ans += termino;
    }
    return ans;
}

double cos(double a){
    double ans = 0, termino = 0;
    double rad = grad_to_rad(a);
    int i;
    for (i=0; i<N_TERM; i++) {
        int exp = 2*i;                            //esto calcula el exponente y el argumento del factorial
        int sign = i%2 == 0 ? 1 : -1;
        termino = sign * integer_power(rad, exp) / factorial(exp);     //calcula el valor absoluto de cada termino
        ans += termino;
    }
    return ans;
}

double factorial(unsigned int a){
    double ans = 1;                                      //comienza ans en 1 por si quiere calcular 0!
    int term = a;
    
    if(a < 0) {
        return 0.0/0.0;
    }

    while (term > 1){                                //evita mutiplicar por cero y se detiene en term == 1
        ans = ans * (term);                           //actualiza el valor de ans
        term--;                                       //pasa al siguiente factor del factorial
    }
    return ans;
}

static double grad_to_rad(double a) {
    return a*2.0*PI/360.0;
}