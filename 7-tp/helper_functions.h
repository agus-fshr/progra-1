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
void flush_stdin(char);

#endif