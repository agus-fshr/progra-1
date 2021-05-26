#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "gpio_emul.h"

#define MSK_BYTE 0xFF
#define CHAR_PORTA_SET  's'
#define CHAR_PORTA_CLR  'c'
#define CHAR_PORTA_TOG  't'
#define CHAR_EXIT       'q'
#define IS_ASCII_NUM(c) ((c) >= '0' || (c) <= '7')
#define ASCII_NUM_INT(c) ((c) - '0')

#if (EMOJI == 1)
#define CHAR_LED_ON     "🛑"
#else
#define CHAR_LED_ON     "00"
#endif
#define CHAR_LED_OFF    "  "

void flush_stdin(char limit);
void dec2bin(unsigned int dec);
void print_porta_data(void);
void clear_screen(void);

int main() {
    char c;
    
    clear_screen();
    print_porta_data();
    while ((c = getchar()) != 'q'){

        if (c == CHAR_PORTA_TOG) {
            //switches the state of all PORTA pins
            mask_toggle(PORTA, MSK_BYTE);
        }
        else if (c == CHAR_PORTA_SET) {
            //turns on all pins when the 'set' letter is entered
            mask_on(PORTA, MSK_BYTE);
        }
        else if (c == CHAR_PORTA_CLR) {
            //turns off all pins when the 'clear' letter is entered
            mask_off(PORTA, MSK_BYTE);
        }
        else if (c == CHAR_EXIT) {
            break;
        }
        else if(IS_ASCII_NUM(c)) {
            //sets the entered bit number to ON
            bit_set(PORTA, ASCII_NUM_INT(c));
        }
        else {
            printf("Sorry, I didn't recognize that input.\n");
        }
        if(c != '\n') {
            clear_screen();
            print_porta_data();
        }
    }
    printf("You have reached the end of the program :) Thank you. \n");
    return 0;
}

/**
 * @brief Clears stdin until the limit char is found.
 * 
 * @param limit char to clear until
 */
void flush_stdin(char limit) {
    char c;
    while((c=getchar()) != limit) {}
}

/**
 * @brief Converts from decimal to binary using
 * the LED_ON and LED_OFF characters and prints it 
 * with purely aesthetic separators.
 *
 * @param dec decimal number to be converted
 */
void dec2bin(unsigned int dec) {
    int i;
    for(i = 7; i >= 0; i--) {
        putchar('|');
        putchar(' ');
        printf("%s",((dec >> i) & 0x1) ? CHAR_LED_ON : CHAR_LED_OFF);
        putchar(' ');
    }
}

/**
 * @brief Clears the terminal
 * 
 */
void clear_screen(void) {
    system("CLS || clear");
}

/**
 * @brief Prints port A data to stdin, this is the main
 * interface for the program
 */
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
