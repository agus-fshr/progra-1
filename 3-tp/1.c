#include <stdio.h>

int a = 3;

void fun1(void) {
    printf("%d\n", a++);
}

void fun2(void) {
    int a = -2;
    printf("%d\n", a++);
}

int main(void) {
    int a = 10;
    printf("%d\n", a++);
    fun1();
    fun2();
    fun1();
    fun2();
    printf("%d\n", a++);
    return 0;
}


/*
    * 10
    * 11
    * -2
    * 12
    * -2
    * 13
*/