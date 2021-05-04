#include<stdio.h>

#define IS_EVEN(n) (((n) % 2) == 0)

int main(void) {
    
    int a = 321;
    int b = 654;

    printf("a es par? %s\n", IS_EVEN(a) ? "si" : "no");
    printf("b es par? %s\n", IS_EVEN(b) ? "si" : "no");
    
    return 0;
}