#include <stdio.h>

#define TAM 7
#define ESPACIO 32
#define SNAKE '*'


int completa (int*);

/*************************************************
*                    CÓDIGO                      *
**************************************************/

int main (void)
{
    int play[TAM][TAM];
    completa(&play[0][0]);
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            printf("%c ", play[i][j]);
        }
        printf("\n");
    }
}

/*************************************************
*                  FUNCIONES                     *
**************************************************/

int completa (int *pun)
{
    for(int k = 0; k < (TAM * TAM); k++ , pun++)
    {
        *pun = ESPACIO; 
    }
}
