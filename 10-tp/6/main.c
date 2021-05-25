#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "gpio_emul.h"

#define MSK_BYTE 0xFF
#define T_CODE 1
#define C_CODE 2
#define S_CODE 3
#define Q_CODE 4
#define CHAR_LED_ON 'w'
#define CHAR_LED_OFF 'u'

void flush_stdin(char limit);
void dec2bin(unsigned int dec);
void print_porta_data(void);
void clear_screen(void);

int main() {
    char c;
    //un total y completo afano de conway
    clear_screen();
    print_porta_data();
    while ((c = getchar()) != 'q'){

        // Temporary output
        if (c == 't') {
            for (int i=0; i<8; i++) {
                bit_toggle(PORTA, i);
            }
        }
        else if (c == 'c') {
            mask_off(PORTA, MSK_BYTE);
        }
        else if (c == 's') {
            mask_on(PORTA, MSK_BYTE);
        }
        else if (c == 'q') {
            break;
        }
        else if(c >= '0' || c <= '7') {
            bit_set(PORTA, c - '0');
        }
        else {
            printf("Sorry, I didn't recognize that input.\n");
        }
        //flush_stdin('\n');
        if(c != '\n') {
            clear_screen();
            print_porta_data();
        }
    }
    printf("You have reached the end of the program :) Thank you. \n");
    return 0;
}

void flush_stdin(char limit) {
    char c;
    // Hasta que se llegue al caracter especificado, vacía stdin
    while((c=getchar()) != limit) {}
}

void dec2bin(unsigned int dec) {
    int i;
    for(i = 7; i >= 0; i--) {
        putchar('|');
        putchar(' ');
        putchar(((dec >> i) & 0x1) ? CHAR_LED_ON : CHAR_LED_OFF);
        putchar(' ');
    }
}

void clear_screen(void) {
    system("CLS || clear");
}

void print_porta_data() {
    printf("\tPORTA data: \n\n");
    printf("\t  7   6   5   4   3   2   1   0  \n");
    printf("\t---------------------------------\n");
    putchar('\t');
    dec2bin(get_data(PORTA));
    putchar('|');
    putchar('\n');
    printf("\t---------------------------------\n");
    printf("\n\n\tInput 's' to set all PORTA bits, 'c' to clear all PORTA bits,\n");
    printf("\t't' to toggle all PORTA bits, any numbers to set the corresponding bit,\n");
    printf("\tor 'q' to exit: ");
}