#ifndef LEVEL_H
#define LEVEL_H
#include<stdint.h>
//#include"Mob.h"
#include"Frog.h"
#include"Lane.h"

#define START_LVL_VEHLANES 3
#define START_LVL_RIVLANES 2
#define LEVEL_HEIGHT 16
#define LEVEL_WIDTH  16

#define LEVEL_MAX_MOBXLANE 10

#define LVL_FINISHSPOTS 5

#define LVL_FINISH_X1   2
#define LVL_FINISH_X2   5
#define LVL_FINISH_X3   8
#define LVL_FINISH_X4   11
#define LVL_FINISH_X5   14


typedef struct {
    uint8_t number;
    laneptr_t * lanes;
    frogptr_t frog;
} level_t;

typedef level_t * levelptr_t;

uint8_t Level_init(levelptr_t level);
uint8_t Level_end(levelptr_t level);
uint8_t Level_check_collisions(levelptr_t level);


#endif