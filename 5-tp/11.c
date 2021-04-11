
// Implementar un programa que reciba del usuario dos palabras y
// determine si la segunda de ellas puede formarse completamente con letters
// contenidas en la primera. Por ejemplo, morsa/rosa, japoneses/esponja.


// a. Recuerden validar los datos ingresados por el usuario. Si el usuario ingresa
// datos que no son válidos el programa debe detectarlo e indicar el error.

// b. Al verificar si la segunda palabra puede formarse con las letras de la primera,
// debe tomarse en cuenta cuantas veces aparece cada letra. Por ejemplo, "mama"
// no puede formarse con las letras de la palabra "camilla" porque falta una 'm'.

// c. Se puede ignorar acentos y la letra ñ para simplificar el programa.

#include <stdio.h>

// The longest word in the spanish language is "electroencefalografista",
// which has a length of 23 characters.
#define MAX_LENGTH 23

// Constant definitions
#define LEN_ERROR 10
#define CHAR_ERROR 20

// Function prototypes
int str_input(char *);
void flush_stdin(char);
int validate_word(char arr[]);


int main(void) {

  // Declaration of both word input arrays
  char word1[MAX_LENGTH + 1]; 
  char word2[MAX_LENGTH + 1];

  // Input
  int valid_word = 0;
  do {
    printf("Enter word 1: ");
    valid_word = str_input(word1) == 0;
    if(!valid_word) {
      printf("LENGTH ERROR: that spanish word doesn't exist, try again\n");
    } else {
      int error_index = -1;
      if((error_index = validate_word(word1)) != -1) {
        printf("CHAR_ERROR: there is an invalid character in your input. See: %c\n", word1[error_index]);
        valid_word = 0;
      }
    }
  } while(!valid_word);
  

  valid_word = 0;
  do {
    printf("Enter word 2: ");
    valid_word = str_input(word2) == 0;
    if(!valid_word) {
      printf("LENGTH ERROR: that's not a valid spanish word, try again\n");
    } else {
      int error_index = -1;
      if((error_index = validate_word(word2)) != -1) {
        printf("CHAR_ERROR: there is an invalid character in your input. See: %c\n", word2[error_index]);
        valid_word = 0;
      }
    }
  } while(!valid_word);

  // Creation of word pointers and counters
  char *pw1 = word1;
  char *pw2 = word2;
  int matched_letters = 0;
  int flag_letter_match = 0;
  int letters_w2 = 0;

  while(*pw2){    // Loops until a \0 char is found, marking the end of the input word
    letters_w2++; // Counter usedto iterate through each element of w2

    flag_letter_match = 0;
    
    pw1 = word1;
    while(*pw1 && !flag_letter_match) { // While the current element is a letter of w1 and the letters do not match
    
      if(*pw1 == *pw2){                 // This condition checks if the letters match
        flag_letter_match = 1;          // Sets the matching letter flag to 1
        matched_letters++;              // Increases the matched letter count
        *pw1 = '_';                     // Replaces that element of w1 for a '_', as to not count it more than once
      }
      pw1++;
    }

    pw2++;                              // Moves to the next letter of w2
  }
  if(matched_letters == letters_w2){    // If the number of letters that match between w2 and w1, that means that 
    printf("Nice!");                    // w2 can be formed using only letters found in w1.
  } else {
    printf("Not nice! :c");
  }

}

// Function Definitions


// Flushes the stdin input buffer
void flush_stdin(char limit) {
    char c;
    // Flushes each character until the desired terminator is found
    while((c=getchar()) != limit) {}
}

// Takes a string as input from the command line and saves it in an array
int str_input(char *str) {
  char ch;
  char *p = str;

  int length_error = 0;

  while(!length_error && ((ch = getchar()) != '\n')) {
    *(p++) = ch;
    length_error = (p - str) == (MAX_LENGTH + 1);
  }
  if(length_error){
    flush_stdin('\n');
    return LEN_ERROR;
  }

  *p = '\0';
  return 0;
}

// Checks if an entered string is valid for the program or not
int validate_word(char arr[]) {
  int i = 0;
  int character_error = 0;
  int error_at = 0;

  while (arr[i]) {
    int is_lowcase_letter = (arr[i] >= 'a') && (arr[i] <= 'z');
    int is_upper_letter = (arr[i] >= 'A') && (arr[i] <= 'Z');
    
    if (!(is_lowcase_letter || is_upper_letter || arr[i] == '\n')){
      character_error = CHAR_ERROR;
      return i;
    }
    i++;
  }

  return -1;
}