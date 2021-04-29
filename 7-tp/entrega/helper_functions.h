#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H
#include <stdlib.h>


/*
 * Función clear_screen
 * 
 * Descripción:
 * Limpia stdout
 * 
 * Peligro! Esta implementación es os-specific
 * 
 * Nota: hay otras formas de resolver esto con caracteres
 * especiales escapados enprintf
*/

/*
 * @brief Flushes the stdout in an os-specific implementation
 *
 * */
void clear_screen(void);        // limpia la pantalla

/*
 * Función flush_stdin
 * Argumentos:
 *      - limit: finaliza
 * 
 * Descripción:
 * Toma caracteres de stdin hasta llegar
 * al caracter especificado
*/

/*
 * @brief Flushes the stdin buffer. Takes characters from stdin until limit.
 * @param limit character that indicates where to stop flushing
 * */
void flush_stdin(char);

#endif
