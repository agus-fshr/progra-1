// Escribir una función que parte un string en dos, en la primera ocurrencia de un
// separador. El prototipo es: char* strSplit(char* str, char separador);
// El primer parámetro es el string a partir y el segundo es un char con el caracter que
// considera separador. Devuelve un puntero al comienzo del segundo string. Si no
// puede partir el string, devuelve un puntero al terminador.

// Por ejemplo:
// • Si se invoca nstr = strSplit("Hola paisano", ' '); la función reemplaza el
// espacio (' ') por un terminador y devuelve un puntero a la 'p'.
// • Si se invoca nstr = strSplit("Palombo;43216;9,58", ';'); la función
// reemplaza el primer punto y coma (';') por un terminador y devuelve un puntero
// al '4'.
// • Si se invoca nstr = strSplit("Cuidado", ';'); la función no parte al string y
// devuelve un puntero al terminador.

#include <stdio.h>

void print_str(char * str);
int str_len(char * str);

int main(){

    char string[] = "este es la string que hay que partir";
    char * p;
    char splitter = '*';

    for (int i=0; i<str_len(string); i++){
        p = &string[i+1];
        if (string[i] == splitter){
            break;
        }
    }

    print_str(p);

    return 0;
}

/***********************************
*            FUNCIONES             *
***********************************/

void print_str(char * w1){
    for (char c=0; c<str_len(w1); c++){
        printf("%c", *(w1+c));
    }
    printf("\n");
}

int str_len(char * str){
    int len = 0, i = 0;

    while (*(str+i) != '\0'){
        len++;
        i++;
    }

    return len;
}