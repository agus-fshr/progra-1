#include "Frog.h"


uint8_t Frog_reset(frogptr_t frog) {
    //frog->lives = 3;
    frog->lane = 15;
    frog->x = 16/2 *60;
}

uint8_t Frog_kill(frogptr_t frog) {
    if(frog->lives > 0) {
        frog->lives--;
        
        frog->lane = 15;
        frog->x = 16/2 * 60;
        return 1;
    }
    return 0;
}