#include <stdio.h>

double cuadrado(double x) {
    return x*x;
}

double leer_numero_stdin(void);

int main(void) {
    double numero;
    printf("Ingrese un numero:");
    numero = leer_numero_stdin();
    //scanf("%lf", &numero);
    printf("El cuadrado es: %f", cuadrado(numero));
    return 0;
}

double leer_numero_stdin(void) {
    char c;
    double numero = 0;
    int es_decimal = 0;
    int contador_decimales = 1;
    int es_negativo = 0;
    int contador_caracteres = 0;

    while((c = getchar()) != '\n') {
        contador_caracteres++;

        if(c == '-' && contador_caracteres == 1) {
            es_negativo = 1;
        } 
        else if(c >= '0' && c <= '9') {
            if(es_decimal == 0) {
                numero *= 10.0;
                numero += c - '0';
            } else {
                int i;
                double division = c - '0';
                for(i = 0; i < contador_decimales; i++) {
                    division /= 10.0;
                }
                contador_decimales++;
                numero += division;
            }
        } 
        else if(c == '.' && es_decimal == 0) {
            es_decimal = 1;
        } 
        else {
            printf("Sos un animal\n");
            break;
        }
    }
    
    if(es_negativo) {
        numero *= -1;
    }

    printf("Se leyo: %.*f\n", contador_decimales - 1, numero);
    
    return numero;
}
