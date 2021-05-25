#include<stdio.h>
#include<stdarg.h>

// MAX 8
#define DECIMAL_DIG 8

int mi_printf(char* str, ...);
void print_int(int n);
void print_double(double n);
int count_digits(int n);
int int_power(int base, int exp);
void print_base(int n, int b);
int count_base(int n, int b);

int main() {
    mi_printf("%d + %d = %c %% %% %a %f", 4, 12, 'A', 3.2165165165);
    printf("\n");
    print_base(-0xcF8A, 16);
    printf("\n%x",-0xcF8A);
    return 0;
}

void print_int(int n) {
    int temp = n;
    int digit_num = count_digits(n);
    int i;
    
    if(n < 0) {
        putchar('-');
        temp *= (-1);
    }
    
    for(i = digit_num; i > 0; i--) {
        int curr_digit = temp/int_power(10, i - 1) - 10*(temp/int_power(10, i));
        putchar(curr_digit + '0');
    }
}

void print_base(int n, int b) {
    int temp = n;
    int digit_num = count_base(n, b);
    int i;
    
    if(n < 0) {
        putchar('-');
        temp *= (-1);
    }
    
    for(i = digit_num; i > 0; i--) {
        int curr_digit = temp/int_power(b, i - 1) - b*(temp/int_power(b, i));
        if(curr_digit <= 9){
            putchar(curr_digit + '0');
        }
        else if(curr_digit <= 34) {
            putchar(curr_digit - 10 + 'A');
        }
    }
}

int count_base(int n, int b) {
    if(n == 0) {
        return 0;
    }
    return 1 + count_base(n/b, b);
}

void print_double(double n) {
    int int_part = (int) n;
    print_int(int_part);
    int decimal_part = n*int_power(10, DECIMAL_DIG) - int_part*int_power(10, DECIMAL_DIG);
    putchar('.');
    if(decimal_part < 0) {
        decimal_part *= -1;
    }
    print_int(decimal_part);
}

int count_digits(int n) {
    if(n == 0) {
        return 0;
    }
    return 1 + count_digits(n/10);
}

int int_power(int base, int exp) {
    double ans = 1;
    int n;
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
                case 'd':
                    print_int(va_arg(param_list, int));
                    // Acá tiene que ir una función print_int(va_arg(param_list, int)) propia
                    // que use putchar
                    break;
                case 'x':
                    printf("%x", va_arg(param_list, int));
                    break;
                    // Acá tiene que ir una función print_hexa(va_arg(param_list, int)) propia
                    // que use putchar. 
                    // EXTRA: que diferencie 'x' de 'X', la func print_hexa podría tomar como
                    // parámetro si poner mayúscula o minúscula quizás.
                case 'c':
                    putchar(va_arg(param_list, int));
                    break;
                    // Acá tiene que ir una función print_char(va_arg(param_list, int)) propia
                    // que use putchar. 
                    //printf("%c", va_arg(param_list, int));
                case 'f':
                    print_double(va_arg(param_list, double));
                    break;
                    // EXTRA: Acá tiene que ir una función print_double(va_arg(param_list, double)) propia
                    // que use putchar. 
                    // No lo pedía, así que no es necesario si es mucho quilombo
                case '%':
                    putchar('%');
                    break;
                    // Si se pone %% imprime un %
                    
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