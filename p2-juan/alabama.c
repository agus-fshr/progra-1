#include <stdio.h>

/*
    Escribir la función bsort que cumple la misma función que qsort pero usando burbujeo como algoritmo.
    void qsort(void¨base, size_t num, size_t size, int (*compar)(const void*, const void*))
*/


/*
    Progra para arboles gene
    - Nombre y apellido (string)
    - Fecha  de nacimiento [dd, mm, aaaa]
    - Madres padres (arreglo de punteros a personas)
    - Hermanos (arr de punt a per)
    - Hijos (a p p)
    Alias: persona_t
*/

#define NMAX 2

typedef struct personaT {           // más fachero meter todo junto
    char nombre[20];        // char * nombre; GUARDA MAN NO ESTÁS GUARDANDO TODO JUNTO
    int fecha_de_nacimiento[3];
    struct personaT * padres[NMAX];
    struct personaT * hermanos[NMAX];
    struct personaT * hijos[NMAX];
} persona_t;

// Escribir la función geniCantSobris, 
// recibe info de una persona (puntero a persona_t) 
// y devuelve cant de sobris
int get_sobris_num(persona_t * persona);
int get_hijitus_num(persona_t * persona);

int get_sobris_num(persona_t * persona) {
    // persona -> hermanos -> num de hijos
    
    persona_t **p_hermano = persona->hermanos;
    int acum_hermanos = 0;
    int acum_sobrinos = 0;
    while((*p_hermano != NULL) && (acum_hermanos < NMAX)) {
        acum_hermanos++;
        acum_sobrinos += get_hijitus_num(*p_hermano);
        p_hermano++;
    }
    return acum_sobrinos;
}

int get_hijitus_num(persona_t * persona) {
    persona_t **p_hijo = persona->hijos;
    int acum = 0;
    while((*p_hijo++ != NULL) && (acum < NMAX)) {
        acum++;
    }
    return acum;
}

int main(void) {
    //syke
    return 0;
}