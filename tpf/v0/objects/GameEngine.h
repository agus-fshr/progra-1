#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H
#include "Level.h"
#include <allegro5/allegro5.h>

typedef struct {
    int (*init)(void*);
    void (*render)(levelptr_t level);
    int (*destroy)();
    int (*process_input)(levelptr_t level, void* q);
} engine_t;
//a
typedef  engine_t * engineptr_t; 

#endif