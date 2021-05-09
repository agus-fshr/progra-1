#include<stdio.h>
#include "operations.h"
#include "calculator_front.h"

#define MAX_OPERATORS 8


int find_operator(char c);
int add_operation(char o, double (*a) (double, double));

//char operators[MAX_OPERATORS] = {'+', '-', '*'};
//double (* actions[MAX_OPERATORS]) (double, double);
double (*actions[MAX_OPERATORS]) (double, double);
char operators[MAX_OPERATORS];

/*
 * MENSAJE FUTURO:
 * Decidir qué hacer con las funciones que toman un solo
 * parámetro: hacer la adaptación a (double, double) en el main o
 * en el módulo operations?
 * Opinión de juan: va en el main pq el módulo operations solo tiene que
 * tener operaciones matemáticas para ser del todo MoDUlAr.
 * 
 * MENSAJE FUTURO V2:
 * Con lo que solo toma enteros, qué se hace ante la falta de respeto
 * de que se presente un NUMERO CON COMA. A la hoguera? Mje de error?
 * Redondeo discretito?
 */

double integer_power_wrapper(double a, double b) {
    return integer_power(a, (int) b);
}

double factorial_wrapper(double a, double b) {
    return factorial((int) a);
}

double sin_wrapper(double a, double b) {
    return sin(a);
}

double cos_wrapper(double a, double b) {
    return cos(a);
}

int main(void) {
    printf("Buenas!\n");
    // Hacer una función que, en base a un operador, ejecute la acción correspondiente
    // Implementar add_operation, quizás que busque el primer índex vacío y ahí meta lo que se le mete
    // Implementar una función que parsee el input. Un número, un operador, un número
    //  dsp vemos cómo hace para devolver las cosas, pero que las lea por lo menos
    // add_operation('+', suma);
    add_operation('+', sum);
    add_operation('-', substraction);
    add_operation('/', division);
    add_operation('*', product);
    add_operation('^', integer_power_wrapper);
    add_operation('!', factorial_wrapper);
    add_operation('s', sin_wrapper);
    add_operation('c', cos_wrapper);

    double op1, op2;
    char operation_char;
    int operation_index = OPERATOR_NOT_FOUND;
    int valid_input = 0;
    int exit = 0;
    
    while(!exit) {
        while(!valid_input){
            printf("Ingrese una operacion valida en formato \"xxxx operador yyyy\", \"0 ? 0\" para ayuda o \"0 q 0\" para salir:\n");
            valid_input = parse_input(&op1, &op2, &operation_char);
            if((operation_index = find_operator(operation_char)) == OPERATOR_NOT_FOUND) {
                valid_input = 0;
                if(operation_char == '?'){
                    printf("Los operadores disponibles son:");
                    int i;
                    for(i = 0; i < MAX_OPERATORS; i++) {
                        printf(" %c", operators[i]);
                    }
                    putchar('\n');
                    printf("Recuerde que los operadores trigonometricos operan en grados, no radianes.\n");
                } else if (operation_char == 'q') {
                    exit = 1;
                }
            }
        }
        //printf("Se realizara la operacion %c sobre %f y %f\n", operators[operation_index], op1, op2);
        printf("Resultado: %f\n", actions[operation_index](op1, op2));
        valid_input = 0;
    }
    printf("Hasta la proxima!");
    /*
    int i = 0;
    while(operators[i] != operation){
        i++;
    }
    */
    

    // double result = (*actions[i]) (a,b);
    return 0;
}


int add_operation(char o, double (*a) (double, double)){
    int i;
    for(i = 0; i < MAX_OPERATORS; i++) {
        if(actions[i] == NULL) {
            actions[i] = a;
            operators[i] = o;
            return 1;
        }
    }
    return 0;
}

int find_operator(char c) {
    int i;
    for (i = 0; i < MAX_OPERATORS; i++) {
        if(c == operators[i]) {
            return i;
        }
    }
    return OPERATOR_NOT_FOUND;
}

