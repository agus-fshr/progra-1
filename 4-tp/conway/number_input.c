#include <stdio.h>

#define DEAD 0
#define ALIVE 1
#define MATRIX_SIZE 20

int main(){
    int M[MATRIX_SIZE][MATRIX_SIZE];
    char c;
    int cell_state;
    int row_counter = 0, col_counter = 0;
    char testing_shit;

    while((c = getchar()) != 'f') {
        switch (c){
            case(' '):{
                cell_state = DEAD;
                M[row_counter][col_counter] = cell_state;
                ++col_counter;
                break;
            }
            case('*'):{
                cell_state = ALIVE;
                M[row_counter][col_counter] = cell_state;
                ++col_counter;
                break;
            }
            case('\n'):{
                ++row_counter;
                col_counter = 0;
                break;
            }
            default:{
                break;
            }
        }
        // M[row_counter][col_counter] = cell_state;
    }

    int row, columns;
        for (row=0; row<=row_counter; row++){
        for(columns=0; columns<col_counter; columns++){
            printf("%d  ", M[row][columns]);
        }
        printf("\n");

    
}
    while((testing_shit = getchar()) != '\n'){
        putchar(testing_shit);
    }

    return 0;
}
// John Conway (1970) - The Game of Life
