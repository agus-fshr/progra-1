/******************************************************************************
  @file     main.c
  @brief    Implements a calculator
  @author   Grupo 7
 ******************************************************************************/

/*
 *  TP8 - Ejercicio 5 - Grupo 7 (FISHER, MARTINEZ TANOIRA, SBRUZZI, OMS)
 *
 *  Consigna:
 *      Implementar una calculadora simple, a la que se le puedan ir agregando nuevas funciones. 
 *      Se generarán dos arreglos (globales): uno contendrá operandos, 
 *      y el otro punteros a la función que debe realizar ese operando, que se completarán de manera dinámica 
 *      al inicializarse el programa.Se le solicitará al usuario que ingrese la cuenta que desea realizar, 
 *      de la forma xxxx operador yyyy (ejemplo: 5 + 3)Finalmente deberá mostrar el resultado obtenido.
 *      La calculadora debe implementar como mínimo: suma, resta, multiplicación, división 
 *      y potenciación(puede implementarse solo para exponentes enteros).
 *
 *  Implementación:
 *      1) Se implementan las funciones suma, resta, division, multiplicacion,
 *          factorial, coseno, seno.
 *      2) Para las funciones matemáticas de un solo parámetro, se utiliza únicamente
 *          el primero (de la izquierda).
 *      3) Se permite calcular indefinidamente hasta ingresar una secuencia de escape
 *      4) El programa propone ayudas cuando hay problemas en la entrada.
 */

#include<stdio.h>
#include "operations.h"
#include "calculator_front.h"

#define MAX_OPERATORS 8


int find_operator(char c);
int add_operation(char o, double (*a) (double, double));

double integer_power_wrapper(double a, double b);
double factorial_wrapper(double a, double b);
double sin_wrapper(double a, double b);
double cos_wrapper(double a, double b);

//char operators[MAX_OPERATORS] = {'+', '-', '*'};
//double (* actions[MAX_OPERATORS]) (double, double);
double (*actions[MAX_OPERATORS]) (double, double);
char operators[MAX_OPERATORS];


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
