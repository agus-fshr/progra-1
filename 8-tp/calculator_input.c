#include <stdio.h>
#include "calculator_input.h"


static double read_number_stdin(int *error); // Debería estar acá??


// ARREGLADO
    // Teóricamente, esto toma bien algo tipo "    5.312         +123"
    // NO FUNCIONA! Posible solución: leer todo en un string de, qcyo, 80 caracteres? y de ahí interpretar
    // NO FUNCIONA! Posible solución: hacer que las funciones tomen el primer char o algo así
    // NO FUNCIONA! Posible solución: encontrar una funcioón como getchar que no vacíe stdin!
int parse_input(double *op1, double *op2, char *operator) {
    char c = 0;
    int error = 0;
    *operator = OPERATOR_NOT_FOUND;
    // char operando = '\0';
    
    *op1 = read_number_stdin(&error);
    if(error) {
        while(getchar() != '\n'){}
        // TODO: poner todo a 0 aca
        return 0;
    }
    
    while((c = getchar()) == ' ') {}
    *operator = c;

    *op2 = read_number_stdin(&error);
    if(error) {
        return 0;
    }
    return 1;
}

double read_number_stdin(int *error) {              // error acá
    char c;
    double number = 0;
    int is_decimal = 0;
    int decimal_counter = 1;
    int is_negative = 0;
    int char_counter = 0;
    *error = 0;
    
    while((((c = getchar()) != ' ') || (char_counter == 0)) && c != '\n') {
        char_counter++;
        if(c == ' ' && char_counter == 1) { // Elimina espacios al comienzo
            char_counter--;
        }
        else if(c == '-' && char_counter == 1) {
            is_negative = 1;
        } 
        else if(c >= '0' && c <= '9') {
            if(is_decimal == 0) {
                number *= 10.0;
                number += c - '0';
            } else {
                int i;
                double division = c - '0';
                for(i = 0; i < decimal_counter; i++) {
                    division /= 10.0;
                }
                decimal_counter++;
                number += division;
            }
        } 
        else if(c == '.' && is_decimal == 0) {
            is_decimal = 1;
        }
        else {
            *error = 1;
        }
    }
    
    if(is_negative) {
        number *= -1;
    }
    
    return number;
}