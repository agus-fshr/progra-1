
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

// La palabra mas larga de la lengua espanola es electroencefalografista,
// que tiene 23 caracteres
#define MAX_LENGTH 23

// Constant definitions
#define 🤌 ((ch = getchar()) != '\n' && ch != EOF) && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && (i <= 23)
#define LEN_ERROR 10
#define CHAR_ERROR 20

// Function prototypes
int str_input(char *);
void flush_stdin(char);
void print_str(void);
int contar_len(char arr[]);
int sanitize_input(char arr[], int);

char palabra1[MAX_LENGTH + 1] = "cammila"; 
char palabra2[MAX_LENGTH + 1] = "mama";
int cont = 0;

int main(void) {
  // Input
  printf("Ingrese una palabra: ");
  str_input(palabra1);
  // Acá habría que validarla

  printf("Ingrese otra palabra: ");
  str_input(palabra2);
  // Acá habría que validarla

   

  // Lo que había


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
//      printf("LEN_ERROR: the string entered exceeds the 23 character limit.\n");
//      printf("There are both length and character errors in your entry. See: %c\n", arr[error_at]);





  // Lo de Juan


  char *pp1 = palabra1;
  char *pp2 = palabra2;
  int letras_encontradas = 0;
  int flag_letra_encontrada = 0;
  int letras_p2 = 0;
  while(*pp2){
    letras_p2++;

    flag_letra_encontrada = 0;
    
    pp1 = palabra1;
    while(*pp1 && !flag_letra_encontrada) {
      //printf("Comparando %c con %c\n", *(pp1), *(pp2));
      if(*pp1 == *pp2){
        flag_letra_encontrada = 1;
        letras_encontradas++;
        *pp1 = '_';
      }
      pp1++;
    }
    //printf("\n");
    pp2++;
  }
  if(letras_encontradas == letras_p2){
    printf("Nice!");
  } else {
    printf("No nice¡ :c");
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
int contar_len(char arr[]){
  int i = 0;
  int len = 0;
  while (arr[i++] != '\0'){
    len++;
  }
  return len;
}


void flush_stdin(char limit) {
    char c;
    // Hasta que se llegue al caracter especificado, vacía stdin
    while((c=getchar()) != limit) {}
}

int str_input(char *str) {
  char ch;
  char *p = str;

  int length_error = 0;

  while(!length_error && ((ch = getchar()) != '\n')) {
    *(p++) = ch;
    length_error = (str - p) == (MAX_LENGTH + 1);
  }
  if(length_error){
    return LEN_ERROR;
  }

  *p = '\0';
  return 0;
}


void validate_word(char arr[]) {
  int i = 0;
  int character_error = 0;
  int error_at = 0;

  while (arr[i++]) {
    int is_lowcase_letter = (arr[i] >= 'a') && (arr[i] <= 'z');
    int is_upper_letter = (arr[i] >= 'A') && (arr[i] <= 'Z');
    
    if (!(is_lowcase_letter || is_upper_letter || arr[i] == '\n')){
      character_error = CHAR_ERROR;
      error_at = i;
      break; 
    }   
  }

  if (character_error == CHAR_ERROR) {
    printf("CHAR_ERROR: there is an invalid character in your input. See: %c\n", arr[error_at]);
  }
}