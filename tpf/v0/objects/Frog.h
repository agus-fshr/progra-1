#ifndef FROG_H
#define FROG_H
#include<stdint.h>
#include"../libs/position.h"

#define STARTING_X 8
#define STARTING_Y 8

typedef struct {
    uint8_t lives;
    move_t movement;
    uint16_t x;
    uint8_t lane;
} frog_t;

typedef frog_t * frogptr_t;

uint8_t Frog_reset(frogptr_t frog);

uint8_t Frog_kill(frogptr_t frog);

#endif