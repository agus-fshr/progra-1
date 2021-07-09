#include<stdio.h>


int main() {
    int *ap[5];    //creo un arreglo de punteros
    int a[5];
    int i;
    int **pp;
    for (i=0;i<5;i++) {   
        ap[i]=&a[i];
    }
    
    pp=&ap[1];
    *(ap[0])=0;
    **(pp)=0;
    **(pp+=1);
    **(pp)=0;
    
    printf("A");
    return 0;
}