/*******************************************************************************
  @file     test.c
  @brief    Program to test custom printf function
  @author   Grupo 7 Inc.
 ******************************************************************************/
#include "custom_printf.h"
#include<stdio.h>

int main(void){
    int a = 123;
    int b = -1665;
    my_printf("%d + %d = %d\n", a, b, a + b);
    my_printf("%d / %d = %f\n", a, b, ((double) a)/b);

    int c = 0xC380;
    int d = 0xA2D2;
    my_printf("%x & %x = %x\n", c, d, c & d);
    my_printf("%b & %b = %b\n", c, d, c & d);
    my_printf("%X | %X = %X\n", c, d, c | d);
    my_printf("%b | %b = %b\n", c, d, c | d);
    my_printf("%o ^ %o = %o\n", c, d, c ^ d);

    int e = 'A';
    int f = -89;
    my_printf("%i, %u\n", e, f);
    my_printf("%c, %i\n", e, f);
    
    my_printf("1: %d\t2: %i\t3: %u\t4: %f\n", 0,0,0,0.0);
    printf("1: %d\t2: %i\t3: %u\t4: %f\n", 0,0,0,0.0);

    return 0;
}