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
 *      4) Se reduce de manera dinámica el argumento de las funciones basadas en polin.
 *          de taylor para aproximarlo al centro, en 0.
 *      5) Las funciones trigonometricas están probadas con ángulos de hasta 21 dígitos.
 *      6) El factorial más alto es el 170!
 *      7) Se truncan aquellos valores que se requieren de manera entera.
 */


/******************************************
 *          INCLUDE HEADER FILES          *
 *****************************************/
#include<stdio.h>
#include "operations.h"
#include "calculator_front.h"


/************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE *
 ************************************************/

#define MAX_OPERATORS 8 ///< Number of operators

#define EXIT_CHAR 'q'
#define HELP_CHAR '?'
#define SUM_CHAR  '+'
#define SUBS_CHAR '-'
#define DIV_CHAR  '/'
#define PROD_CHAR '*'
#define POW_CHAR  '^'
#define FACT_CHAR '!'
#define SIN_CHAR  's'
#define COS_CHAR  'c'

#define TAN_CHAR  't' ///< unused
#define ASIN_CHAR 'a' ///< unused
#define ACOS_CHAR 'b' ///< unused
#define ATAN_CHAR 'd' ///< unused


/***********************
 * FUNCTION PROTOTYPES *
 ***********************/


/**
 * @brief Finds the index of the operator represented by a char
 * @param c The identifier of the operator to search for
 * @return The operation index
 */ 
int find_operator(char c);


/**
 * @brief Adds an operator to the array
 * @param operator_char The char represeting the operation
 * @param callback The function to associate to the operator
 * @return 1 if succesful, 0 otherwise
 */ 
int add_operation(char operator_char, double (*callback) (double, double));


/**
 * @brief Wraps power function due to formatting
 * @param a Left operand (base)
 * @param b Right operand (exponent)
 * @return Result of a^b
 */ 
double integer_power_wrapper(double a, double b);


/**
 * @brief Wraps factorial function due to formatting
 * @param a Left operand (to take the factorial of)
 * @param b Right operand (nothing)
 * @return Result of a!
 */ 
double factorial_wrapper(double a, double b);


/**
 * @brief Wraps sin function due to formatting
 * @param a Left operand (to calc sin of)
 * @param b Right operand (nothing)
 * @return Result of sin(a)
 */ 
double sin_wrapper(double a, double b);


/**
 * @brief Wraps cos function due to formatting
 * @param a Left operand (to calc cos of)
 * @param b Right operand (nothing)
 * @return Result of cos(a)
 */ 
double cos_wrapper(double a, double b);


/********************
 * GLOBAL VARIABLES *
 ********************/
double (*actions[MAX_OPERATORS]) (double, double);
char operators[MAX_OPERATORS];


/********************
 *       MAIN       *
 ********************/
int main(void) {
    int initial_err = 1;
    initial_err *= add_operation(SUM_CHAR, sum);
    initial_err *= add_operation(SUBS_CHAR, substraction);
    initial_err *= add_operation(DIV_CHAR, division);
    initial_err *= add_operation(PROD_CHAR, product);
    initial_err *= add_operation(POW_CHAR, integer_power_wrapper);
    initial_err *= add_operation(FACT_CHAR, factorial_wrapper);
    initial_err *= add_operation(SIN_CHAR, sin_wrapper);
    initial_err *= add_operation(COS_CHAR, cos_wrapper);

    if(initial_err == 0) {
        printf("Algo ha fallado en la etapa de configuracion. Lo sentimos! :c\n");
        return 0;
    }

    double op1, op2;
    char operation_char;
    int operation_index = OPERATOR_NOT_FOUND;
    int valid_input = 0;
    int exit = 0;
    
    clear_screen();

    printf("Bienvenido! Esto es una calculadora.\n");
    print_calculator_tips();

    while(!exit) {
        while(!valid_input && !exit){
            printf("Ingrese una operacion valida en formato \"X operador Y\", \"X %c Y\" para ayuda, o \"X %c Y\" para salir:\n", HELP_CHAR, EXIT_CHAR);
            valid_input = parse_input(&op1, &op2, &operation_char);
            if((operation_index = find_operator(operation_char)) == OPERATOR_NOT_FOUND) {
                valid_input = 0;        // if the op was not found the input was not valid
                if(operation_char == HELP_CHAR){
                    print_operators(operators, MAX_OPERATORS);
                    print_calculator_tips();
                } else if (operation_char == EXIT_CHAR) {
                    exit = 1;       // exits the calculator
                }
            }
        }
        if(!exit) {
            double result = actions[operation_index](op1, op2);
            printf("= %.10g\n", result); // Uses exponent notation when convenient
            valid_input = 0;    // Takes next input
        }
    }
    
    clear_screen();

    printf("Hasta la proxima!\n");
    
    return 0;
}


int add_operation(char operator_char, double (*callback) (double, double)){
    int i;
    for(i = 0; i < MAX_OPERATORS; i++) {
        if(actions[i] == NULL) {    // Empty space found!
            actions[i] = callback;         // add action
            operators[i] = operator_char;       // add operator char
            return 1;               // return without error
        }
    }
    return 0;           // No empty space found, return with error
}

int find_operator(char c) {
    int i;
    for (i = 0; i < MAX_OPERATORS; i++) {
        if(c == operators[i]) {     // Operator matches char
            return i;               // return index
        }
    }
    return OPERATOR_NOT_FOUND;      // returns with error
}

double integer_power_wrapper(double a, double b) {
    return integer_power(a, (int) b);
}

double factorial_wrapper(double a, double b) {
    if (a >= 0) {
        return factorial((int) a);
    }
    return 0.0/0.0; // If input is invalid, returns NaN
}

double sin_wrapper(double a, double b) {
    return sin(a);
}

double cos_wrapper(double a, double b) {
    return cos(a);
}
