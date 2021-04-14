// Escribir la función CamelCase que recibe un string con texto en inglés y lo modifica
// para que la primera letra de cada palabra quede en mayúscula y el resto en
// minúscula. El texto no tiene ñ ni tildes, es un texto válido y puede tener mezcladas
// mayúsculas y minúsculas. El prototipo es: void CamelCase(char* str);

// Por ejemplo, si la entrada es:
// "Will I paSS the EXAM? I hOPe so. i'VE stuDIEd a lot... NOT!"
// la función debe editarlo para que quede:
// "Will I Pass The Exam? I Hope So. I'Ve Studied A Lot... Not!"

#include <stdio.h>

int str_len(char * str);
void lower(char * str);
void make_upper(char str);
void make_lower(char str);

int main() {

    char str[] = "me encanta progrAMAR en C";

    lower(str);

    str[0] -= ('a' - 'A');

    for (int i=0; i < str_len(str); i++){
        if (str[i] == ' '){
        str[i+1] -= ('a' - 'A');
        }
        // else{
        //     str[i+1] += ('a' - 'A');
        // }
    }

    for (char c=0; c<str_len(str); c++){
        printf("%c", str[c]);
    }
    printf("\n");

    return 0;
}

void lower(char * str){
    for (int i=0; i<str_len(str); i++){
        if ((*(str+i)>='A') && (*(str+i)<='Z')){
            *(str+i) = *(str+i) + ('a'-'A');
        }
    }
}

int str_len(char * str){
    int len = 0, i = 0;

    while (*(str+i) != '\0'){
        len++;
        i++;
    }

    return len;
}