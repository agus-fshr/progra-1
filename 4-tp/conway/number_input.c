#include <stdio.h>

#define DEAD 0
#define ALIVE 1

int main(){
    int M[8][8];
    char c;
    int cell_state;
    int row_counter, col_counter;

    while((c = getchar()) != EOF) {
        switch (c){
            case(' '):{
                cell_state = DEAD;
                col_counter++;
                break;
            }
            case('*'):{
                cell_state = ALIVE;
                col_counter++;
                break;
            }
            case('\n'):{
                row_counter++;
                break;
            }
        }
        M[row_counter][col_counter] = cell_state;
    }

    for (int i=0; i<=row_counter; i++){
        for(int n=0; n<=col_counter; n++){
            printf("%d  ", M[i][n]);
        }
        printf("\n");
    }

    return 0;
}
// John Conway (1970) - The Game of Life