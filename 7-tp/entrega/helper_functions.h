/** ****************************************************************************
  @file     helper_functions.h
  @brief    Group 7 helper functions
  @author   Grupo 7
 ******************************************************************************/

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H
#include <stdlib.h>


/**
 * @brief Clears terminal in an OS-specific basis
 */
void clear_screen(void);


/**
 * @brief Flushes the stdin buffer. Takes characters from stdin until limit is found.
 * 
 * @param limit Character that indicates where to stop flushing
 */
void flush_stdin(char limit);

#endif
