#include "Lane.h"
#include <stdio.h>

void Lane_tick(laneptr_t lane) {
    lane->ticks++;
    if(!(lane->ticks % lane->speed_ticks)) {
        lane->step++;
    }
    if(lane->ticks == lane->speed_ticks*lane->delta*6) {
        lane->step = 0;
        lane->ticks = 0;
    }
}
