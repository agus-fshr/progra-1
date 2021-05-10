/*****************************************************************************
  @file     calculator_front.c
  @brief    Front-end of the calculator (.c)
  @author   Grupo 7
 ******************************************************************************/

/************************
 * INCLUDE HEADER FILES *
 ************************/
#include <stdio.h>
#include <stdlib.h>
#include "calculator_front.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define IS_NUM(c) (((c) >= '0') && ((c) <= '9'))
#define ASCII_TO_NUM(c) ((c) - '0')


/*******************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE *
 *******************************************************************/
/**
 * @brief Reads a number from stdin
 * @param error Pointer to int variable storing error code
 * @return The read number
 */ 
static double read_number_stdin(int *error);


/**
 * @brief Divides a number a certain amount of times
 * @param num The number to divide
 * @param times The times to divide by 10
 * @return The number divided
 */ 
static double divide_by_10_n_times(int num, int times);


/******************************************
 ******************************************
 **     GLOBAL FUNCTION DEFINITIONS      **
 ******************************************
 ******************************************/

int parse_input(double *op1, double *op2, char *operator) {
    char c = 0;
    int error = 0;
    *operator = OPERATOR_NOT_FOUND;
    
    *op1 = read_number_stdin(&error);   // reads the first number

    if(error) {             // if something went wrong
        flush_stdin('\n');  // emtpies stdin
        return 0;           // returns with error
    }
    
    while((c = getchar()) == ' ') {}    // ignores trailing spaces on the number
    
    *operator = c;  // the first char found after the spaces is the operator

    *op2 = read_number_stdin(&error);   // reads the second number
    if(error) {         // if something went wrong
        return 0;       // returns with error
    }
    return 1;           // returns without error
}

void print_calculator_tips(void) {
    printf("Tips de uso:\n");
    printf("\t-Es obligatorio un espacio de cada lado del operador, de lo contrario el comportamiento es indefinido.\n");
    printf("\t-Solo es obligatorio el primer operando, el segundo, si se omite, se asume 0.\n");
    printf("\t-Los operadores trigonometricos operan en grados, no radianes.\n");
    printf("\t-Para los operadores de un solo parametro, debe ingresar por lo menos el izquierdo.\n");
    printf("\t-La calculadora truncara a enteros todos los valores que no deberian ser decimales\n");
    printf("\t\t(por ejemplo, los exponentes).\n");
    printf("\t-Si recibe el valor -1.#IND00, se intento realizar una operacion con valores absurdos.\n");
    printf("\t-Si recibe el valor -1.#INF00, se provoco una indeterminacion tendiente a inf,\n");
    printf("\t\tquizas dividiendo por 0, o provocando un numero demasiado grande.\n");
}

void print_operators(char operators[], int op_num) {
    printf("Los operadores disponibles son:");
    int i;
    for(i = 0; i < op_num; i++) {
        printf(" %c", operators[i]);
    }
    putchar('\n');
}

void print_operation_result(double op1, double op2, char operation, double result) {
    printf("%f %c %f = %f\n", op1, operation, op2, result);
}

void clear_screen(void) {
    system("cls || clear");
}

void flush_stdin(char limit) {
    char c;
    // Until it gets to the desired char, empties stdin
    while((c=getchar()) != limit) {}
}


/******************************************
 ******************************************
 **      LOCAL FUNCTION DEFINITIONS      **
 ******************************************
 ******************************************/


/*
 * Notes about the implementation:
 * This functions reads chars from stdin with the objective
 * of parsing a number, considering negatives and decimals.
 * Also, it throws away any left padding with spaces.
 */
static double read_number_stdin(int *error) {
    char c;
    double number = 0;
    int is_decimal = 0;
    int decimal_counter = 1;
    int is_negative = 0;
    int char_counter = 0;
    *error = 0;                         // by default, there is no error
    
    // Continues reading chars until a space (after the initial padding) or a '\n' are found
    while((((c = getchar()) != ' ') || (char_counter == 0)) && c != '\n') {
        char_counter++;
        if(c == ' ' && char_counter == 1) { 
            char_counter--;             // Ignores left padding spaces
        }
        else if(c == '-' && char_counter == 1) {    
            is_negative = 1;            // Handles sign if there is a minus first
        } 
        else if(IS_NUM(c)) {            // If the char is a number
            if(is_decimal == 0) {
                number *= 10.0;         // if it's not decimal, adds the number
                                        // to 10 times the prev value
                number += ASCII_TO_NUM(c);
            } else {
                // if it's decimal, adds the number adjusted to the next
                // decimal position
                number += divide_by_10_n_times(ASCII_TO_NUM(c), decimal_counter++);
            }
        } 
        else if(c == '.' && is_decimal == 0) {
            is_decimal = 1;     // if the read char is '.' for the first time, the next are decimals
        }
        else {                  // if anything else was input, there is an error
            *error = 1;         // anyway, it will continue reading until ' ' or '\n' is reached
        }
    }
    
    if(is_negative) {
        number *= -1;
    }
    
    return number;
}

static double divide_by_10_n_times(int num, int times) {
    int i;
    double division = num;      // starting value
    for(i = 0; i < times; i++) {
        division /= 10.0;       // divides by 10 'times' times
    }
    return division;
}