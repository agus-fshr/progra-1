#include <stdio.h>

                        /* defino los posibles idiomas*/
/*********************************************************************************************/
#define SPANISH 1
#define ENGLISH 2   
/*********************************************************************************************/

int main (void)
{
    #define LANGUAGE ENGLISH    //específco el idioma que quiero

    #if (LANGUAGE == SPANISH)
    printf ("hola mundo\n");
    #elif (LANGUAGE == ENGLISH)
    printf ("hello world\n");
    #endif
    
    return 0;
}
