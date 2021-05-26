/******************************************************************************
  @file     custom_printf.h
  @brief    Header file for custom printf function
  @author   Grupo 7 Inc.
 *****************************************************************************/

#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

/**
 * @brief Prints a string, replacing with the desired parameters
 * @param str pointer to the base string
 * @param ... additional arguments to print numbers and chars
 * @note %d and %i print a signed integer in decimal representation
 * @note %u prints an unsigned integer in decimal representation
 * @note %x prints an unsigned integer in hexadecimal representation, 
 *  letters in lowercase
 * @note %X prints an unsigned integer in hexadecimal representation, 
 *  letters in uppercase
 * @note %f prints a double precision floating number
 * @note %o prints an unsigned integer in octal representation
 * @note %c prints a char
 * @note %% prints a single %
*/
void my_printf(char* str, ...);

#endif