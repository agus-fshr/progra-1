#ifndef LANE_H
#define LANE_H
#include<stdint.h>
#include"../libs/position.h"

typedef enum {MOB_CAR = 1, MOB_LOG, MOB_FINISH} mobtype_t;

typedef struct {
    mobtype_t type;
    uint8_t respawn_ticks;
    uint16_t last_position;
    uint8_t speed_ticks;
    uint8_t delta;
    uint8_t mob_length;
} lane_t;

typedef lane_t * laneptr_t; 

#endif