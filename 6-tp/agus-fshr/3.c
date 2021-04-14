// Escribir un programa que imprima "Hola Mundo" o "Hello World" dependiendo del
// valor de la constante IDIOMA, mediante el uso de switch de compilación e
// instrucciones de preprocesador.

#include <stdio.h>

#define IDIOMA EN
#define EN 1
#define ES 2
#define FR 3

int main() {

    int lang = IDIOMA;

    // printf("lang = %d\n", IDIOMA);

    switch (lang){
        case (EN): {
            printf("Hello, World!\n");
            break;
        }
        case (ES): {
            printf("Hola, mundo!\n");
            break;
        }
        case (FR): {
            printf("Salut, monde!\n");
            break;
        }
        default: {
            printf("You didnt provide a valid language, please check again\n");
        }
    }

    return 0;
}