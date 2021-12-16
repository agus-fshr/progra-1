#include "Level.h"
#include<stdio.h>

#ifdef LEDMAT
    #include "LEDMatrixEngine.h"
#else
    #include "AllegroEngine.h"
#endif

static int8_t gen_sign();
static void generate_car_lane(laneptr_t lane, uint8_t diff);
static void generate_log_lane(laneptr_t lane, uint8_t diff);
static void generate_floor_lane(laneptr_t lane);

uint8_t Level_init(levelptr_t level) {
    uint8_t i = 0, p = 0;
    
    level->finisher_count = 0;
    for(i = 0; i < LVL_FINISHSPOTS; i++) {
        level->finishers[i] = -100;
    }

    level->number = 0;
    level->paused = 0;
    level->score = 0;
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
        
        level->lanes[i]->delta = 100;
        level->lanes[i]->step = 100;
        level->lanes[i]->x0 = 100;
        level->lanes[i]->mob_length = 1;

    }

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

uint8_t Level_check_collisions(levelptr_t level, uint8_t* finish) {
    float frog_x = ((float) level->frog->x) / BLOCK_WIDTH;
    uint8_t frog_y = level->frog->lane;
    int8_t i = 0, p = 0; // iterator
    laneptr_t lane = level->lanes[frog_y];
    uint8_t collided = 0;
    if(lane->delta != 0) {   
        for(p = -1; p < LEVEL_WIDTH / lane->delta + 2; p++) {    
            float start = ((float) lane->x0)/BLOCK_WIDTH + p*lane->delta;
            printf("%d %f %f\n", frog_y, frog_x, start);
            if(((frog_x+1) > start) && (frog_x < (start + lane->mob_length))) {
                *finish = p;
                return 1;
            }
        }
    }
    return 0;
}

// a a
int8_t gen_sign() {
    return 1 - 2 * (rand() % 2);
}

void generate_car_lane(laneptr_t lane, uint8_t diff) {
    lane->ticks = rand() % 500;
    lane->type = MOB_CAR;
    lane->step = gen_sign() * ((20-diff) + rand() % (36 - diff));
    if(lane->step == 0) {
        lane->step = gen_sign();
    }
    lane->mob_length = 1 + rand() % 3;
    lane->delta = lane->mob_length + 2 + (rand() % (20 - diff));
    lane->step = 2 + rand() % (5 + diff);
    lane->x0 = 10*(rand() % 6);
}
void generate_log_lane(laneptr_t lane, uint8_t diff) {    
    lane->ticks = rand() % 500;
    lane->type = MOB_LOG;
    lane->step = gen_sign() * (1 + rand() % (8+diff));

    lane->mob_length = 2 + (rand() % (4 - diff/2));
    lane->delta = lane->mob_length + 2 + (rand() % (4 + (3-diff)/2));
    lane->x0 = rand() % BLOCK_WIDTH;
}
void generate_floor_lane(laneptr_t lane) {
    lane->ticks = 0;
    lane->type = MOB_FLOOR;
    lane->step = 0;
    lane->mob_length = 0;
    lane->delta = 1;
    lane->x0 = 0;
}
void Level_gen(levelptr_t level) {
    uint8_t i = 0;
    for(i = 0; i < LEVEL_HEIGHT; i++) {
        if(i == 0) {
            
            level->lanes[0]->type = MOB_FINISH;
        } else if(i == 8 || i == 15) {
            generate_floor_lane(level->lanes[i]);
        }else if(i < 8){
            generate_log_lane(level->lanes[i], level->number);
        } else {
            generate_car_lane(level->lanes[i], level->number);
        }
    }
}