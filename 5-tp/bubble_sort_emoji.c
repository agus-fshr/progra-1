#include <stdio.h>
#include <sys/cdefs.h>

#define 🥰 10
#define 🤡 while
#define 🥱 for
#define 💞 swap2
#define 📊 contador_de_cambios
#define 🤺 orden
#define 📝 printf(

void 💞(int*, int*);

int main (void){
    int *p;

    int 🤺 [🥰] = {6, 9, 2, 2, 5, 1, 4, 0, 8, 7};

    int 📊 = 1;

    🤡 (📊 != 0){
        📊 = 0;
        p = &🤺[0];
        🥱 (int i = 0; i < 🥰-1; i++) {

            if (*p > *(p+1)) {
                💞(p, p+1);
                📊++;
            }

            p++;
        
        }
    }

    🥱 (int x = 0; x < 🥰; x++)
        📝"%d  ", 🤺[x]);
    📝"\n");
    return 0;
}



void 💞(int *pa, int *pb) 
{ 
    int t; 
    t = *pa; 
    *pa = *pb; 
    *pb = t;
}