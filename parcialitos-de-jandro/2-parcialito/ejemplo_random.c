#include <stdio.h>

int main(void){
    int a = 10;
    do {
        printf("%d", a++);
    } while(a++ < 15);

    printf("\n");
    return 0;
}

// do {esto} while(cond);
//101214