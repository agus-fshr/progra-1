#ifndef LEVEL_H
#define LEVEL_H
#include<stdint.h>
#include"Mob.h"
#include"Frog.h"

#define START_LVL_VEHLANES 3
#define START_LVL_RIVLANES 2
#define LVL_FINISHSPOTS 5

typedef struct {
    uint8_t number;
    uint8_t vehicle_lane_num;
    uint8_t river_lane_num;
    mobptr_t * vehicle_lanes;
    mobptr_t * river_lanes;
    void * finish_spots;
    frogptr_t frog;
} level_t;

typedef level_t * levelptr_t;

uint8_t Level_init(levelptr_t level);
uint8_t Level_end(levelptr_t level);


#endif