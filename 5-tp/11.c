/*
    TP5 - Ejercicio 11 - Grupo 7 (FISHER, MARTINEZ TANOIRA, SBRUZZI, OMS)
    Consigna:
      Implementar un programa que reciba del usuario dos palabras y
      determine si la segunda de ellas puede formarse completamente con letters
      contenidas en la primera. Por ejemplo, morsa/rosa, japoneses/esponja.
        a. Recuerden validar los datos ingresados por el usuario. Si el usuario ingresa
          datos que no son válidos el programa debe detectarlo e indicar el error.
        b. Al verificar si la segunda palabra puede formarse con las letras de la primera,
          debe tomarse en cuenta cuantas veces aparece cada letra. Por ejemplo, "mama"
          no puede formarse con las letras de la palabra "camilla" porque falta una 'm'.
        c. Se puede ignorar acentos y la letra ñ para simplificar el programa.


    Criterios de diseño:
      - Se permite el ingreso de letras mayúsculas y minúsculas, pero se considera 
        una misma letra. Es decir, "JaPoNeSES" y "esPONJA" daría un resultado positivo.
      - No se consideran válidos los caracteres acentuados y la ñ.
      - Se consideran válidas las palabras en español: por eso surge la cota superior
        de 23 letras para una palabra correcta.
*/

#include <stdio.h>


// Function return definitions
#define ERROR 1
#define NO_ERROR -1

// The longest word in the spanish language is "electroencefalografista",
// which has a length of 23 characters.
#define MAX_LENGTH 23

/********************
 * Func. prototypes *
 ********************/

void flush_stdin(char);
void string_to_lowercase(char*);
unsigned int string_length(char*);

int input_string_to(char*, unsigned int);
int validate_word(char*);
void handle_word_input(char*);
unsigned int common_letters_count(char*, char*);


/******************
 * Main function  *
 ******************/

int main(void) {
  // Declaration of both word input arrays
  char first_word[MAX_LENGTH + 1];
  char second_word[MAX_LENGTH + 1];

  // Input
  printf("Enter word 1: ");
  handle_word_input(first_word);
  printf("Enter word 2: ");
  handle_word_input(second_word);
  
  // Normalization
  string_to_lowercase(first_word);
  string_to_lowercase(second_word);

  // If the number of letters that match between w2 and w1, that means that 
  // w2 can be formed using only letters found in w1.
  unsigned int shared_letters = common_letters_count(first_word, second_word);
  if(shared_letters == string_length(second_word)){
    printf("The second word can be formed using the letters from the first one\n");
  } else {
    printf("The second word can't be formed using the letters from the first one\n");
  }

  return 0;
}


/*********************
 * Func. definitions *
 *********************/

/* Function flush_stdin
 * Flushes the stdin input buffer
 * (empties stdin until it finds the desired char)
 * 
 * Parameters:
 * - limit: the last char to read from stdin
 */
void flush_stdin(char limit) {
    char c;
    // Flushes each character until the desired terminator is found
    while((c=getchar()) != limit) {}
}

/* Function string_length
 * Parameters:
 * - word: the string to analyze
 * Returns the length of the string (not counting the terminator)
 */
unsigned int string_length(char *word){
  unsigned int counter = 0;
  while(*word) {     // Loops until a \0 char is found
    counter++;
    word++;
  }
  return counter;
}

/* Function string_to_lowercase
 * Transforms a string to lowercase, without erasing any
 * non-letter symbols.
 * Parameters:
 * - word: where the resulting string will be saved
 */
void string_to_lowercase(char* word) {
  char *p =  word;      // temporal pointer
  while(*p) {           // While the letter isn't the terminator '\0'
    if(*p >= 'A' && *p <= 'Z') {  // If it's uppercase
      *p -= 'A' - 'a';            // Make it lowercase
    }
    p++;                // Check next char
  }
}

/* Function input_string_to
 * Takes a string as input from the command line and saves it in an array
 * Parameters:
 * - str: pointer where string is saved
 * - max_chars: maximum chars to read (not counting the terminator)
 * Returns an integer:
 * - ERROR if the maximum chars were exceded.
 * - NO_ERROR if the length of the string is ok.
 */
int input_string_to(char *str, unsigned int max_chars) {
  char ch;
  char *p = str;                // Temporal pointer

  while((ch = getchar()) != '\n') {
    *(p++) = ch;                // Assign input to word
    if((p - str) == (int) (max_chars + 1)){
      // (the cast is needed because max_chars is uint but the
      // substraction p-str is a signed int)
      // If the next letter should be the terminator
      *p = '\0';                // Add the terminator
      flush_stdin('\n');        // Empty stdin
      return ERROR;
    }
  }

  *p = '\0';
  return NO_ERROR;
}

/* Function validate_word
 * Checks if the entered string contains only letters 
 * (spaces aren't allowed)
 * Parameters:
 * - arr: the array containing the word to validate
 * Returns an integer:
 * - NO_ERROR if the word is, indeed, a single word.
 * - A number >= 0 indicating the index of the first error.
 */
int validate_word(char *arr) {
  int i = 0;

  while (arr[i]) {    // While the letter isn't the terminator '\0'
    int is_lowcase_letter = (arr[i] >= 'a') && (arr[i] <= 'z');
    int is_uppercase_letter = (arr[i] >= 'A') && (arr[i] <= 'Z');
    
    if (!(is_lowcase_letter || is_uppercase_letter)){
      return i;       // If the condition was met, the current char isn't a letter
    }
    i++;              // Check next char
  }
  return NO_ERROR;
}

/* Function handle_word_input
 * Handles a single word input from the user.
 * Shows error messages, allowing the user to retry.
 * Parameters:
 * - word: where the resulting string will be saved
 */
void handle_word_input(char *word) {
  int valid_word = 0;
  while(!valid_word) {
    if(input_string_to(word, MAX_LENGTH) == ERROR) {
      printf("LENGTH ERROR: that spanish word doesn't exist.\n");
      printf("Try again: ");
    } else {
      int error_index = -1;
      if((error_index = validate_word(word)) != NO_ERROR) {
        printf("CHAR_ERROR: there is an invalid character ('%c') in your input.\n", word[error_index]);
        printf("Try again: ");
      } else {
        valid_word = 1;
      }
    }
  }
}

/* Function common_letters_count
 * Counts how many letters match both words, counting
 * reocurrences.
 * Parameters:
 * - word1 and word2: the strings to compare
 */
unsigned int common_letters_count(char *word1, char *word2) {
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

  return matched_letters;
}