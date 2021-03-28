#include <stdio.h>

int main(void) {

    int a=4, b=8;
    do {
        putchar('A');
        if (++b < 9)
            putchar('B');
        else if (a & 1)
            break;
        putchar('C');

    } while (a++ < 6); // el while corre 3 veces

    return 0;
}