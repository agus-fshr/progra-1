/***************************************************************************//**
  @file     conway.h
  @brief    +Descripcion del archivo+
  @author   Grupo 7
 ******************************************************************************/

#ifndef CONWAY_H
#define CONWAY_H


/************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE *
 ************************************************/

/* Parametrización funcional */
#define WORLD_WIDTH 25      // Ancho del mundo. Número de columnas.
#define WORLD_HEIGHT 15     // Altura del mundo. Número de filas.
#define OUTSIDE_STATE DEAD  // Estado de las celdas del borde externo

/* Parametrización estética */
#define ALIVE_CHAR '*'      // Caracter que representa una celda viva
#define DEAD_CHAR ' '       // Caracter que representa una celda muerta
#define SEPARATOR '|'       // Separador de columnas

/* Funcionamiento interno */
#define ALIVE 1
#define DEAD 0


/******************************************
 *       GLOBAL FUNCTION PROTOTYPES       *
 *****************************************/


/*
 * Función read_generations
 * 
 * Descipción:
 * Lee un número entero sin signo de stdin
 * La presencia de cualquier caracter numérico, 
 * excepto q y \n (si están en la primera posición), 
 * provocan que devuelva un 0.
 * Sin embargo, si se incluye una q en algún lugar de la entrada, 
 * la salida será -1, marcando error.
*/

/*
 * @brief Reads an unsigned number from stdin. 
*/
int read_generations(void);     // lee num de generaciones a avanzar


/*
 * Función advance_generation
 * Realiza un avance en la generación actual, analizando
 * el estado futuro de todas las celdas. Antes de salir,
 * guarda en el estado actual del sistema la generación
 * calculada.
 * 
 * Implementa la lógica del Juego de la Vida de James Conway,
 * de acuerdo a las siguientes reglas:
 * 
 *  - Una celda viva con exactamente dos o tres vecinos sobrevive;
 *  - Una celda muerta con exactamente tres vecinos obtiene vida.
 * En el resto de los casos, morirá (o seguirá muerta).
*/

/*
 * @brief Advances the current generation, analyzing the future state
 * of all cells. Before ending, it saves the calculated generation
 * in the current state.
 * 
 * This function implements John Conway'advance_generas Game of Life rules
 *  - A live cell with exactly two or three live neighbors stays alive
 *  - A dead cell with exactly three live neighbors becomes alive
*/
void advance_generation(int[][WORLD_WIDTH]);  // avanza una generación


/*
 * Función print_world
 * 
 * Descripción:
 * Imprime a stdout el estado actual del mundo,
 * con formato embellecido.
*/
void print_world(int[][WORLD_WIDTH]);         // imprime mundo


/*
 * Función initialize_world
 * 
 * Descripción:
 * Maneja la inicialización del mundo de juego.
 * Permite al usuario elegir entre distintos métodos de entrada
 * para personalizar el mundo en el que jugará.
 * Incluye instrucciones sobre cómo se realiza la carga manual de un mapa.
 * Apto para mayores de 12 años.
*/
void initialize_world(int[][WORLD_WIDTH]);                // inicializa juego


#endif