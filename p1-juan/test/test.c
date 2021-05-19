#include <stdio.h>

union u {
    short a;
    char b;
}un;
void (*signal(int, void (*)(int)))(int);

int main(void)
{
    un.a = 0xabcd;
    if(un.b == 0xab)
        printf("\n The system is big-endian\n");
    else
        printf("\n The system is little-endian\n");
    return 0;
}
