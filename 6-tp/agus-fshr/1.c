// Escribir una función llamada ordenalfa que determina el orden alfabético de dos
// palabras. El prototipo es: int ordenalfa (char* str1, char*str2);
// La función recibe dos strings cuyo contenido son palabras (solamente letras), y debe
// devolver -1 si str1 está antes que str2, 1 si str1 está después que str2 o 0 si str1
// y str2 son iguales. Debe ignorar mayúsculas y minúsculas (i.e: debe ser case
// insensitive) y no se pueden usar funciones de la librería string.

#include <stdio.h>

int ordenalfa(char* str1, char* str2);
void lower(char * str);
void print_str(char * str);
int str_len(char * str);

char word1[] = "aBcDefGhIjkLmnOpqRsTuVwXyZ";
char word2[] = "abcdefz";

char * w1 = word1;
char * w2 = word2;



int main(){

    lower(word1);
    lower(word2);

    int min_len;
    if (str_len(word1) > str_len(word2)) {
        min_len = str_len(word2);
    }
    else if (str_len(word2) > str_len(word1)){
        min_len = str_len(word1);
    }
    else{
        min_len = str_len(word1);
    }

    int matching_chars = 0;

    print_str(word1);
    print_str(word2);
    
    int order_state;
    for (int i=0; i<min_len; i++){
        if (*(word1+matching_chars) > *(word2+matching_chars)){
            order_state = 2;
        }
        if (*(word1+matching_chars) < *(word2+matching_chars)){
            order_state = 1;
        }
        else{
            order_state = 0;
        }
        matching_chars++;
    }
    switch (order_state){
        case (0): {
            printf("All strings are created equal\n");
            break;
        }
        case (1): {
            printf("String 1 comes first\n");
            break;
        }
        case (2): {
            printf("String 2 comes first\n");
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

void lower(char * str){
    for (int i=0; i<str_len(str); i++){
        if ((*(str+i)>='A') && (*(str+i)<='Z')){
            *(str+i) = *(str+i) + ('a'-'A');
        }
    }
}

void print_str(char * w1){
    for (char c=0; c<str_len(w1); c++){
        printf("%c", *(w1+c));
    }
    printf("\n");
}