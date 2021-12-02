#include "Level.h"
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
//#include "Mob.h"


uint8_t Level_init(levelptr_t level) {
    uint8_t i = 0, p = 0;

    level->number = 0;
    level->lanes = calloc(LEVEL_HEIGHT, sizeof(laneptr_t));
    if(level->lanes == NULL){
        return 0;
    }
    level->frog = malloc(sizeof(frog_t));
    if(level->frog == NULL) {
        free(level->lanes);
        return 0;
    }

    for(i = 0; i < LEVEL_HEIGHT; i++) {
        level->lanes[i] = malloc(sizeof(lane_t));

        if(level->lanes[i] == NULL){
            while(i >= 0){
                free(level->lanes[i--]);
            }
            free(level->lanes);
            free(level->frog);
            return 0;
        }
        
        level->lanes[i]->speed_ticks = 100;
        level->lanes[i]->delta = 100;
        level->lanes[i]->step = 100;
        level->lanes[i]->x0 = 100;
        level->lanes[i]->mob_length = 1;

    }
    /*
    for(i = 0; i < LVL_FINISHSPOTS; i++) {
        level->mob_lanes[LEVEL_HEIGHT - 1][i]->movement = STOP;
        level->mob_lanes[LEVEL_HEIGHT - 1][i]->tickspeed = 0;
        level->mob_lanes[LEVEL_HEIGHT - 1][i]->type = MOB_FINISH;
    }

    level->mob_lanes[LEVEL_HEIGHT - 1][0]->x = LVL_FINISH_X1;
    level->mob_lanes[LEVEL_HEIGHT - 1][1]->x = LVL_FINISH_X2;
    level->mob_lanes[LEVEL_HEIGHT - 1][2]->x = LVL_FINISH_X3;
    level->mob_lanes[LEVEL_HEIGHT - 1][3]->x = LVL_FINISH_X4;
    level->mob_lanes[LEVEL_HEIGHT - 1][4]->x = LVL_FINISH_X5;
    */
    /*
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
        free(level->mob_lanes);
        return 0;
    }
    */

    return 1;
}

uint8_t Level_delete(levelptr_t level) {
    uint8_t i = 0, p = 0;
    
    for(i = 0; i < LEVEL_HEIGHT; i++) {        
        free(level->lanes[i]);
    }
    free(level->lanes);

    //free(level->finish_spots);
    return 1;
}

uint8_t Level_check_collisions(levelptr_t level) {
    int16_t frog_x = level->frog->position.x * 60;
    int16_t frog_y = level->frog->position.y;
    int8_t i = 0, p = 0; // iterator
    laneptr_t lane = level->lanes[frog_y];
    if(lane->delta != 0) {   
        for(p = -1; p < LEVEL_WIDTH / lane->delta + 1; p++) {    
            int16_t A = lane->x0 + p*lane->delta*60;
            //printf("%d %d %d %d\n\r",frog_x, A, B, cond);
            if(((frog_x+60) > A) && (frog_x < (A + 60*lane->mob_length))) {
                return lane->type;
            }
        }
    }
    return 0;
}