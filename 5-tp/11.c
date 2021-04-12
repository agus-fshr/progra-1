
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

// Function prototypes
int str_input(char*);
void flush_stdin(char);
int validate_word(char*);
void take_word(char*);


int main(void) {
  // Declaration of both word input arrays
  char word1[MAX_LENGTH + 1];
  char word2[MAX_LENGTH + 1];

  // Input
  printf("Enter word 1: ");
  take_word(word1);

  printf("Enter word 2: ");
  take_word(word2);

  // Creation of word pointers and counters
  char *pw1 = word1;
  char *pw2 = word2;
  int matched_letters = 0;
  int flag_letter_match = 0;
  int letters_w2 = 0;

  while(*pw2){    // Loops until a \0 char is found, marking the 
                  // end of the input word

    letters_w2++; // Counter used to iterate through each element of w2

    flag_letter_match = 0;
    
    pw1 = word1;

    // While the current element is a letter of w1 and the 
    // letters do not match
    while(*pw1 && !flag_letter_match) {
    
      // This condition checks if the letters match
      if(*pw1 == *pw2){

        // Sets the matching letter flag to 1
        flag_letter_match = 1;

        // Increases the matched letter count
        matched_letters++;

        // Replaces element of w1 for '_', as to not count it more than once
        *pw1 = '_';
      }

      // Increment pw1 to move to the next letter
      pw1++;
    }

    // Moves to the next letter of w2
    pw2++;
  }


  // If the number of letters that match between w2 and w1, that means that 
  // w2 can be formed using only letters found in w1.
  if(matched_letters == letters_w2){
    printf("Nice!");
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
    return 1;
  }

  *p = '\0';
  return 0;
}

// Checks if an entered string is valid for the program or not
int validate_word(char arr[]) {
  int i = 0;

  while (arr[i]) {
    int is_lowcase_letter = (arr[i] >= 'a') && (arr[i] <= 'z');
    int is_upper_letter = (arr[i] >= 'A') && (arr[i] <= 'Z');
    
    if (!(is_lowcase_letter || is_upper_letter || arr[i] == '\n')){
      return i;
    }
    i++;
  }
  return -1;
}

void take_word(char word[]) {
  int valid_word = 0;
  while(!valid_word) {
    valid_word = str_input(word) == 0;
    if(!valid_word) {
      printf("LENGTH ERROR: that spanish word doesn't exist, try again\n");
    } else {
      int error_index = -1;
      if((error_index = validate_word(word)) != -1) {
        printf("CHAR_ERROR: there is an invalid character in your input. See: '%c'\n", word[error_index]);
        valid_word = 0;
      }
    }
  }
}