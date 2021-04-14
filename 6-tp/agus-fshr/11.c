// Escribir una función que transponga una matriz de NxN.
// El prototipo debe ser: void transponer (double mat[N][N]), siendo N una
// constante ya definida. El resultado debe devolverse modificando la matriz original.

#include <stdio.h>

#define N 6

void copy_matrix(int mat1[], int mat2[]);

int main(){

    int mat1[N][N] = {{2, 4, 5, 2, 1, 2}, {3, 4, 1, 6, 4, 5}, {6, 8, 3, 2, 1, 6}, {5, 2, 4, 1, 5, 2}, {7, 4, 2, 3, 1, 1}, {2, 4, 2, 5, 2, 1}};
    int mat2[N][N];

    for (int f=0; f<N; f++){ //filas

        for (int c=0; c<N; c++){ //columnas
            mat2[c][f] = mat1[f][c];
        }

    }

    for (int row=0; row<N; row++){

        for(int columns=0; columns<N; columns++){
            printf("%d     ", mat1[row][columns]);
        }
        printf("\n");

    }

    int spaces = 6*N;

    for (int x=0; x<spaces-5; x++){
        printf("=");
    }
    printf("\n");

    for (int row=0; row<N; row++){

        for(int columns=0; columns<N; columns++){
            printf("%d     ", mat2[row][columns]);
        }
        printf("\n");

    }

    return 0;
}