#include <stdio.h>

#define DEAD 0
#define ALIVE 1

int main(){
    int M[8][8];
    char c;
    int cell_state;
    int row_counter = 0, col_counter = 0;

    while((c = getchar()) != EOF) {
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

    return 0;
}
// John Conway (1970) - The Game of Life
