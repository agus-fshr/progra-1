#ifndef MOB_H
#define MOB_H
#include<stdint.h>
#include"../libs/position.h"

typedef struct {
    uint8_t type;
    uint8_t tickspeed;
    move_t movement;
    coord_t position;
} mob_t;

typedef mob_t * mobptr_t; 

#endif