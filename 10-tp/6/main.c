#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "gpio_emul.h"

#define MSK_BYTE 0xFF
#define CHAR_PORTA_SET  's'
#define CHAR_PORTA_CLR  'c'
#define CHAR_PORTA_TOG  't'
#define CHAR_EXIT       'q'
#define CHAR_LED_ON     "🛑"
#define CHAR_LED_OFF    "  "
#define IS_ASCII_NUM(c) ((c) >= '0' || (c) <= '7')
#define ASCII_NUM_INT(c) ((c) - '0')

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
        if (c == CHAR_PORTA_TOG) {
            mask_toggle(PORTA, MSK_BYTE);
        }
        else if (c == CHAR_PORTA_CLR) {
            mask_off(PORTA, MSK_BYTE);
        }
        else if (c == CHAR_PORTA_SET) {
            mask_on(PORTA, MSK_BYTE);
        }
        else if (c == CHAR_EXIT) {
            break;
        }
        else if(IS_ASCII_NUM(c)) {
            bit_set(PORTA, ASCII_NUM_INT(c));
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
        printf("%s",((dec >> i) & 0x1) ? CHAR_LED_ON : CHAR_LED_OFF);
        putchar(' ');
    }
}

void clear_screen(void) {
    system("CLS || clear");
}

void print_porta_data() {
    printf("\tPORTA data: \n\n");
    printf("\t   7   6    5    4    3    2    1    0  \n");
    printf("\t-----------------------------------------\n");
    putchar('\t');
    dec2bin(get_data(PORTA));
    putchar('|');
    putchar('\n');
    printf("\t-----------------------------------------\n");
    printf("\n\n\tInput 's' to set all PORTA bits, 'c' to clear all PORTA bits,\n");
    printf("\t't' to toggle all PORTA bits, any numbers to set the corresponding bit,\n");
    printf("\tor 'q' to exit: ");
}
