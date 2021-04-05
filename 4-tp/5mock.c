/*
    TP4 - Ejercicio 5 - Grupo 7 (FISHER, MARTINEZ TANOIRA, SBRUZZI, OMS)
    Consigna:
        Implementar el Juego de la Vida, de James Conway. Reglas:
            a) Una célula viva con menos de dos vecinos muere;
            b) una célula con más de tres vecinos también muere;
            c) una célula viva con exactamente dos o tres vecinos sobrevive;
            d) una célula muerta con exactamente tres vecinos obtiene vida nuevamente.        
    Requisitos:
            a) El tamaño del mundo debe encontrarse en dos constantes, por ejemplo, ANCHO
                y ALTO. Debe poder cambiarse el valor de las mismas y recompilar el código, y
                el mismo debe funcionar.
            b) El programa debe mostrar el estado actual del mundo en pantalla, y luego
                preguntar al usuario cuantas generaciones desea avanzar. Cuando el usuario
                ingresa un número y presiona enter, se calcula el nuevo estado del mundo, se
                presenta en pantalla, y se vuelve a preguntar.
            c) Si el usuario presiona enter sin ingresar ningún número, se debe avanzar una
                generación.
            d) Si el usuario ingresa el carácter ‘q’, se debe salir del programa.
            e) Cualquier funcionalidad extra que deseen agregar se tomará en cuenta en la
                nota del trabajo práctico.

    Descripción de la implementación:
        1) El estado de cada celda no es un número, sino un define. Esto se tiene en cuenta en todo el código.
        2) Hay 3 formas de ingresar un mapa:
            - Manualmente, con las instrucciones correspondientes
            - A través de un .txt que tenga un mapa formateado correctamente
            - A través de la generación pseudoaleatoria
        3) Se sanitizan el input del usuario en la medida de lo posible: se cuida que no queden caracteres
            pendientes en stdin cuando ello podría arruinar el funcionamiento correcto del programa.
        4) Bajo la categoría "parametrización" se encuentran los defines que establecen detalles del
            funcionamiento del programa. Esto permite personalizar tanto el funcionamiento del juego
            como la presentación del mismo
        5) Organización: 

*/


#include <stdio.h>
#include <stdlib.h>



/* Parametrización funcional */
#define WORLD_WIDTH 25      // Ancho del mundo. Número de columnas.
#define WORLD_HEIGHT 15     // Altura del mundo. Número de filas.
#define OUTSIDE_STATE DEAD  // Estado de las celdas del borde externo

/* Parametrización estética */
#define ALIVE_CHAR '*'      // Caracter que representa una celda viva
#define DEAD_CHAR ' '       // Caracter que representa una celda muerta
#define SEPARATOR '|'       // Separador de columnas

/* Funcionamiento interno */
#define ALIVE 1
#define DEAD 0



/** Helper functions **/
int get_cell_state(int, int);   // toma el estado de una celda
int get_world_height(void);     // devuelve la altura del mapa
int get_world_width(void);      // devuelve el ancho del mapa
void clear_screen(void);        // limpia la pantalla
void flush_stdin(char);         // limpia stdin

/** Game-specific functions **/
int read_generations(void);     // lee num de generaciones a avanzar
void advance_generation(void);  // avanza una generación
unsigned int count_adjacent_cells(int, int); // cuenta celdas colindantes vivas
void copy_world(int[][WORLD_WIDTH], int[][WORLD_WIDTH]);
void print_world(void);         // imprime mundo

/** Setup functions **/
void world_from_stdin(int[][WORLD_WIDTH]);  // toma mundo desde stdin
void seed_world(int[][WORLD_WIDTH]);        // genera mundo
void initialize_world(void);                // inicializa juego



/******************************************
 *                MAIN                    *
 *****************************************/

int world[WORLD_HEIGHT][WORLD_WIDTH]; //  variable global que almacena el estado actual del mundo

int main(void){
    int total_generations = 0;
    
    initialize_world();   // decide qué mapa se usará como estado inicial
    
    /*
    int exit_loop_flag = 0;

    clear_screen();
    printf("\n\nGeneracion: %d\n\n", total_generations);
    print_world();

    while(!exit_loop_flag) {
        int i;

        printf("Ingrese: \n");
        printf(" - Enter: para avanzar una generacion\n");
        printf(" - Un numero natural para avanzar esa cantidad de generaciones\n");
        printf(" - 'q' para salir\n");

        int next_generations = read_generations();      // lee un numero o salida
        
        if(next_generations == -1) {      
            exit_loop_flag = 1;
        }

        
        for(i = 0; i < next_generations; i++) {
            advance_generation();       // calcular una generación y pasarla al estado
            clear_screen();             // limpiar pantalla
            printf("\n\nGeneracion: %d\n\n", ++total_generations);

            if(i != (next_generations - 1)){    // si no se está en la última gen a avanzar
                printf("Falta avanzar %d\n\n", next_generations-1-i);
                print_world();
                printf("Presione enter para avanzar una gen\n");
                getchar(); // para que muestre la generación intermedia
            }
            else {
                print_world();
            }
        }
    
    }
    */
    

    int steps = 0;              // variable local: pasos a avanzar o si debe salir
    while(steps != -1) {        // si steps vale -1, debe abandonarse el juego

        clear_screen();
        printf("\n\n\tGeneracion: %d\n\n", total_generations);
        print_world();
        printf("\tIngrese: \n");
        printf("\t - Enter: para avanzar una generacion\n");
        printf("\t - Un numero natural para avanzar esa cantidad de generaciones\n");
        printf("\t - 'q' para salir\n");

        steps = read_generations();     // lee generaciones a avanzar o salida
        total_generations += steps;
        
        int i;
        for(i = 0; i < steps; i++) {
            advance_generation();       // pasa a la siguiente generación
        }
    
    }

    printf("Nos vemos.\n");     // saluda amablemente

    return 0;
}


/****************************
 *     Helper functions     *
*****************************/

/*
 * Función get_cell_state
 * Argumentos (cuidado!):
 *      - x: la FILA de la celda
 *      - y: la COLUMNA de la celda
 * 
 * Descipción:
 * Devuelve el estado de una celda
*/
int get_cell_state(int x, int y) {
    return world[x][y];
}

/*
 * Función get_world_height
 * 
 * Descipción:
 * Devuelve la altura del mapa
*/
int get_world_height(void) {
    return WORLD_HEIGHT;
}

/*
 * Función get_world_width
 * 
 * Descipción:
 * Devuelve el ancho del mapa
*/
int get_world_width(void) {
    return WORLD_WIDTH;
}

/*
 * Función clear_screen
 * 
 * Descripción:
 * Limpia stdout
 * 
 * Peligro! Esta implementación es linux-specific
 * Para que el programa funcione en windows, debe
 * reemplazarse por system("CLS"), y haciendo include
 * a Windows.h
 * 
 * Nota: hay otras formas de resolver esto con caracteres especiales 
 * de printf:
 * printf("\e[1;1H\e[2J");
*/
void clear_screen(void) {
    system("clear");        // Pasa el comando clear a la consola (LINUX)
    //system("CLS");        // Pasa el comando CLS a la consola (Windows.h)
}

/*
 * Función flush_stdin
 * Argumentos:
 *      - limit: finaliza
 * 
 * Descripción:
 * Toma caracteres de stdin hasta llegar
 * al caracter especificado
*/
void flush_stdin(char limit) {
    char c;
    // Hasta que se llegue al caracter especificado, vacía stdin
    while((c=getchar()) != limit) {}
}

/*
 * Función read_generations
 * 
 * Descipción:
 * Lee un número entero sin signo de stdin
 * La presencia de cualquier caracter numérico, 
 * excepto q y \n (si están en la primera posición), 
 * provocan que devuelva un 0.
 * Sin embargo, si se incluye una q en algún lugar de la entrada, 
 * la salida será -1, marcando error.
*/
int read_generations(void) {
    char c = getchar();
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


/****************************
 * Game-specific functions  *
*****************************/

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
 * En el resto de los casos, morirá (o seguirá muerta).
*/
void advance_generation(void) {
    int i_col, i_fil;
    int next_world[WORLD_HEIGHT][WORLD_WIDTH];
    // En next_world se almacena el estado futuro temporalmente
    for(i_col = 0; i_col < get_world_width(); i_col++) {
        for(i_fil = 0; i_fil < get_world_height(); i_fil++) {
            int adjacent_living = count_adjacent_cells(i_fil, i_col);
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
 * Función count_adjacent_cells
 * Argumentos (Cuidado!):
 *      - x: FILA de la celda a analizar
 *      - y: COLUMNA de la celda a analizar
 * Salida:
 *      - El número de celdas colindantes vivas.
 *
 * Descripción:
 * Calcula el número de celdas colindantes con la
 * deseada que se encuentran vivas.
 * 
*/
unsigned int count_adjacent_cells(int x, int y) {
    int alive_neighbours = 0;   // acumulador de vecinos vivos
    int row, col;               // iteradores para filas y columnas, respectivamente
    int out_of_map_rows;        // condición de overflow de borde en fila
    int out_of_map_cols;        // condición de overflow de borde en columna
    
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
                    OUTSIDE_STATE : get_cell_state(row, col) == ALIVE;
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
    alive_neighbours -= get_cell_state(x, y) == ALIVE; 
    return alive_neighbours;
}

/*
 * Función copy_world
 * Argumentos:
 *      - src: matriz de origen
 *      - tgt: matriz de destino
 * 
 * Descripción:
 * Copia una matriz (del tamaño especificado por la parametrización)
 * pasada como parámetro, a la variable indicada.
*/
void copy_world(int src[][WORLD_WIDTH], int tgt[][WORLD_WIDTH]) {
    for(int i = 0; i < get_world_height(); i++) {
        for(int j = 0; j < get_world_width(); j++) {
            tgt[i][j] = src[i][j];
        }
    }
}

/*
 * Función print_world
 * 
 * Descripción:
 * Imprime a stdout el estado actual del mundo,
 * con formato embellecido.
*/
void print_world(void) {
    int row, col;       // contadores de filas y columnas, respectivamente
    putchar('\n');
    for (row=0; row < get_world_height(); row++){   // itera sobre las filas
        printf("\t%c", SEPARATOR);
        for(col=0; col < get_world_width(); col++){ // itera sobre las columnas
            if(get_cell_state(row, col) == ALIVE) {
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


/****************************
 *      Setup functions     *
*****************************/

/*
 * Función world_from_stdin
 * Argumentos:
 *      - world_to_save: matriz en la que almacenar el mundo
 * 
 * Descripción:
 * Lee un mapa del tamaño especificado por la parametrización
 * del programa. Se puede ingresar a mano o pipeando un .txt
 * Es un REQUISITO que al terminar, se ingrese una f.
 * No es necesario un separador en especial entre valores.
 * Si se pasa de columnas, lo incluirá en la siguiente de la matriz.
 * (efecto colateral del funcionamiento interno de matrices)
*/
void world_from_stdin(int world_to_save[][WORLD_WIDTH]) {
    char c;
    int row_counter = 0, col_counter = 0;
    int cell_counter = 0;           // contador de celdas detectadas
    // total_cells: número total de celdas posibles en el tamaño de mapa actual
    int total_cells = get_world_width() * get_world_height();
    int valid_position = 1;         // para no irse de la matriz
    
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

/*
 * Función seed_world
 * Argumentos:
 *      - world_to_seed: matriz en la que almacenar el mundo
 * 
 * Descripción:
 * Genera un mapa pseudoaleatorio.
*/
void seed_world(int world_to_seed[][WORLD_WIDTH]){
    for(int i = 0; i < get_world_height(); i++) {
        for(int j = 0; j < get_world_width(); j++) {
            // rand() genera un entero aleatorio
            // al pedir el resto de la división por 2,
            // se obtendrá 1 o 0 de manera pseudoaleatoria
            world_to_seed[i][j] = (rand() % 2) == 0 ? ALIVE : DEAD;        
        }
    }
}

/*
 * Función initialize_world
 * 
 * Descripción:
 * Maneja la inicialización del mundo de juego.
 * Permite al usuario elegir entre distintos métodos de entrada
 * para personalizar el mundo en el que jugará.
 * Incluye instrucciones sobre cómo se realiza la carga manual de un mapa.
 * Apto para mayores de 12 años.
*/
void initialize_world(void){
    char c;
    int stdin_world[WORLD_HEIGHT][WORLD_WIDTH];
    
    printf("Si esta leyendo esto, no cargo un archivo valido para jugar.\n");
    printf("Si su intención era hacerlo, recuerde que debe ingresar el comando cat [archivo] - | ./5\n");
    printf("Quizas decidio ingresar manualmente el mundo de juego, en cuyo caso, felicidades!\n");
    printf("Debo avisarle, primero que nada, que haga lo posible por ingresar un mapa de ");
    printf("%d filas y %d columnas. Si se equivoca, no se preocupe, nada se va a incendiar.\n", get_world_height(), get_world_width());
    printf("Tenga en cuenta:\n");
    printf("\t- Un caracter '%c' representa una celda muerta\n", DEAD_CHAR);
    printf("\t- Un caracter '%c' representa una celda viva\n", ALIVE_CHAR);
    printf(" utilizar el caracter que mas le guste para separar celdas, incluso puede no usar ninguno!\n");
    printf("Eso si, al terminar cada fila presione enter.\n"); // No es necesario, pero es más seguro
    printf("Si se encuentra contento con el resultado, ingrese una f al final de la ultima fila\n");
    printf("Si no, cierre el programa e intente otra vez. La siguiente sera la vencida.\n");
    printf("Si no quiere cargar un mapa y quiere pasar al juego,\ningrese una 'f' y luego pida cargar el mundo por defecto.\n");
    
    world_from_stdin(stdin_world);  // carga en var local el mapa desde stdio
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