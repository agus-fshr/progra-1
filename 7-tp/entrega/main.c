/******************************************************************************
  @file     main.c
  @brief    Plays Conway's Game of Life.
  @author   Grupo 7
 ******************************************************************************/

/*
    TP4 - Ejercicio 5 - Grupo 7 (FISHER, MARTINEZ TANOIRA, SBRUZZI, OMS)
    Consigna:
        Implementar el Juego de la Vida, de James Conway. Reglas:
            a) Una célula viva con menos de dos vecinos muere;
            b) una célula con más de tres vecinos también muere;
            c) una célula viva con exactamente dos o tres vecinos sobrevive;
            d) una célula muerta con exactamente tres vecinos obtiene vida nuevamente.        
    Requisitos:
            a) El tamaño del mundo debe encontrarse en dos constantes, por ejemplo, ANCHO
                y ALTO. Debe poder cambiarse el valor de las mismas y recompilar el código, y
                el mismo debe funcionar.
            b) El programa debe mostrar el estado actual del mundo en pantalla, y luego
                preguntar al usuario cuantas generaciones desea avanzar. Cuando el usuario
                ingresa un número y presiona enter, se calcula el nuevo estado del mundo, se
                presenta en pantalla, y se vuelve a preguntar.
            c) Si el usuario presiona enter sin ingresar ningún número, se debe avanzar una
                generación.
            d) Si el usuario ingresa el carácter ‘q’, se debe salir del programa.
            e) Cualquier funcionalidad extra que deseen agregar se tomará en cuenta en la
                nota del trabajo práctico.

    Descripción de la implementación:
        1) El estado de cada celda no es un número, sino un define. Esto se tiene en cuenta en todo el código.
        2) Hay 3 formas de ingresar un mapa:
            - Manualmente, con las instrucciones correspondientes
            - A través de un .txt que tenga un mapa formateado correctamente
            - A través de la generación pseudoaleatoria
        3) Se sanitizan el input del usuario en la medida de lo posible: se cuida que no queden caracteres
            pendientes en stdin cuando ello podría arruinar el funcionamiento correcto del programa.
        4) Bajo la categoría "parametrización" se encuentran los defines que establecen detalles del
            funcionamiento del programa. Esto permite personalizar tanto el funcionamiento del juego
            como la presentación del mismo

    Instrucciones:
    Puede cargar el mundo de manera manual o cargarlo en un archivo de texto con el formato adecuado.
    Luego, compilar este programa y llamar al comando cat [archivo mapa] - | ./[ejecutable]
    Alternativamente, si el archivo del mapa se denomina "mapa.txt" y el ejecutable más reciente tiene como nombre "5",
    puede simplemente correr el ejecutable game-of-life, como ./game-of-life, que es un wrapper

*/


/******************************************
 *          INCLUDE HEADER FILES          *
 *****************************************/
#include <stdio.h>
#include "helper_functions.h"
#include "conway.h"



/******************************************
 *                MAIN                    *
 *****************************************/

/**
 * @brief Main function
 */
int main(void){
    int myworld[WORLD_HEIGHT][WORLD_WIDTH]; //  variable global que almacena el estado actual del mundo
    int total_generations = 0;
    int steps = 0;              // variable local: pasos a avanzar o si debe salir
    
    initialize_world(myworld);   // decide qué mapa se usará como estado inicial

    while(steps != -1) {        // si steps vale -1, debe abandonarse el juego

        clear_screen();
        printf("\n\n\tGeneracion: %d\n\n", total_generations);
        print_world(myworld);
        printf("\tIngrese: \n");
        printf("\t - Enter: para avanzar una generacion\n");
        printf("\t - Un numero natural para avanzar esa cantidad de generaciones\n");
        printf("\t - 'q' para salir\n");

        steps = read_generations();     // lee generaciones a avanzar o salida
        total_generations += steps;
        
        int i;
        for(i = 0; i < steps; i++) {
            advance_generation(myworld);       // pasa a la siguiente generación
        }
    }

    printf("Nos vemos.\n");     // saluda amablemente

    return 0;
}