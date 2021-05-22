#include<stdio.h>
#include<stdarg.h>

int mi_printf(char*, ...);

int mi_printf(char *str, ...) {
    char *p_str = str;
    va_list param_list;
    va_start(param_list, str);
    
    while(*p_str){      // mientras que no se llegue al final del string
        
        if(*p_str == '%'){          // si se encontró un '%'
            switch(*(++p_str)) {    // analizar el caracter siguiente
                case 'd':
                    printf("%d", va_arg(param_list, int));
                    // Acá tiene que ir una función print_int(va_arg(param_list, int)) propia
                    // que use putchar
                    break;
                case 'x':
                    // Acá tiene que ir una función print_hexa(va_arg(param_list, int)) propia
                    // que use putchar. 
                    // EXTRA: que diferencie 'x' de 'X', la func print_hexa podría tomar como
                    // parámetro si poner mayúscula o minúscula quizás.
                    printf("%x", va_arg(param_list, int));
                    break;
                case 'c':
                    // Acá tiene que ir una función print_char(va_arg(param_list, int)) propia
                    // que use putchar. 
                    printf("%c", va_arg(param_list, int));
                    break;
                case 'f':
                    // EXTRA: Acá tiene que ir una función print_double(va_arg(param_list, double)) propia
                    // que use putchar. 
                    // No lo pedía, así que no es necesario si es mucho quilombo
                    printf("%f", va_arg(param_list, double));
                    break;
                case '%':
                    // Si se pone %% imprime un %
                    putchar('%');
                    break;
                    
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

int main() {
    mi_printf("%d + %d = %c %% %% %a %f", 4, 12, 'A', 3.21);
}