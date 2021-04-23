#include <stdio.h>

#define J 11
#define Q 12
#define K 13
#define AS 1
#define picas 100
#define corazon 200
#define rombo 300
#define trebol 400


int pierna_poker(int cartas[]);
void normalizar (int*);

void main (void)
{
    int jugador1[] = {rombo+3,corazon+3, picas+3,trebol+J, picas+2};
    printf("Si hay pierna devuelve 1, si no 0\n");
    printf("%d\n", pierna_poker(jugador1));
}

int pierna_poker(int cartas[])
{
    int *punt;
    punt = cartas;
    int *secp;
    int flag = 0;
    normalizar(punt);
    for(int a = 0; a < 4; a++, punt++)
    {
        for(int n =1; 5-n ;n++)
        {
            secp=(punt+n);
            if((*punt)==(*secp))
            {
                flag += 1;
            }
            if(flag == 2)
            {
                return 1;
            }
        }
        return 0;
    }   
}

void normalizar (int* kya)
{
    for (int i = 0; i < 5; i++, kya++)                          //normalizo todo
    {
        if(*kya >= trebol)                                     //le resto el palo trebor
        {
            *kya = *kya-trebol;
        }
        else if((*kya < trebol) && (*kya >= rombo))           //le resto el palo rombo
        {
            *kya = *kya-rombo;
        }
        else if((*kya < rombo) && (*kya >= corazon))          //le resto el palo corazon
        {
            *kya = *kya-corazon;
        }
        else if(*kya < corazon)                                //le resto el palo de picas
        {
            *kya = *kya-picas;
        }
    }

}