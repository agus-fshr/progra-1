#include<stdio.h>

#define MAX_OPERATORS 3

int add_operation(char o, float (*a) (float, float));
char operators[MAX_OPERATORS] = {'+', '-', '*'};
float (* actions[MAX_OPERATORS]) (float, float);

int main(void) {
    
    // Hacer una función que, en base a un operador, ejecute la acción correspondiente
    // Implementar add_operation, quizás que busque el primer índex vacío y ahí meta lo que se le mete
    // Implementar una función que parsee el input. Un número, un operador, un número
    //  dsp vemos cómo hace para devolver las cosas, pero que las lea por lo menos
    
    
    return 0;
}