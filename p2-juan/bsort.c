#include <stdio.h>

void bsort(void *base, size_t num, size_t size, int (*compar)(const void*, const void*));

void bsort(void *base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    // forma 2
    int i, j, k;
    for(i = num; i > 0; i--) {
        for(j = 0; j < i - 1; j++) {
            char *p1 = (char*)base + j*size;
            char *p2 = (char*)base + (j+1)*size;
            int res = compar(p1, p2);
            if(res > 0) {
                char temp;
                for(k = 0; k < size; k++) {
                    temp = *(p1 + k);
                    *(p1 + k) = *(p2 + k);
                    *(p2 + k) = temp;
                }
            }
        }
    }
    
    // forma 1
    /*
    int i, contador_de_cambios = 1;    
    while(contador_de_cambios != 0){
        contador_de_cambios = 0;
        for(i = 0; i < num; i++){

            if(compar((char*) base + i*size, (char*) base + (i+1)*size) > 0) {
                // swap pero no se el tamaño de cada dato????
                int j;
                for(j = 0; j < size; j++) {

                }
                contador_de_cambios++;
            }
        }
    }
    */
}

int mi_compa(const void *p1, const void *p2);
int mi_compa(const void *p1, const void *p2) {
    return *(int*)p1 - *(int*)p2;
}
int mi_compa2(const void *p1, const void *p2);
int mi_compa2(const void *p1, const void *p2) {
    char c1 = *(char*)p1;
    char c2 = *(char*)p2;
    
}

int main(void) {
    int arr[] = { 
                    97, 38, 91, 43, 41,
                    28, 67, 77, 17, 76,
                    39, 18, 36, 78, 87,
                    26, 64, 74, 23, 15
                };
    int i;
    for(i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    bsort(arr, 20, sizeof(int), mi_compa);
    for(i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*
void bsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*)){ 
    char* pEscritura = (char*) base; 
    int i, j, k; 
    int accion; //variable que guardara la devolucion de la funcion compar 
    char temp; 
    for (i=0; i<=num; i++){
        for (j=0; j < (num-1) ; j++){ 
            accion = compar( pEscritura[j*size], pEscritura[ (j+1) * size ] ); 
            if (accion > 0){ // solo para este caso se debera intercambiar la posicion de los elementos 
                for (k = 0; k < size; k++){ // realizo el intercambio copiando byte a byte 
                    temp = pEscritura[j*size + k]; 
                    pEscritura[j*size + k] = pEscritura [ (j+1) * size +k ]; 
                    pEscritura [ (j+1) * size +k ] = temp; 
                } 
            } 
        } 
    } 
}
*/