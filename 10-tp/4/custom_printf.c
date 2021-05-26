/******************************************************************************
  @file     custom_printf.h
  @brief    Module file for custom printf function
  @author   Grupo 7 Inc.
 *****************************************************************************/

/******************************************************************************
 * INCLUDE HEADER FILES
 *****************************************************************************/

#include <stdarg.h>
#include <stdio.h>
#include "custom_printf.h"


/******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 *****************************************************************************/

// Char to separate integer from decimal when printing doubles
#define DOUBLE_DEC_SEP  '.'

// Decimal digits to print. Can't be greater than 10
#define DOUBLE_DEC_DIGITS 6

#define DECIMAL_BASE 10
#define HEXA_BASE 16
#define OCTAL_BASE 8
#define BINARY_BASE 2


/******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 *****************************************************************************/

/**
 * @brief Prints a double precision number to stdio
 * @param num Number to print
*/
static void print_double(double num);


/**
 * @brief Prints the base-specific representation of an unsigned integer
 * @param num Number to print
 * @param base Numeral base in which the num is represented
 * @param lowercase If the base needs alphanumerical chars,
 *  0 prints them in uppercase, lowercase otherwise
 * @note base won't work with values bigger than 10 + 25 
 *  (the number of ASCII letters + the number of decimal numbers)
*/
static void print_int_to_base(unsigned int num, unsigned int base, int lowercase);


/**
 * @brief Calculates base^exp
 * @param base Base to calc the power of
 * @param exp Exponent
*/
static double int_power(unsigned int base, unsigned int exp);



/******************************************************************************
 ******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 ******************************************************************************
 *****************************************************************************/

void my_printf(char *str, ...) {
    char *p_str = str;
    va_list param_list;
    va_start(param_list, str);
    
    while(*p_str){
        if(*p_str == '%'){          // if a '%' was found
            switch(*(++p_str)) {    // check the next char
                case 'i':
                case 'd': {
                    int val = va_arg(param_list, int);
                    if(val < 0) {           // handle sign
                        putchar('-');
                        val = -val;
                    }
                    print_int_to_base((unsigned int) val, DECIMAL_BASE, 0);
                    break;
                }
                case 'u': {
                    print_int_to_base((unsigned int) va_arg(param_list, int), DECIMAL_BASE, 0);
                    break;
                }
                case 'x': {
                    // print lowercase hexadecimal number
                    print_int_to_base((unsigned int) va_arg(param_list, int), HEXA_BASE, 1);
                    break;
                }
                case 'X': {
                    // print uppercase hexadecimal number
                    print_int_to_base((unsigned int) va_arg(param_list, int), HEXA_BASE, 0);
                    break;
                }
                case 'o': {
                    // print octal number
                    print_int_to_base((unsigned int) va_arg(param_list, int), OCTAL_BASE, 0);
                    break;
                }
                case 'B':
                case 'b': {
                    print_int_to_base((unsigned int) va_arg(param_list, int), BINARY_BASE, 0);
                    break;
                }
                case 'c': {
                    // print char
                    putchar(va_arg(param_list, int));
                    break;
                }
                case 'f': {
                    // print double precision floating point number
                    print_double(va_arg(param_list, double));
                    break;
                }
                case '%': {
                    // "%%" prints a single %
                    putchar('%');
                    break;
                }
                default:
                    // If the char next to % is not recognized, do nothing
                    break;
            }
        } else {
            putchar(*p_str);    // if the current char isn't %, print it
        }
        
        p_str++;                // check next char
    }
    
    va_end(param_list);
}



/******************************************************************************
 ******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 ******************************************************************************
 *****************************************************************************/


static void print_int_to_base(unsigned int num, unsigned int base, int lowercase) {
    int remainder;

    if(num == 0) {
        putchar('0');   // if num passed is exactly 0, print 0
    }

    // if the next division of the number is 0, the printing has ended
    if(num/base == 0) {
        return;     // "base case"
    } else {
        // print next division of the number
        print_int_to_base(num/base, base, lowercase);
    }

    remainder = num % base;
    if(remainder <= 9){             // print ascii number
        putchar(remainder + '0');
    } else if((remainder - 10) <= ('Z' - 'A')) {    
        // if remainder is bigger that 10, but less than 10 + the number of possible letters
        putchar((remainder - 10) + (lowercase ? 'a' : 'A'));
    }
}


static void print_double(double num) {
    unsigned int integer_part;
    unsigned int decimal_part;
    if(num < 0) {       // handle sign
        num = -num;
        putchar('-');
    }

    integer_part = (unsigned int) num;  // erase decimal part
                                        // for the decimal_part, erase the
                                        // integer_part and multiply it by 10 to
                                        // the power of desired decimal places
    decimal_part = (num - integer_part)*int_power(DECIMAL_BASE, DOUBLE_DEC_DIGITS);
    
    print_int_to_base(integer_part, DECIMAL_BASE, 0);
    putchar(DOUBLE_DEC_SEP);                            // print decimal separator
    
    if(decimal_part != 0){
        print_int_to_base(decimal_part, DECIMAL_BASE, 0);
    } else {
        int i = 0;
        for(i = 0; i < DOUBLE_DEC_DIGITS; i++){
            putchar('0');       // ensure that the correct amount of 0s is printed
        }
    }
}


static double int_power(unsigned int base, unsigned int exp) {
    double ans = 1;
    unsigned int n;
    for (n = 0; n < exp; n++){
        ans *= base;        // multiply ans by base n times
    }
    return ans;
}