#include <stdio.h>

#define ALIVE 1
#define DEAD 0

#define ALIVE_CHAR '*'
#define DEAD_CHAR ' '

#define WORLD_WIDTH 10
#define WORLD_HEIGHT 10


void initialize_world(void); // Acá tiene que estar lo de selección de parser o mapa por defecto
int get_world_height(void);
int get_world_width(void);
int get_cell_state(int x, int y);
void set_cell_state(int x, int y, int state);
void print_world(void);
unsigned int read_num(void); // solo enteros positivos y si no es válido, pedirlo de nuevo
void advance_generation(void);
void clear_screen(void);
unsigned int read_adjacent_cells(int x, int y);

unsigned int world[WORLD_HEIGHT][WORLD_WIDTH];
unsigned int total_generations;

int main(void){
    char c;

    initialize_world();
    // acá va a haber algo que 

    while((c = getchar()) != 'q') {
        unsigned int next_generations = read_num();
        total_generations += next_generations;

        int i;
        for(i = 0; i < next_generations; i++) {
            advance_generation();
            // acá algo de printeo lindo quizás 
            // podríamos poner el núm de generaciones pasadas, x ej.
            print_world();
            clear_screen();
        }

    }

    printf("A ksita");

    return 0;
}

void advance_generation(void) {
    int i_col, i_fil;
    next_gen
    for(i_col = 0; i_col < get_world_width(); i_col++) {
        for(i_fil = 0; i_fil < get_world_height(); i_fil++) {
            int adjacent_living = read_adjacent_cells(i_col, i_fil);
            if(tal condicion)
            else if(tal condicion)
            etc etc
            esto lo tiene que guardar en next_gen
        }
    }
    acá guardar next gen en el mundo actual
}