#include<stdio.h>
#include "operations.h"

#define OPERATOR_NOT_FOUND -1
#define MAX_OPERATORS 7
#define IS_NUM(c) ((c) >= '0' && (c) <= '9')

int add_operation(char o, float (*a) (float, float));
int parse_input(float *op1, float *op2, int *operator);
int is_operator(char c);
double read_number_stdin(int *error);
char delete_spaces_stdin(void);


//char operators[MAX_OPERATORS] = {'+', '-', '*'};
//float (* actions[MAX_OPERATORS]) (float, float);
float (*actions[MAX_OPERATORS]) (float, float);
char operators[MAX_OPERATORS];

/*
 * MENSAJE FUTURO:
 * Decidir qué hacer con las funciones que toman un solo
 * parámetro: hacer la adaptación a (float, float) en el main o
 * en el módulo operations?
 * 
 * MENSAJE FUTURO V2:
 * Con lo que solo toma enteros, qué se hace ante la falta de respeto
 * de que se presente un NUMERO CON COMA. A la hoguera? Mje de error?
 * Redondeo discretito?
 */


int main(void) {
    printf("Buenas!\n");
    // Hacer una función que, en base a un operador, ejecute la acción correspondiente
    // Implementar add_operation, quizás que busque el primer índex vacío y ahí meta lo que se le mete
    // Implementar una función que parsee el input. Un número, un operador, un número
    //  dsp vemos cómo hace para devolver las cosas, pero que las lea por lo menos
    // add_operation('+', suma);
    add_operation('+', suma);
    add_operation('-', resta);
    add_operation('/', division);
    add_operation('*', multiplicacion);
    add_operation('^', potencia);
    add_operation('!', factorial);
    add_operation('s', sen);

    float op1, op2;
    int operation;

    printf("Ingrese la operacion en formato \"xxxx operador yyyy\": \n");
    while(!parse_input(&op1, &op2, &operation) || operation == OPERATOR_NOT_FOUND) {
        printf("Ingrese una operacion valida en formato \"xxxx operador yyyy\":\n");
        if(operation == OPERATOR_NOT_FOUND){
            printf("Los operadores disponibles son:");
            int i;
            for(i = 0; i < MAX_OPERATORS; i++) {
                printf(" %c", operators[i]);
            }
        }
    }
    /*
    int i = 0;
    while(operators[i] != operation){
        i++;
    }
    */
    printf("Se realizara la operacion %c sobre %f y %f\n", operators[operation], op1, op2);
    printf("Resultado: %f", actions[operation](op1, op2));

    // float result = (*actions[i]) (a,b);
    return 0;
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
            return i;
        }
    }
    return OPERATOR_NOT_FOUND;
}

// ARREGLADO
    // Teóricamente, esto toma bien algo tipo "    5.312         +123"
    // NO FUNCIONA! Posible solución: leer todo en un string de, qcyo, 80 caracteres? y de ahí interpretar
    // NO FUNCIONA! Posible solución: hacer que las funciones tomen el primer char o algo así
    // NO FUNCIONA! Posible solución: encontrar una funcioón como getchar que no vacíe stdin!
int parse_input(float *op1, float *op2, int *operator) {
    char c = 0;
    int error = 0;
    int operator_found = 0;
    *operator = OPERATOR_NOT_FOUND;
    // char operando = '\0';
    
    *op1 = read_number_stdin(&error);
    if(error) {
        while(getchar() != '\n'){}
        // TODO: poner todo a 0 aca
        return 0;
    }
    
    while(!operator_found && c != ' ') {
        if(is_operator(c) != OPERATOR_NOT_FOUND) {
            *operator = is_operator(c);
            operator_found = 1;
        } else {
            c = getchar();
        }
    }
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

char delete_spaces_stdin(void) {
    char c;
    while((c = getchar()) == ' '){}
    return c;
}