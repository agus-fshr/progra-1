#include "gpio_emul.h"
#include <bits/types/cookie_io_functions_t.h>
#include <stdio.h>

#define T_CODE 1
#define C_CODE 2
#define S_CODE 3
#define Q_CODE 4

void flush_stdin(char limit);

int main() {
char c;

//un total y completo afano de conway
while ((c = getchar()) != 'q'){


        // Temporary output
        if (c == 't') {
            flush_stdin('\n');
            for (int i=0; i<8; i++) {
                bit_toggle(PORTA, i);
            }
        }
        else if (c == 'c') {
            flush_stdin('\n');
            for (int i=0; i<8; i++) {
                bit_clr(PORTA, i);
            }
        }
        else if (c == 's') {
            flush_stdin('\n');
            for (int i=0; i<8; i++) {
                bit_set(PORTA, i);
            }
        }
        else if (c == 'q') {
            break;
        }
        else if(c >= '0' || c <= '7') {
            flush_stdin('\n');
            bit_set(PORTA, (int) c);
        }
        else {
            flush_stdin('\n');
            printf("Sorry, I didn't recognize that input.\n");
        }
        flush_stdin('\n');
    }
    printf("You have reached the end of the program :) Thank you. \n");
    return 0;
}

void flush_stdin(char limit) {
    char c;
    // Hasta que se llegue al caracter especificado, vacía stdin
    while((c=getchar()) != limit) {}
}