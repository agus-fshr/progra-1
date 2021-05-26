#include<stdio.h>
#include<stdarg.h>
#include<stdint.h>

// MAX 10
#define DOUBLE_DEC_DIGITS 6
#define DECIMAL_BASE 10
#define HEXA_BASE 16
#define OCTAL_BASE 8


int mi_printf(char* str, ...);
void print_double(double n);
void print_int_to_base(unsigned int n, unsigned int b, int lowercase);
double int_power(unsigned int base, unsigned int exp);


int main() {
    mi_printf("%d + %d = %c %% %% %a %f", 4, 12, 'A', 3.2165165165);
    return 0;
}

void print_int_to_base(unsigned int num, unsigned int base, int lowercase) {
    if(num == 0) {
        return;
    }

    print_int_to_base(num/base, base, lowercase);

    int remainder = num % base;
    if(remainder <= 9){
        putchar(remainder + '0');
    } else if((remainder - 10) <= ('Z' - 'A')) {
        putchar((remainder - 10) + (lowercase ? 'a' : 'A'));
    }
}


void print_double(double num) {
    unsigned int integer_part;
    unsigned int decimal_part;
    if(num < 0) {
        num = -num;
        putchar('-');
    }

    integer_part = (unsigned int) num;
    decimal_part = (num - integer_part)*int_power(DECIMAL_BASE, DOUBLE_DEC_DIGITS);
    
    print_int_to_base(integer_part, DECIMAL_BASE, 0);
    putchar('.');
    print_int_to_base(decimal_part, DECIMAL_BASE, 0);
}

double int_power(unsigned int base, unsigned int exp) {
    double ans = 1;
    unsigned int n;
    for (n = 0; n < exp; n++){
        ans *= base;
    }
    return ans;
}

int mi_printf(char *str, ...) {
    char *p_str = str;
    va_list param_list;
    va_start(param_list, str);
    
    while(*p_str){      // mientras que no se llegue al final del string
        
        if(*p_str == '%'){          // si se encontró un '%'
            switch(*(++p_str)) {    // analizar el caracter siguiente
                case 'd': {
                    int val = va_arg(param_list, int);
                    if(val < 0) {
                        putchar('-');
                        val = -val;
                    }
                    print_int_to_base(val, DECIMAL_BASE, 0);
                    break;
                }
                case 'x': {
                    print_int_to_base((unsigned int) va_arg(param_list, int), HEXA_BASE, 1);
                    break;
                }
                case 'X': {
                    print_int_to_base((unsigned int) va_arg(param_list, int), HEXA_BASE, 0);
                    break;
                }
                case 'o': {
                    print_int_to_base((unsigned int) va_arg(param_list, int), OCTAL_BASE, 0);
                    break;
                }
                case 'c': {
                    putchar(va_arg(param_list, int));
                    break;
                }
                case 'f': {
                    print_double(va_arg(param_list, double));
                    break;
                }
                case '%': {
                    putchar('%');
                    break;
                }
                default:        // Si hay un % y algo no reconocido, saltearlo
                    break;
            }
        } else {
            putchar(*p_str);    // si no se encontró un '%', imprimir el char
        }
        
        p_str++;                // ver el siguiente char
    }
    
    va_end(param_list);
    return 4;                   // EXTRA: que devuelva el número de caracteres escritos
    // Para eso último haría falta un acumulador que sume 1 en el else o sume lo necesario
    // para cada especificador. Eso requeriría que cada subfunción devuelva los chars escritos
    // también
}