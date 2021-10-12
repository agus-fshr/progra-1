#ifndef LANE_H
#define LANE_H
#include<stdint.h>
#include"../libs/position.h"

typedef enum {MOB_CAR = 1, MOB_LOG, MOB_FINISH} mobtype_t;

typedef struct {
    mobtype_t type;
    uint16_t ticks;
    uint16_t step;
    uint16_t x0;
    int8_t speed_ticks;
    uint8_t delta;
    uint8_t mob_length;
} lane_t;

typedef lane_t * laneptr_t; 

void Lane_tick(laneptr_t lane);

#endif