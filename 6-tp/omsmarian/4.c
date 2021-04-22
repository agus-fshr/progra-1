#include <stdio.h>

void rombo (int);

int main (void)
{
    rombo(4);
    return 0;
}


void rombo (int n)
{
    int fila = 0;                               //contador de filas
    int cantidad;                               //cantidad de * por filas 
    int up = n;                                 //primera parte del rombo
    int down = (n-1);                           //segunda parte del rombo

    for (up; up > 0; up--) 
    {
        cantidad = (2 * (fila++));                       //defino la cantidad de * que va a tener cada fila 
        for (cantidad; cantidad >= 0; cantidad--)        //por la ecuacion: cantidad = numero_de_fila + 2
        {
            printf ("*");
        }
        printf ("\n");
    }    
    for (down; down > 0; down--) 
    {
        cantidad = (2 * (--fila));                  //decremento el contador de filas para hacer la 
        for (cantidad; cantidad > 1; cantidad--)    //parte inferior del rombo
        {
            printf ("*");
        }
        printf ("\n");
    }    

}