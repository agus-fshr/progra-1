#include <stdio.h>
#include <stdlib.h>

#define ALIVE 1
#define DEAD 0

#define OUTSIDE_STATE DEAD

#define ALIVE_CHAR '*'
#define DEAD_CHAR ' '

#define WORLD_WIDTH 4
#define WORLD_HEIGHT 4


void initialize_world(void); // Acá tiene que estar lo de selección de parser o mapa por defecto
int get_world_height(void);
int get_world_width(void);
int get_cell_state(int, int);
void set_cell_state(int, int, int);
void print_world(void);
unsigned int read_num(void); // solo enteros positivos y si no es válido, pedirlo de nuevo
void advance_generation(void);
void clear_screen(void);
unsigned int read_adjacent_cells(int, int);
void world_from_file(void);
void load_default_world(void);

unsigned int world[WORLD_HEIGHT][WORLD_WIDTH];
unsigned int total_generations;

int main(void){
    printf("Arranque\n");
    char c;

    initialize_world();
    print_world();

    while((c = getchar()) != 'q') {
        unsigned int next_generations = 1;
        printf("\n Num leido: %d\n", next_generations);
        total_generations += next_generations;
        int i;
        for(i = 0; i < next_generations; i++) {
            advance_generation();
            // acá algo de printeo lindo quizás 
            // podríamos poner el núm de generaciones pasadas, x ej.
            printf("\n\nSiguiente generación: \n\n");
            print_world();
            //clear_screen();
        }
    }

    printf("A ksita");

    return 0;
}
/*
una celula viva con exactamente dos o tres vecinos sobrevive;
una celula muerta con exactamente tres vecinos obtiene vida nuevamente.
*/
void advance_generation(void) {
    int i_col, i_fil, i;
    unsigned int next_world[WORLD_HEIGHT][WORLD_WIDTH];
    for(i_col = 0; i_col < get_world_width(); i_col++) {
        for(i_fil = 0; i_fil < get_world_height(); i_fil++) {
            int adjacent_living = read_adjacent_cells(i_fil, i_col);
            int cell_state = get_cell_state(i_fil, i_col);
            int next_state = DEAD;
            if(cell_state == ALIVE) {
                if(adjacent_living == 2 || adjacent_living == 3) {
                    next_state = ALIVE;
                }
            }
            else {
                if(adjacent_living == 3) {
                    next_state = ALIVE;
                }
            }
            next_world[i_fil][i_col] = next_state;
        }
    }
    
    // copiar matriz a world
    for(i = 0; i < WORLD_HEIGHT; i++) {
        for(int j = 0; j < WORLD_WIDTH; j++) {
            world[i][j] = next_world[i][j];
        }
    }

}
unsigned int read_num(void){
    char c;
    int nro = 0;
    while (((c = getchar()) && c != '\n') && (c>='0' && c<='9')){
        nro = nro * 10.0;
        nro += c - '0';
    }
    return nro;
}

void world_from_file() {
    int M[WORLD_HEIGHT][WORLD_WIDTH];
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
}

unsigned int read_adjacent_cells(int x, int y) {
    int alive_neighbours = 0;
    int n, m;
    int out_of_map_rows;
    int out_of_map_cols;
    
    for(int n = x-1; n <= x+1; n++){
        out_of_map_rows = (n == -1) || (n == get_world_height());
        if(out_of_map_rows == 0){
            for(int m = y-1; m <= y+1; m++){
                out_of_map_cols = (m == -1) || (m == get_world_width());
                alive_neighbours += out_of_map_cols ? OUTSIDE_STATE : get_cell_state(n, m);
            }
        }
        else {
            // Why 3
            alive_neighbours += 3*OUTSIDE_STATE;
        }
    }
    return alive_neighbours;
}

void initialize_world(void){
    printf("Bienvenido. Quiere importar el mapa desde el archivo? (y=si / n=no)\n");
    char c = getchar();
    /*
    if(c == 'y') {
        world_from_file();
    }
    else {
        */
        printf("Cargando mundo por defecto\n");
        load_default_world();
    //}
}

void load_default_world(void){
    int temp_world[][4] = {{0, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    for(int i = 0; i < WORLD_HEIGHT; i++) {
        for(int j = 0; j < WORLD_WIDTH; j++) {
            world[i][j] = temp_world[i][j];
        }
    }
}

int get_cell_state(int x, int y) {
    return world[x][y];
}

int get_world_height(void) {
    return WORLD_HEIGHT;
}

int get_world_width(void) {
    return WORLD_WIDTH;
}

void print_world(void) {
    int row, columns;
    for (row=0; row < get_world_height(); row++){
        for(columns=0; columns < get_world_width(); columns++){
            printf("%d  ", world[row][columns]);
        }
        printf("\n");
    }
}

void clear_screen(void){
    system("clear");
}