/** *************************************************************************//**
  @file     conway.c
  @brief    Implements Conway's game of life
  @author   Grupo 7
 ******************************************************************************/


/******************************************
 *          INCLUDE HEADER FILES          *
 *****************************************/
#include "conway.h"
#include "helper_functions.h"
#include <stdio.h>


/*******************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE *
 *******************************************************************/


/**
 * @brief Reads a cell state
 * 
 * @param x Row coordinate
 * @param y Column coordinate
 * @param world Matrix where the cell lookup happens.
 * 
 * @return The cell value
 */
static int get_cell_state(int, int, int[][WORLD_WIDTH]);   // toma el estado de una celda


/**
 * @brief Returns the world height
 * 
 * @return World height
*/
static int get_world_height(void);     // devuelve la altura del mapa


/**
 * @brief Returns the world width
 * 
 * @return World width
*/
static int get_world_width(void);      // devuelve el ancho del mapa


/**
 * @brief Analyzes the number of 
 * living neighboring cells to the specified cell.
 * 
 * @param x Row of the target cell
 * @param y Column of the target cell
 * @param world World analyzed
 * 
 * @return  The number of alive neighboring cells to the specified cell.
*/
static unsigned int count_adjacent_cells(int x, int y, int world[][WORLD_WIDTH]);


/**
 * @brief Copies a matrix recieved as a parameter to the target matrix
 * 
 * @param src origin matrix
 * @param tgt target matrix 
*/
static void copy_world(int src[][WORLD_WIDTH], int tgt[][WORLD_WIDTH]);


/**
 * @brief Reads a map of size specified previously. 
 * It can be entered either by hand or by piping a .txt file. Input must end with the character
 * 'f'. It is not necessary to have a separator between values. If the length of a column
 * is exceeded, it will be included in the next one.
 * 
 * @param world_to_save A matrix to store the world map in.
*/
static void parse_world_from_stdin(int world_to_save[][WORLD_WIDTH]);


/**
 * @brief Generates pseudorandom world.
 * 
 * @param world_to_seed Where the generated world is saved
 */
static void seed_world(int world_to_seed[][WORLD_WIDTH]);        // genera mundo




/******************************************
 *      GLOBAL FUNCTION DEFINITIONS       *
 *****************************************/

void initialize_world(int world[][WORLD_WIDTH]){
    char c;
    // Temporary world used if map was input using piping
    int stdin_world[WORLD_HEIGHT][WORLD_WIDTH];
    
    clear_screen();

    printf("Si esta leyendo esto, no cargo un archivo valido para jugar.\n");
    printf("Si su intencion era hacerlo, recuerde que debe ingresar el comando cat [archivo] - | ./[ejecutable]\n");
    printf("Quizas decidio ingresar manualmente el mundo de juego, en cuyo caso, felicidades!\n");
    printf("Debo avisarle, primero que nada, que haga lo posible por ingresar un mapa de ");
    printf("%d filas y %d columnas. Si se equivoca, no se preocupe, nada se va a incendiar.\n", get_world_height(), get_world_width());
    printf("Tenga en cuenta:\n");
    printf("\t- Un caracter '%c' representa una celda muerta\n", DEAD_CHAR);
    printf("\t- Un caracter '%c' representa una celda viva\n", ALIVE_CHAR);
    printf("Puede utilizar el caracter que mas le guste para separar celdas, incluso puede no usar ninguno!\n");
    printf("Eso si, al terminar cada fila presione enter.\n"); // No es necesario, pero es más seguro
    printf("Si se encuentra contento con el resultado, ingrese una f al final de la ultima fila\n");
    printf("Si no, cierre el programa e intente otra vez. La siguiente sera la vencida.\n");
    printf("Si no quiere cargar un mapa y quiere pasar al juego,\ningrese una 'f' y luego pida cargar el mundo por defecto.\n");
    
    parse_world_from_stdin(stdin_world);  // carga en var local el mapa desde stdio
    clear_screen();
    
    printf("Ingrese una 'i' para iniciar el juego\n");
    flush_stdin('i');       // vaciar stdin hasta llegar a una 'i'
    flush_stdin('\n');      // si se ingresa algo además de la i, vaciará hasta el enter
    //Nota: de por si, debería haber un solo \n luego de la i. Si se presionan 2 teclas sin querer, por ejemplo
    //  se debe vaciar stdin del todo también, para evitar problemas en las siguientes porciones del programa.
    
    clear_screen();

    printf("Bienvenido al Juego de la Vida, de James Conway.\n\n");
    printf("Presione 's' para inciar el mapa cargado manualmente o desde archivo.\n");
    printf("Cualquier otra tecla, como 'n' le generara un mapa automaticamente.\n");
    
    c = getchar();          // toma la tecla de accion del usuario
    
    if(c == 's') {          // si la misma es 's', se debe copiar el mundo de stdin
        copy_world(stdin_world, world);
    }
    else {                  // si no es 's', debe copiarse el mundo generado
        seed_world(world);  // genera el mundo sobre la variable global
    }
    flush_stdin('\n');      // vacía el stdin, si se ingresó más de un char como acción
}



void advance_generation(int world_to_advance[][WORLD_WIDTH]) {
    // Iterators
    int i_col, i_fil;
    
    // Temporary world state
    int next_world[WORLD_HEIGHT][WORLD_WIDTH];

    for(i_col = 0; i_col < get_world_width(); i_col++) {
        for(i_fil = 0; i_fil < get_world_height(); i_fil++) {
            int adjacent_living = count_adjacent_cells(i_fil, i_col, world_to_advance);
            // adjacent_living almacena el número de las celdas
            // vivas que se encuentran próximas a la celda
            int cell_state = get_cell_state(i_fil, i_col, world_to_advance); // estado actual
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
    
    copy_world(next_world, world_to_advance); // copia el mundo calculado al estado actual
}


int read_generations(void) {
    // Where each read char is saved
    char c = getchar();
    
    // Temporary output
    int salida = 0;

    if(c == 'q') {          
        flush_stdin('\n');
        return -1;      // Si se ingresa una 'q' primero, devuelve señal de salida
    }
    else if (c == '\n') {
        return 1;       // Si se ingresa un '\n' primero, avanzar una generación
    }
    else if( c < '0' || c > '9') {  
        flush_stdin('\n');
        return 0;       // Si se ingresa otra cosa, ignora y no avanza
    }
    // El siguiente while tomará caracteres numéricos válidos
    // y conformará un número entero positivo
    while ((c != '\n') && (c >= '0' && c <= '9')){
        salida *= 10;       // Desplaza el orden del número almacenado (*10 por ser sistema decimal)
        salida += c - '0';  // Quita el offset de los números en ASCII
        c = getchar();      // toma el siguiente caracter
    }   

    if(c != '\n'){          // Si el caracter leído no era el fin, sino algo raro
        flush_stdin('\n');  // vacía stdin
        return 0;           // y no avanza ninguna generación
    }
    
    return salida;
}


void print_world(int world[][WORLD_WIDTH]) {
    // Iterators
    int row, col;
    putchar('\n');
    for (row=0; row < get_world_height(); row++){   // itera sobre las filas
        printf("\t%c", SEPARATOR);
        for(col=0; col < get_world_width(); col++){ // itera sobre las columnas
            if(get_cell_state(row, col, world) == ALIVE) {
                putchar(ALIVE_CHAR);
            } else {
                putchar(DEAD_CHAR);
            }
            putchar(SEPARATOR);   // imprime separador de columnas
        }
        printf("\n");
    }
    printf("\n");
}




/******************************************
 *       LOCAL FUNCTION DEFINITIONS       *
 *****************************************/

static int get_cell_state(int x, int y, int world[][WORLD_WIDTH]) {
    return world[x][y];
}

static int get_world_height(void) {
    return WORLD_HEIGHT;
}

static int get_world_width(void) {
    return WORLD_WIDTH;
}


static unsigned int count_adjacent_cells(int x, int y, int world[][WORLD_WIDTH]) {
    // Alive neighbours acummulator
    int alive_neighbours = 0;
    
    // Iterators
    int row, col;

    // Row overflow condition
    int out_of_map_rows;

    // Column overflow condition
    int out_of_map_cols;
    
    for(row = x-1; row <= x+1; row++){    // itera por 3 filas centradas en x
        // calcula condición: si se quiere analizar la fila -1 o
        // la fila que coincida con la altura del mapa, no debe
        // intentar acceder a la matriz
        out_of_map_rows = (row == -1) || (row == get_world_height());
        if(!out_of_map_rows){
            for(col = y-1; col <= y+1; col++){ // itera por 3 filas centradas en y
                // calcula condición: si se quiere analizar la columna -1 o
                // la fila que coincida con el ancho del mapa, no debe
                // intentar acceder a la matriz
                out_of_map_cols = (col == -1) || (col == get_world_width());
                // Si la columna está fuera del mapa, cuenta un OUTSIDE_STATE (configurable)
                // mientras que si no, recupera el estado de esa celda
                alive_neighbours += out_of_map_cols ? 
                    OUTSIDE_STATE : get_cell_state(row, col, world) == ALIVE;
            }
        }
        else {
            // Es configurable el comportamiento de las celdas
            // del borde externo del mapa, por lo que si se
            // quiere analizar una fila que está fuera del mapa
            // se deben contar 3 celdas en ese estado.
            alive_neighbours += 3*OUTSIDE_STATE;        // Not magic
        }
    }
    // Si está viva, se debe restar el valor sumado por contar
    // la celda del medio (solo se quiere el número de vecinos)
    alive_neighbours -= get_cell_state(x, y, world) == ALIVE; 
    return alive_neighbours;
}


static void copy_world(int src[][WORLD_WIDTH], int tgt[][WORLD_WIDTH]) {
    for(int i = 0; i < get_world_height(); i++) {
        for(int j = 0; j < get_world_width(); j++) {
            tgt[i][j] = src[i][j];
        }
    }
}


static void parse_world_from_stdin(int world_to_save[][WORLD_WIDTH]) {
    // Where each read char is saved
    char c;

    // Iterators
    int row_counter = 0, col_counter = 0;

    // Detected cell counter
    int cell_counter = 0;

    // Maximum possible cells
    int total_cells = get_world_width() * get_world_height();

    // Valid position flag (prevents matrix overflow)
    int valid_position = 1;
    
    //Cuidado: es necesaria la condición cell_counter < total_cells
    // esto se debe a que si no se limita, estaríamos permitiendo
    // sobreescribir lugares que no le pertenecen a la variable world_to_save
    while(((c = getchar()) != 'f') && cell_counter < total_cells && valid_position) {
        
        switch (c){
            case(DEAD_CHAR):{   // Si se lee el caracter que indica celda muerta, lo almacena
                world_to_save[row_counter][col_counter++] = DEAD;
                cell_counter++;
                break;
            }
            case(ALIVE_CHAR):{  // Si se lee el caracter que indica celda viva, lo almacena
                world_to_save[row_counter][col_counter++] = ALIVE;
                cell_counter++;
                break;
            }
            case('\n'):{        // Si se lee el caracter de enter, pasa a la siguiente fila
                ++row_counter;
                col_counter = 0;
                break;
            }
            default:{
                break;
            }
        }
        // Una posición válida debe no sobrepasar los límites de la matriz
        valid_position = row_counter < get_world_height() && col_counter < get_world_width();
    }
}


static void seed_world(int world_to_seed[][WORLD_WIDTH]){
    for(int i = 0; i < get_world_height(); i++) {
        for(int j = 0; j < get_world_width(); j++) {
            // rand() genera un entero aleatorio
            // al pedir el resto de la división por 2,
            // se obtendrá 1 o 0 de manera pseudoaleatoria
            world_to_seed[i][j] = (rand() % 2) == 0 ? ALIVE : DEAD;        
        }
    }
}