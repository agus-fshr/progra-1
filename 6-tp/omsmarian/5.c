#include <stdio.h>

#define space ' '

char toUpper (char);                    //recibe letra minus la transforma en Mayus
char toLower (char);                    //recibe letra Mayus la transforma en minus
int isUpper (char);                     //chequea que sea Mayus
int isLower (char);                     //chequea que sea minus
void CamelCase (char *str);

void main (void)
{
    char frase[] ="bETa tEStiG...";
    int i = (sizeof(frase)/sizeof(frase[0]));
    printf("Original Frase:\n");
    for(int j = 0; (frase[j]) != '\0'; j++)
    {
        printf("%c", frase[j]);    
    }
    printf("\nCheta Frase\n");
    CamelCase(frase);
}


void CamelCase (char *str)
{
    if(isUpper(*str))
    {
        printf("%c", *str);
        str++;
    }
    else if(isLower(*str))
    {
        printf("%c", toUpper(*str));
        str++;
    }
    for(str ; *str!='\0'; str++)
    {
        if (*str == space)
        {
            printf("%c", *str);
            str++;
            if(isUpper(*str))
            {
                printf("%c", *str);
            }
            else if(isLower(*str))
            {
                printf("%c",toUpper(*str));
            }
        }
    }

}

char toUpper (char letter)
{
    return (letter + ('a'-'A'));
}

char toLower (char letter)
{
    return (letter - ('a'-'A'));
}

int isUpper (char letter)
{
    return ((letter >= 'A' && letter <= 'Z')? 1: 0);
}

int isLower (char letter)
{
    return ((letter >= 'a' && letter <= 'z')? 1: 0);
}