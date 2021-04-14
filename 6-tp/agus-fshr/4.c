// Escribir una función llamada rombo que imprime en pantalla un rombo relleno con
// asteriscos de lado n. La función recibe el parámetro n y no devuelve nada. Debe
// funcionar para todo 1 ≤ n ≤ 25. No se permite utilizar arreglos. Se debe validar n.

#include <stdio.h>

#define FILLER '*'
#define SPACER '.'

int main(){

    int lado = 3;
    int line_number = 1;

    int lines_to_print = 2*lado - 1;
    int columns_to_print = 2*lado - 1;

    int spaces_to_print = lado - line_number;
    int fills_to_print = 2*line_number - 1;


    for (int i=0; i < lines_to_print; i++){

        spaces_to_print = lado - line_number;
        fills_to_print = 2*line_number - 1;

        // print spacers
        for (int c=0; c < spaces_to_print; c++) {
            printf("%c", SPACER);
        }

        // print fill
        for (int x=0; x < fills_to_print; x++){
            printf("%c", FILLER);
        }

        // print spacers
        for (int c=0; c < spaces_to_print; c++) {
            printf("%c", SPACER);
        }
        printf("\n");
        line_number++;
    }


    return 0;
}

/*

Amount of lines to print = 2n-1
Amount of columns to print = 2n-1

Offset for the first * = n-1
Offset for each line where the line number is t = n-t

lado 2

.*.
***
.*.


lado 3

..*..
.***.
*****
.***.
..*..

*/