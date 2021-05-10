/*****************************************************************************
  @file     operations.c
  @brief    Mathematical functions (.c)
  @author   Grupo 7
 ******************************************************************************/


/************************
 * INCLUDE HEADER FILES *
 ************************/
#include "operations.h"
#include <stdio.h>



/******************************************
 * CONSTANT AND MACRO DEFS USING #DEFINE  *
 ******************************************/
/// The number of terms to approximate to when using Taylor expansion
#define TAYLOR_TERMS 30 



/*******************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE *
 *******************************************************************/
/**
 * @brief Converts number in degrees to radians
 * @param deg number in degrees to convert
 * @return The number converted to radians
 */ 
static double deg_to_rad(double deg);


/**
 * @brief Converts number in degrees to equivalent in first cycle
 * @param deg number in degrees to convert
 * @return The number in [0, 360]
 */ 
static double deg_to_first_cycle(double deg);


/******************************************
 ******************************************
 **     GLOBAL FUNCTION DEFINITIONS      **
 ******************************************
 ******************************************/

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

double integer_power(double base, int exp){
    int i;
    double ans = 1;
    int mod_exp = exp >= 0 ? exp : -exp;
    for (i=0; i<mod_exp; i++){
        ans *= base;       // Multiplies the base by itself exp times
    }
    if(exp < 0) {
        ans = 1 / ans;
    }
    return ans;
}

double sin(double a){
    double ans = 0, termino = 0;
    double radian_num = deg_to_rad(deg_to_first_cycle(a));
    int i;
    for (i=0; i<TAYLOR_TERMS; i++) {    // sin(a) = sum((-1)^n * a^(2n+1)/((2n+1)!))
        int sign = i%2 == 0 ? 1 : -1;   // (-1)^n
        termino = sign * integer_power(radian_num, 2*i + 1) / factorial(2*i + 1);
        ans += termino;
    }
    return ans;
}

double cos(double a){
    double ans = 0, termino = 0;
    double radian_num = deg_to_rad(deg_to_first_cycle(a));
    int i;
    for (i=0; i<TAYLOR_TERMS; i++) {    // sin(a) = sum((-1)^n * a^(2n+1)/((2n+1)!))
        int sign = i%2 == 0 ? 1 : -1;   // (-1)^n
        termino = sign * integer_power(radian_num, 2*i) / factorial(2*i);     //calcula el valor absoluto de cada termino
        ans += termino;
    }
    return ans;
}

double factorial(unsigned int a){
    double ans = 1;
    int term = a;

    while (term > 1){       // avoids multiplying by 0 and stops when term == 1
        ans = ans * (term);
        term--;
    }
    return ans;
}



/******************************************
 ******************************************
 **      LOCAL FUNCTION DEFINITIONS      **
 ******************************************
 ******************************************/
static double deg_to_rad(double deg) {
    return deg*2.0*PI/360.0;
}

static double deg_to_first_cycle(double deg) {
    // Reduces the angle by the max amount of cycles
    return deg - 360.0*((long long int)(deg / 360.0)); 
}