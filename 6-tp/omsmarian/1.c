#include <stdio.h>

int ordenalfa (char* str1, char* str2);
char parame (char);

int main (void)
{
    char word1 [] = "orden";
    char word2 [] = "orden";

    printf("word1 antes que word2 = -1\nword1 despues que word2 = 1\n");
    printf("rta = %d\n", ordenalfa (&word1[0] , &word2[0]));

    return 0;
}



int ordenalfa (char* str1, char* str2)
{
    for(;(*str1 != '\0') && (*str2 != '\0');str1++, str2++)
    {
        char w1 = *str1;
        char w2 = *str2;
        w1 = parame(w1);
        w2 = parame(w2);
        if (w1 < w2)
            return -1;
        else if (w1 > w2)
            return 1;
    }
    if (*str1 != '\0')
    {
        return 1;
    }
    else if (*str2 != '\0')
    {
        return -1;
    }
    return 0;
}


char parame (char a)
{
    if (a <= 'z' && a >= 'a')
    {
        return (a - 32);
    }
    else if (a <= 'Z' && a >= 'A') 
        return a;
}