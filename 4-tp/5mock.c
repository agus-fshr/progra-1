#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE 1
#define DEAD 0

#define OUTSIDE_STATE DEAD

#define ALIVE_CHAR '*'
#define DEAD_CHAR ' '

#define WORLD_WIDTH 15
#define WORLD_HEIGHT 15


void initialize_world(void); // Acá tiene que estar lo de selección de parser o mapa por defecto
int get_world_height(void);
int get_world_width(void);
int get_cell_state(int, int);
int read_num(void); // solo enteros positivos y si no es válido, pedirlo de nuevo
void print_world(void);
void advance_generation(void);
void clear_screen(void);
unsigned int read_adjacent_cells(int, int);
void world_from_file(void);
void copy_world(unsigned int[][WORLD_WIDTH], unsigned int[][WORLD_WIDTH]);

unsigned int world[WORLD_HEIGHT][WORLD_WIDTH];
unsigned int file_world[WORLD_HEIGHT][WORLD_WIDTH];
unsigned int total_generations = 0;
unsigned int default_world[][WORLD_WIDTH]/* = {
    {DEAD, DEAD, ALIVE, DEAD, ALIVE, DEAD, DEAD, DEAD, ALIVE, DEAD, ALIVE, DEAD, DEAD, ALIVE, DEAD},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
}*/;

int main(void){
    int exit_loop = 0;
    
    world_from_file();
    initialize_world();
    printf("\nGeneracion: %d\n", total_generations);
    print_world();

    while(!exit_loop) {
        printf("Ingrese el numero de generaciones que quiere avanzar o 'q' para salir: \n");
        int next_generations = read_num();
        if(next_generations == -1) {
            exit_loop = 1;
        }
        int i;
        for(i = 0; i < next_generations; i++) {
            advance_generation();
            clear_screen();
            printf("\n\nGeneracion: %d\n", ++total_generations);
            printf("Falta avanzar %d\n\n", next_generations-1-i);

            print_world();
            if(i != (next_generations - 1)){
                printf("Presione enter para avanzar una gen\n");
                getchar(); // para que muestre la generacion intermedia
            }
        }
    }

    printf("Nos vemos.");

    return 0;
}



/****************************
 *     Helper functions     *
*****************************/

int get_cell_state(int x, int y) {
    return world[x][y];
}

int get_world_height(void) {
    return WORLD_HEIGHT;
}

int get_world_width(void) {
    return WORLD_WIDTH;
}

void clear_screen(void){
    system("clear");
}

int read_num(void){
    char c;
    int nro = 0;

    while ((((c = getchar()) != '\n') && c != 'q') && (c >= '0' && c <= '9')){
        nro *= 10;
        nro += c - '0';
    }
    if(c == 'q'){
        return -1;
    }
    return nro;
}


void copy_world(unsigned int src[][WORLD_WIDTH], unsigned int tgt[][WORLD_WIDTH]) {
    for(int i = 0; i < get_world_height(); i++) {
        for(int j = 0; j < get_world_width(); j++) {
            tgt[i][j] = src[i][j];
        }
    }
}

void print_world(void) {
    int row, columns;
    for (row=0; row < get_world_height(); row++){
        printf(" _");
    }
    putchar('\n');
    for (row=0; row < get_world_height(); row++){
        putchar('|');
        for(columns=0; columns < get_world_width(); columns++){
            if(get_cell_state(row, columns) == ALIVE) {
                putchar(ALIVE_CHAR);
            } else {
                putchar(DEAD_CHAR);
            }
            putchar('|');
        }
        printf("\n");
    }
}


/****************************
 *      Game functions      *
*****************************/

/*
una celula viva con exactamente dos o tres vecinos sobrevive;
una celula muerta con exactamente tres vecinos obtiene vida nuevamente.
*/
void advance_generation(void) {
    int i_col, i_fil;
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
    
    copy_world(next_world, world);
}

unsigned int read_adjacent_cells(int x, int y) {
    int alive_neighbours = 0;
    int n, m;
    int out_of_map_rows;
    int out_of_map_cols;
    
    for(n = x-1; n <= x+1; n++){
        out_of_map_rows = (n == -1) || (n == get_world_height());
        if(out_of_map_rows == 0){
            for(m = y-1; m <= y+1; m++){
                out_of_map_cols = (m == -1) || (m == get_world_width());
                alive_neighbours += out_of_map_cols ? OUTSIDE_STATE : get_cell_state(n, m);
            }
        }
        else {
            // Why 3
            alive_neighbours += 3*OUTSIDE_STATE;
        }
    }
    alive_neighbours -= get_cell_state(x, y); // Para descontar el estado de la celda central
    return alive_neighbours;
}


/****************************
 *      Setup functions     *
*****************************/

void world_from_file() {
    char c;
    int row_counter = 0, col_counter = 0;
    
    while((c = getchar()) != 'f') {
        switch (c){
            case(DEAD_CHAR):{
                file_world[row_counter][col_counter] = DEAD;
                ++col_counter;
                break;
            }
            case(ALIVE_CHAR):{
                file_world[row_counter][col_counter] = ALIVE;
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
    
    printf("Mundo cargado\n");
}

void initialize_world(void){
    char c;
    printf("Ingrese una 'i' para iniciar el programa\n");
    while((c = getchar()) != 'i'){}
    getchar();
    printf("Bienvenido. Quiere importar el mapa desde el archivo? (y=si / n=no): \n");
    
    c = getchar();
    
    if(c == 'y') {
        printf("Copiando mundo del archivo\n");
        copy_world(file_world, world);
    }
    else {
        printf("Cargando mundo por defecto\n");
        copy_world(default_world, world);
    }
    getchar();
}