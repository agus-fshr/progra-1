#include <stdio.h>

#define relleno '*'                              //código ASCII del *
#define espacio ' '


void rombo (int);
int lector (void);

int main (void)
{
    printf("impresora de rombos ingrese tamaño:");
    rombo(lector());    
    return 0;
}


void rombo (int n)
{
    int fila = 1;                              //contador de filas
    int cant_esp;                              //contador de espacios por fila 
    int cant_re;                              //cantidad de * por filas 
    int sup = n;                               //primera parte del rombo
    int inf = (n-1);                           //segunda parte del rombo

    for (sup; sup > 0; sup--) 
    {
        for(cant_esp = (n-fila); cant_esp>0; cant_esp--)
        {
            printf("%c", espacio);
        }
        cant_re = (2 * ((fila++) -1));                      //defino la cantidad de * que va a tener cada fila 
        for (cant_re; cant_re >= 0; cant_re--)              //por la ecuacion: cantidad = numero_de_fila + 2
        {
            printf ("%c",relleno);
        }
        printf ("\n");
    }
    fila--;                                      //resto la el total de filas ya que termina defasado    
    for (inf; inf > 0; inf--) 
    {
        cant_re = (2 * ((fila--) -1));                      //decremento el contador de filas para hacer la 
        for (cant_esp = (n-(fila)); cant_esp>0; cant_esp--) //parte inferior del rombo
        {
            printf("%c", espacio);
        }
        for (cant_re; cant_re > 1; cant_re--)           
        {
            printf ("%c",relleno);
        }
        printf ("\n");
    }    

}


int lector (void)
{
    char c;
    int num = 0;
    while ((c = getchar()) && c != '\n')
    {
        num *= 10;       
        num += (c - '0');
    }
    return num;
}