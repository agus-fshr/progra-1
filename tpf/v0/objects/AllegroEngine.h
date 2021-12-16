#ifndef __ALLEGRO_ENGINE_H
#define __ALLEGRO_ENGINE_H

#include"RenderEngine.h"
#include "../config.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define BLOCK_HEIGHT (64)
#define BLOCK_WIDTH  (64)
#define DISP_HEIGHT (BLOCK_HEIGHT * LEVEL_HEIGHT)
#define DISP_WIDTH (BLOCK_WIDTH * LEVEL_WIDTH)

int AllegroEngine_init(ALLEGRO_EVENT_QUEUE *q);
void AllegroEngine_render(levelptr_t level);
int AllegroEngine_destroy();

#endif