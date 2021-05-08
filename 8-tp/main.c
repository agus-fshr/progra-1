#include<stdio.h>
#include "operations.h"

#define MAX_OPERATORS 3
#define IS_NUM(c) ((c) >= '0' && (c) <= '9')

int add_operation(char o, float (*a) (float, float));
double suma(double a, double b);
int parse_input(int *op1, int *op2, char *operator);
int is_operator(char c);
double read_number_stdin(int *error);
char delete_spaces_stdin(void);

//char operators[MAX_OPERATORS] = {'+', '-', '*'};
//float (* actions[MAX_OPERATORS]) (float, float);
double (*actions[MAX_OPERATORS]) (float, float);
char operators[MAX_OPERATORS];


int main(void) {
    
    // Hacer una función que, en base a un operador, ejecute la acción correspondiente
    // Implementar add_operation, quizás que busque el primer índex vacío y ahí meta lo que se le mete
    // Implementar una función que parsee el input. Un número, un operador, un número
    //  dsp vemos cómo hace para devolver las cosas, pero que las lea por lo menos
    add_operation('+', suma);

    return 0;
}

double suma(double a, double b) {
    return a+b;
}

int add_operation(char o, float (*a) (float, float)){
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

int is_operator(char c) {
    int i;
    for (i = 0; i < MAX_OPERATORS; i++) {
        if(c == operators[i]) {
            return 1;
        }
    }
    return 0;
}

// Teóricamente, esto toma bien algo tipo "    5.312         +123"
// NO FUNCIONA! Posible solución: leer todo en un string de, qcyo, 80 caracteres? y de ahí interpretar
// NO FUNCIONA! Posible solución: hacer que las funciones tomen el primer char o algo así
// NO FUNCIONA! Posible solución: encontrar una funcioón como getchar que no vacíe stdin!
int parse_input(int *op1, int *op2, char *operator) {
    char c;
    int *error = 0;
    char operando = '\0';
    
    *op1 = read_number_stdin(error);
    if(error) {
        return 0;
    }
    
    c = delete_spaces_stdin();
    while(c != '\n'&& !operando) {
        if(is_operator(c)) {
            operando = c;
        }
        c = getchar();
    }
    
    *op2 = read_number_stdin(error);
    if(error) {
        return 0;
    }
}

double read_number_stdin(int *error) {
    char c;
    double number = 0;
    int is_decimal = 0;
    int decimal_counter = 1;
    int is_negative = 0;
    int char_counter = 0;

    while((c = getchar()) != '\n') {
        char_counter++;
        
        if(c == ' ' && char_counter == 1) { // Elimina espacios al comienzo
            char_counter--;
        }
        if(c == '-' && char_counter == 1) {
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
            return 0.0;
        }
    }
    
    if(is_negative) {
        number *= -1;
    }

    *error = 0;
    return number;
}

char delete_spaces_stdin(void) {
    char c;
    while((c = getchar()) == ' '){}
    return c;
}