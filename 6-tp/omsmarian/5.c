#include <stdio.h>

#define space 32

char toUpper (char);                    //recibe letra minus la transforma en Mayus
char toLower (char);                    //recibe letra Mayus la transforma en minus
int isUpper (char);                     //chequea que sea Mayus
int isLower (char);                     //chequea que sea minus
void normalizar (char *str);
void CamelCase (char *str);

void main (void)
{
    char frase[] ="bETa tEStiG... mono tEta";
    printf("Original Frase:\n");
    for(int j = 0; (frase[j]) != '\0'; j++)
    {
        printf("%c", frase[j]);    
    }
    printf("\nCheta Frase\n");
    normalizar (frase);    
    CamelCase(frase);
    for(int p = 0; (frase[p]) != '\0'; p++)
    {
        printf("%c", frase[p]);    
    }
    printf("\n");
}

void CamelCase (char *str)
{
    int space_flag = 0;
    *str = toUpper(*str);
    str++;
    for(str ;(*str)!= '\0'; str++)
    {
        if((*str) == space)
        {
            space_flag = 1;
        }
        else if(space_flag)
        {
            *str= toUpper(*str);
            space_flag = 0;
        }
    }    
}

void normalizar (char *str)
{
    for(str; (*str)!= '\0'; str++)
    {
        if ((((*str)>= 'A') && ((*str)<='Z')) || (((*str)>= 'a') && ((*str)<='z')))
        {
            if(isUpper(*str))
            *str = toLower(*str);
        }
        else if ((*str) != ((((*str)>= 'A') && ((*str)<='Z')) || (((*str)>= 'a') && ((*str)<='z'))))
        {
            *str = *str;
        }
    }
}

char toUpper (char letter)
{
    return (letter - ('a'-'A'));
}

char toLower (char letter)
{
    return (letter + ('a'-'A'));
}

int isUpper (char letter)
{
    return ((letter >= 'A' && letter <= 'Z')? 1: 0);
}

int isLower (char letter)
{
    return ((letter >= 'a' && letter <= 'z')? 1: 0);
}