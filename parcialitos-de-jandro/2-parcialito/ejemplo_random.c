#include <stdio.h>

int main(void){
    int i = getchar();
    switch (i) {
        case ('0'):{
            printf("tu numero es el cero\n");
            break;
        }
        default:{
            printf("no es cero :)\n");
            break;
        }
    }
}