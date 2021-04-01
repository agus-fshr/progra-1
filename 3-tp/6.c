#include <stdio.h>

double leer_numero_stdin(void);
void imprimir_msj_temp(double);


int main(void) {
    printf("Que temperatura hace??? ");
    double numero = leer_numero_stdin();
    imprimir_msj_temp(numero);
    
    return 0;
}


void imprimir_msj_temp(double temp) {
    if(30 <= temp && temp <= 90)
		printf("de alta papurri\n");
	else if(15 <= temp && temp < 30)
		printf("media pila\n");
	else if(0 <= temp && temp < 15)
		printf("la baja\n");
	else				/*si es > 90 o < 0*/
		printf("kya\n");
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
