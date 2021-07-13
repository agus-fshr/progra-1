#include "Level.h"
#include<stdint.h>
#include<stdlib.h>
#include "Frog.h"
#include "Mob.h"


uint8_t Level_init(levelptr_t level) {
    level->number = 0;
    level->vehicle_lane_num = START_LVL_VEHLANES;
    level->river_lane_num = START_LVL_RIVLANES;
    
    level->vehicle_lanes = calloc(START_LVL_VEHLANES, sizeof(void*));
    if(level->vehicle_lanes == NULL){
        return 0;
    }

    level->river_lanes = calloc(START_LVL_VEHLANES, sizeof(void*));
    if(level->river_lanes == NULL) {
        free(level->vehicle_lanes);
        return 0;
    }
    
    level->finish_spots = calloc(LVL_FINISHSPOTS, sizeof(void*));
    if(level->finish_spots == NULL) {
        free(level->vehicle_lanes);
        free(level->river_lanes);
        return 0;
    }

    return 1;
}

uint8_t Level_delete(levelptr_t level) {
    free(level->vehicle_lanes);
    free(level->river_lanes);
    free(level->finish_spots);
    return 1;
}
