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

// Constant definitions
#define 🤌 ((ch = getchar()) != '\n' && ch != EOF) && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && (i <= 23)
#define LEN_ERROR 10
#define CHAR_ERROR 20

// Function prototypes
void strInput(char str[]);
void print_str(void);
int contar_len(char arr[]);
int sanitize_input(char arr[], int);


char palabra1[24] = "cammila"; 
char palabra2[24] = "mama";
int cont = 0;

int main(void) {

  print_str();
  int len1 = contar_len(palabra1);
  int len2 = contar_len(palabra2);

  

  int irasig = 0;

  // Iterates over each char in palabra2 and looks for an unused match in palabra1
  for(int i=0; i < len2 - 1; i++){
      irasig = 0;
      for(int j=0; (j < len1 - 1) && !irasig; j++){
          if(palabra2[i] == palabra1[j]){
              cont++;
              palabra1[j] = -1;
              irasig = 1;
          }
      }
  }

  // Prints the outcome of the program
  if(cont == len2 - 1){
    printf("si, %d, %d\n", cont, len2);                                 // TODAVIA HAY QUE DEJAR LINDO ESTO
  }
  else{
    printf("no, %d, %d\n", cont, len2);
  }
}

// Prints out the two input strings
void print_str(void){
  int n = 0;
    while (palabra1[n] != '\0') {
        printf("%c", palabra1[n++]);
    }
    printf("\n");
    n=0;

    // strInput(palabra2);
    while (palabra2[n] != '\0') {
        printf("%c", palabra2[n++]);
    }
    printf("\n");
}

// Counts the length of each input string
int str_len(char arr[]){
  int i = 0;
  int len = 0;
  while (arr[i++] != '\0'){
    len++;
  }
  return len;
}

void strInput(char str[]) {
  int i = 0;
  int ch;
  while(🤌) {
    str[i++] = ch;
  }
  str[i] = '\0';
  
}

int sanitize_input(char arr[], int len){
  int len_error = 0;
  int character_error = 0;
  if (len > 24){
    len_error = LEN_ERROR;
  }
  else {
    len_error = 0;
  }

  for (int i=0; i<=len; i++) {
    if (((arr[i] >= 'a') && (arr[i] <= 'z') || ((arr[i] >= 'A') && (arr[i] <= 'Z'))) || (arr[i] == '\n')){
      character_error = 0;
    }
    else{
      character_error = CHAR_ERROR;
      break;
    }
  }

  error_code = character_error + len_error;

  switch (error_code) {
    case (LEN_ERROR): {
      printf("LEN_ERROR: the string entered exceeds the 23 character limit.\n");
      break;
    }
    case (CHAR_ERROR): {
      printf("CHAR_ERROR: there is an invalid character in your input. See: %c\n", arr[i]);
      break;
    }
    case (CHAR_ERROR + LEN_ERROR): {
      printf("There are both length and character errors in your entry. See: %c\n", arr[i]);
      break;
    }
  }
}