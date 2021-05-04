/******************************************************************************
  @file     helper_functions.c
  @brief    Group 7 helper functions
  @author   Grupo 7
 ******************************************************************************/

#include <stdio.h>
#include "helper_functions.h"

void clear_screen(void) {
    system("cls || clear");
}

void flush_stdin(char limit) {
    char c;
    // Hasta que se llegue al caracter especificado, vacía stdin
    while((c=getchar()) != limit) {}
}