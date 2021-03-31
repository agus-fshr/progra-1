#include <stdio.h>

void prm3(double vr[], double M[][3], double v[], int filas);

#define FILAS 3

int main() {

    double vr[FILAS];
    double M[FILAS][3] = {{2, 3, 4}, {1, 0, 4}, {5, 3, 2}};
    double v[3] = {4, 5, 6};

    prm3(vr, M, v, 3);

    for(int n=0; n<FILAS; n++){
        printf("%f\n", vr[n]);
    }
    
}

void prm3(double vr[], double M[][3], double v[], int filas) {

    int i, n; //contador para las filas de v

    for (n = 0; n < filas; n++) {

        for (i = 0; i <= 2; i++) {
            vr[n] += v[i] * M[n][i];
        }
        
    }
}

/*
a b c     x     ax + by + cz
d e f  x  y ==> dx + ey + fz
g h i     z     gx + hy + iz
j k l           jx + ky + lz
| | |

x y z
*/