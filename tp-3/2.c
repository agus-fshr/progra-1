#include <stdio.h>

int main(void) {
    int c;
    
    while ((c = getchar()) != 'e' ) {
        putchar(c + 'A' - 'a');
    }
    
    return 0;
}
