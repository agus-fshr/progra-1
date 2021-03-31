#include <stdio.h>

double determinante3(double N[3][3]);

int main() {
    double N[3][3] = {{2, 3, 4}, {1, 0, 4}, {5, 3, 2}};    

    printf("%f\n", determinante3(N));
    return 0;
}

double determinante3(double N[3][3]){
    return  (N[0][0])*(N[1][1])*(N[2][2]) + (N[0][1])*(N[1][2])*(N[2][0]) + (N[1][0])*(N[2][1])*(N[0][2]) - (N[2][0])*(N[1][1])*(N[0][2]) - (N[2][1])*(N[1][2])*(N[0][0]) - (N[1][0])*(N[0][1])*(N[2][2]);
}

/*
a b c    a deteminate (e f) - d determinate (b c) + h (b c)
d e f                 (i j)                 (i j)     (ef)
h i j (
*/

// N[0][0]*N[1][1]*N[2][2] + N[0][1]*N[1][2]*N[2][0] + N[1][0]*N[2][1]*N[0][2] - N[2][0]*N[1][1]*N[0][2] - N[2][1]*N[1][2]*N[0][0] - N[1][0]*N[0][1]*N[2][2]