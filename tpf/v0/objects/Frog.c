#include "Frog.h"


uint8_t Frog_init(frogptr_t frog) {
    frog->lives = 3;
}

uint8_t Frog_kill(frogptr_t frog) {
    if(frog->lives > 0) {
        frog->lives--;
        return 1;
    }
    return 0;
}