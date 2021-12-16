#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H
#include "Level.h"
#include <allegro5/allegro5.h>

typedef struct {
    int (*init)(ALLEGRO_EVENT_QUEUE *q);
    void (*render)(levelptr_t level);
    int (*destroy)();
} engine_t;

typedef  engine_t * engineptr_t; 

#endif