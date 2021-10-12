#include "Frog.h"


uint8_t Frog_reset(frogptr_t frog) {
    frog->lives = 3;
    frog->position.x = STARTING_X;
    frog->position.y = STARTING_Y;
}

uint8_t Frog_kill(frogptr_t frog) {
    if(frog->lives > 0) {
        frog->lives--;
        return 1;
    }
    return 0;
}