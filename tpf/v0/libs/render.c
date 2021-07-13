#include "render.h"
#include"position.h"
#include<stdio.h>
#include"../objects/Level.h"
#include"../objects/Frog.h"
#include"joydisp/disdrv.h"
#include"joydisp/termlib.h"


void render_level(levelptr_t level){
    int x, y;

    for(x = DISP_MIN; x < DISP_MAX_X; x++) {
        for(y = DISP_MIN; y < DISP_MAX_Y; y++) {
            gotoxy(x,y);
            putchar('X');
        }
    }

    int m;
    for(m = 0; m < level->vehicle_lane_num; m++) {
        int mobx = level->vehicle_lanes[m]->position.x;
        int moby = level->vehicle_lanes[m]->position.y;
        gotoxy(x,y);
        putchar('O');
    }

    for(m = 0; m < level->river_lane_num; m++) {
        int mobx = level->river_lanes[m]->position.x;
        int moby = level->river_lanes[m]->position.y;
        gotoxy(x,y);
        putchar('E');
    }

    int mobx = level->frog->position.x;
    int moby = level->frog->position.y;
}