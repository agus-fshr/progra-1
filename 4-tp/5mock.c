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
void world_from_stdin(void);
void copy_world(unsigned int[][WORLD_WIDTH], unsigned int[][WORLD_WIDTH]);
void flush_stdin(char);

unsigned int world[WORLD_HEIGHT][WORLD_WIDTH];
unsigned int stdin_world[WORLD_HEIGHT][WORLD_WIDTH];
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
}*/; //TODO: acá poner un estado x defecto

int main(void){
    int exit_loop_flag = 0;
    
    world_from_stdin();      // carga en temporal el mapa del archivo
    initialize_world();     // decide qué mapa se usará como estado inicial
    printf("Generacion: %d", total_generations);
    print_world();

    while(!exit_loop_flag) {
        int i;

        printf("Ingrese el numero de generaciones que quiere avanzar o 'q' para salir: \n");
        int next_generations = read_num();      // lee un numero o salida
        if(next_generations == -1) {      
            exit_loop_flag = 1;
        }

        for(i = 0; i < next_generations; i++) {
            advance_generation();       // calcular una generación y pasarla al estado
            clear_screen();             // limpiar pantalla
            printf("\n\nGeneracion: %d\n", ++total_generations);
            printf("Falta avanzar %d\n\n", next_generations-1-i);

            print_world();
            if(i != (next_generations - 1)){    // si no se está en la última gen a avanzar
                printf("Presione enter para avanzar una gen\n");
                getchar(); // para que muestre la generación intermedia
            }
        }
    }

    printf("Nos vemos.");

    return 0;
}



/****************************
 *     Helper functions     *
*****************************/

/*
 * Función get_cell_state
 * Argumentos:
 *      - x: la fila de la celda
 *      - y: la columna de la celda
 * Devuelve el estado de una celda
*/
int get_cell_state(int x, int y) {
    return world[x][y];
}

/*
 * Función get_world_height
 * Devuelve la altura del mapa
*/
int get_world_height(void) {
    return WORLD_HEIGHT;
}

/*
 * Función get_world_width
 * Devuelve el ancho del mapa
*/
int get_world_width(void) {
    return WORLD_WIDTH;
}

/*
 * Función clear_screen
 * Limpia stdout
*/
void clear_screen(void) {
    system("clear");
}

/*
 * Función flush_stdin
 * Argumentos:
 *      - limit: finaliza
 * Toma caracteres de stdin hasta llegar
 * al caracter especificado
*/
void flush_stdin(char limit) {
    char c;
    while((c=getchar()) != limit) {}
}

/*
 * Función read_num
 * Lee un número entero sin signo de stdin
 * Todos los caracteres no numéricos, excepto q y \n, se ignoran o provocarán
 * el corte de la lectura, sin levantar error.
 * Sin embargo, si se incluye una q en algún lugar de la entrada, la salida
 * será -1, marcando error.
*/
int read_num(void) {
    char c;
    int nro = 0;


    while ((((c = getchar()) != '\n') && c != 'q') && (c >= '0' && c <= '9')){
        nro *= 10;
        nro += c - '0';
    }
    if(c == 'q'){
        return -1;
    }
    // poner algo que vacie el stdin sería ideal, hay que tener cuidado
    return nro;
}

/*
 * Función copy_world
 * Copia una matriz del tamaño especificado por los #define.
 * Argumentos:
 *      - src: matriz de origen
 *      - tgt: matriz de destino
*/
void copy_world(unsigned int src[][WORLD_WIDTH], unsigned int tgt[][WORLD_WIDTH]) {
    for(int i = 0; i < get_world_height(); i++) {
        for(int j = 0; j < get_world_width(); j++) {
            tgt[i][j] = src[i][j];
        }
    }
}

/*
 * Función print_world
 * Imprime a stdout el estado actual del mundo,
 * con formato embellecido.
*/
void print_world(void) {
    int row, columns;
    putchar('\n');
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
*/
/*
 * Función advance_generation
 * Realiza un avance en la generación actual, analizando
 * el estado futuro de todas las celdas. Antes de salir,
 * guarda en el estado actual del sistema la generación
 * calculada.
 * 
 * Implementa la lógica del Juego de la Vida de James Conway,
 * de acuerdo a las siguientes reglas:
 * 
 *  - Una celda viva con exactamente dos o tres vecinos sobrevive;
 *  - Una celda muerta con exactamente tres vecinos obtiene vida.
 * En el resto de los casos, morirá o seguirá muerta.
*/
void advance_generation(void) {
    int i_col, i_fil;
    unsigned int next_world[WORLD_HEIGHT][WORLD_WIDTH];
    // En next_world se almacena el estado futuro temporalmente
    for(i_col = 0; i_col < get_world_width(); i_col++) {
        for(i_fil = 0; i_fil < get_world_height(); i_fil++) {
            int adjacent_living = read_adjacent_cells(i_fil, i_col);
            // adjacent_living almacena el número de las celdas
            // vivas que se encuentran próximas a la celda
            int cell_state = get_cell_state(i_fil, i_col); // estado actual
            int next_state = DEAD;
            if(cell_state == ALIVE) {
                if(adjacent_living == 2 || adjacent_living == 3) {
                    // Si está viva y tiene 2 o 3 células vivas
                    // próximas, debe seguir viva.
                    next_state = ALIVE;
                }
            }
            else {
                if(adjacent_living == 3) {
                    // Si está muerta y tiene 3 celdas vivas
                    // próximas, debe vivir.
                    next_state = ALIVE;
                }
            }
            // guarda en la var temporal el estado calculado de la celda
            next_world[i_fil][i_col] = next_state; 
        }
    }
    
    copy_world(next_world, world); // copia el mundo calculado al estado actual
}

/*
 * Función read_adjacent_cells
 * Argumentos:
 *      - x: fila de la celda a analizar
 *      - y: columna de la celda a analizar
 * Calcula el número de celdas colindantes con la
 * deseada que se encuentran vivas.
*/
unsigned int read_adjacent_cells(int x, int y) {
    int alive_neighbours = 0;   // acumulador de vecinos vivos
    int n, m;
    int out_of_map_rows;        // condición de overflow de borde en fila
    int out_of_map_cols;        // condición de overflow de borde en columna
    
    for(n = x-1; n <= x+1; n++){    // itera por 3 filas centradas en x
        // calcula condición: si se quiere analizar la fila -1 o
        // la fila que coincida con la altura del mapa, no debe
        // intentar acceder a la matriz
        out_of_map_rows = (n == -1) || (n == get_world_height());
        if(!out_of_map_rows){
            for(m = y-1; m <= y+1; m++){ // itera por 3 filas centradas en y
                // calcula condición: si se quiere analizar la columna -1 o
                // la fila que coincida con el ancho del mapa, no debe
                // intentar acceder a la matriz
                out_of_map_cols = (m == -1) || (m == get_world_width());
                // Si la columna está fuera del mapa, cuenta un OUTSIDE_STATE (configurable)
                // mientras que si no, recupera el estado de esa celda
                alive_neighbours += out_of_map_cols ? 
                    OUTSIDE_STATE : get_cell_state(n, m) == ALIVE;
            }
        }
        else {
            // Es configurable el comportamiento de las celdas
            // del borde externo del mapa, por lo que si se
            // quiere analizar una fila que está fuera del mapa
            // se deben contar 3 celdas en ese estado
            alive_neighbours += 3*OUTSIDE_STATE;
        }
    }
    // Si está viva, se debe restar el valor sumado por contar
    // la celda del medio (solo se quiere el número de vecinos)
    alive_neighbours -= get_cell_state(x, y) == ALIVE; 
    return alive_neighbours;
}

/****************************
 *      Setup functions     *
*****************************/

/*
 * Función world_from_stdin
 * Lee un mapa del tamaño especificado por la parametrización
 * del programa. Se puede ingresar a mano o pipeando un .txt
 * Es un REQUISITO que al terminar, se ingrese una f.
 * No es necesario un separador en especial entre valores.
 * No se sanitiza, pero se "truncará" el input. Si se pasa de columnas,
 * lo incluirá en la siguiente de la matriz.
*/
void world_from_stdin() {
    char c;
    int row_counter = 0, col_counter = 0;
    
    while((c = getchar()) != 'f') {
        switch (c){
            case(DEAD_CHAR):{
                stdin_world[row_counter][col_counter] = DEAD;
                ++col_counter;
                break;
            }
            case(ALIVE_CHAR):{
                stdin_world[row_counter][col_counter] = ALIVE;
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


/*
 * Función initialize_world
 * Lee un mapa del tamaño especificado por la parametrización
 * del programa. Se puede ingresar a mano o pipeando un .txt
 * Es un REQUISITO que al terminar, se ingrese una f.
 * No es necesario un separador en especial entre valores.
 * No se sanitiza, pero se "truncará" el input. Si se pasa de columnas,
 * lo incluirá en la siguiente de la matriz.
*/
void initialize_world(void){
    char c;
    printf("Ingrese una 'i' para iniciar el programa\n");
    flush_stdin('i');
    getchar();      // Necesario para sacar el \n posterior al while del buffer
    printf("Bienvenido. Quiere utilizar el mapa cargado por stdio? ('y'=si / 'n'=no): \n");
    
    c = getchar();  // toma el input del usuario
    
    if(c == 'y') {
        printf("Copiando mundo del stdin\n");
        copy_world(stdin_world, world);
    }
    else {
        printf("Cargando mundo por defecto\n");
        copy_world(default_world, world);
    }
    flush_stdin('\n');   // vacía el stdin, si se ingresó más de un char
}