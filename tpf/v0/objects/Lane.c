#include "Lane.h"
#include <stdio.h>

void Lane_tick(laneptr_t lane) {
    lane->ticks++;
    if(lane->speed_ticks > 0) {
        if(!(lane->ticks % lane->speed_ticks)) {
            lane->step++;
        }
        if(lane->step == lane->delta*6) {
            lane->step = 0;
            lane->ticks = 0;
        }
    } else if(lane->speed_ticks < 0) {
        if(!(lane->ticks % lane->speed_ticks)) {
            if(lane->step > 0) lane->step--;            
        }
        if(lane->step == 0) {
            lane->step = lane->delta*6;
            lane->ticks = 0;
        }
    }
}
