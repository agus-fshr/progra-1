// Implementar un programa que reciba del usuario dos palabras y
// determine si la segunda de ellas puede formarse completamente con letras
// contenidas en la primera. Por ejemplo, morsa/rosa, japoneses/esponja.


// a. Recuerden validar los datos ingresados por el usuario. Si el usuario ingresa
// datos que no son válidos el programa debe detectarlo e indicar el error.

// b. Al verificar si la segunda palabra puede formarse con las letras de la primera,
// debe tomarse en cuenta cuantas veces aparece cada letra. Por ejemplo, "mama"
// no puede formarse con las letras de la palabra "camilla" porque falta una 'm'.

// c. Se puede ignorar acentos y la letra ñ para simplificar el programa.

#include <stdio.h>

void strInput(char str[]);

    char palabra1[23]; 
    char palabra2[23];

int main(void) {

    // La palabra mas larga de la lengua espanola es electroencefalografista
    // tiene 23 caracteres

    strInput(palabra1);
    int n = 0;
    while (palabra1[n] != '\0') {
        printf("%c", palabra1[n++]);
    }
    printf("\n");
    n=0;

    strInput(palabra2);
    while (palabra2[n] != '\0') {
        printf("%c", palabra2[n++]);
    }
    printf("\n");

}

// char str_input(void){
//     char *p, c;

//     *p = &palabra1;
//     while ((c = getchar()) != '\n') {
//         if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))){
//             *p = c;
//             p++;
//         }

//     }
// }

void strInput(char str[]) {
  int i = 0;
  int ch;
  while((ch = getchar()) != '\n' && ch != EOF ) {
    str[i++] = ch;
  }
  str[i] = '\0';
}