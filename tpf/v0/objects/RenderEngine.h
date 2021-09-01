#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H
#include "Level.h"

typedef struct {
    int (*init)();
    int (*render)(levelptr_t level);
    int (*destroy)();
} RenderEngine;

#endif