#ifndef FROG_H
#define FROG_H
#include<stdint.h>
#include"../libs/position.h"

typedef struct {
    uint8_t lives;
    move_t movement;
    coord_t position;
} frog_t;

typedef frog_t * frogptr_t;

uint8_t Frog_init(frogptr_t frog);
uint8_t Frog_kill(frogptr_t frog);

#endif