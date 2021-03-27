#include <stdio.h>


int main(void) {    
    
    int c = getchar();
    
    while ((c != 'q') && (c != 'Q')) {
        putchar(c);
        c = getchar();
    }
    
    return 0;
}