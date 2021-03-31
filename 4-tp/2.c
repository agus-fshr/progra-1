#include <stdio.h>

double determinante(double M[2][2]);

int main() {

    double M[2][2] = {{3, 4}, {7, 5}};

    printf("%f\n", determinante(M));

    return 0;
}

double determinante(double M[2][2]){
    return M[0][0]*M[1][1] - M[0][1]*M[1][0];
}

/*
a b  ---> ad - bc ---> M[0][0]*M[1][1] - M[0][1]*M[1][0]
c d

*/