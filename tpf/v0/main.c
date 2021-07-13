//#include"libs/joydisp/termlib.h"
#include<stdio.h>
#include"objects/Level.h"
#include"libs/render.h"

int main(void) {
    levelptr_t level;
    Level_init(level);
    level->vehicle_lanes[2]->position.x = 2;
    level->vehicle_lanes[2]->position.y = 3;

    level->frog->position.x = 4;
    level->frog->position.y = 4;

    while(1) {
        render_level(level);
    }
    return 0;
}