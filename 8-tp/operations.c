#include "operations.h"



static double calc_sen(double a);
static double calc_factorial(int a);
static double calc_potencia(double a, int b);



double suma(double a, double b){
    return a+b;	
}

double resta(double a, double b){
    return a-b;
}

double division(double a, double b){
    return a/b;
}

double multiplicacion(double a, double b){
    return a*b;
}

double potencia(double a, double b) {
    return calc_potencia(a, (int) b);
}

static double calc_potencia(double a, int b){
    int i, ans = 1;
    for (i=0; i<b; i++){
        ans *= a;
    }
    return ans;
}

double sen(double a, double b) {
    return calc_sen(a);
}

#define N_TERM 8
static double calc_sen(double a){
    double ans, termino;
    for (int i=0; i<N_TERM; i++) {
        int exp = 2*i + 1;                            //esto calcula el exponente y el argumento del factorial
        termino = calc_potencia(a, exp) / calc_factorial(exp);     //calcula el valor absoluto de cada termino
        if ((i%2) == 0){                              //los terminos pares suman
            ans += termino;
        }
        else {                                        //los terminos impares restan
            ans -= termino;
        }
    }
    return ans;
}

double factorial(double a, double b) {
    return calc_factorial((int) a);
}

static double calc_factorial(int a){
    int ans = 1;                                      //comienza ans en 1 por si quiere calcular 0!
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
