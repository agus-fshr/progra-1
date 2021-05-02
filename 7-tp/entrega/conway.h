/** ****************************************************************************
  @file     conway.h
  @brief    Implements Conway's game of life
  @author   Grupo 7
 ******************************************************************************/

#ifndef CONWAY_H
#define CONWAY_H


/************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE *
 ************************************************/

/* Parametrización funcional */
#define WORLD_WIDTH 25      ///< Ancho del mundo. Número de columnas.
#define WORLD_HEIGHT 15     ///< Altura del mundo. Número de filas.
#define OUTSIDE_STATE DEAD  ///< Estado de las celdas del borde externo

/* Parametrización estética */
#define ALIVE_CHAR '*'      ///< Caracter que representa una celda viva
#define DEAD_CHAR ' '       ///< Caracter que representa una celda muerta
#define SEPARATOR '|'       ///< Separador de columnas

/* Funcionamiento interno */
#define ALIVE 1             ///< Valor interno de una celda viva
#define DEAD 0              ///< Valor interno de una celda muerta


/******************************************
 *       GLOBAL FUNCTION PROTOTYPES       *
 *****************************************/


/**
 * @brief Reads an unsigned number from stdin. 
 * @return 1 if the first char is '\\n', -1 if it's 'q',
 * the input number if it's valid, 0 otherwise.
*/
int read_generations(void);     // lee num de generaciones a avanzar


/**
 * @brief Advances the current generation, analyzing the future state
 * of all cells.
 * 
 * @param world_to_advance World matrix where the current state is and
 * the future state will be saved before returning.
 * 
 * @note This function implements John Conway's Game of Life rules
 *  - A living cell with exactly two or three living neighbors stays alive
 *  - A dead cell with exactly three living neighbors becomes alive
*/
void advance_generation(int world_to_advance[][WORLD_WIDTH]);


/**
 * @brief Prints the world state to stdout
 * in a polished format.
 * 
 * @param world world to print to stdout
*/
void print_world(int world[][WORLD_WIDTH]);


/**
 * @brief Handles world initialization. Allows the user to select
 * different input methods to customize the world to load. Includes
 * instructions on how to manually load a world file.
 * 
 * @param world Matrix where the initial world state is saved.
*/
void initialize_world(int world[][WORLD_WIDTH]);


#endif