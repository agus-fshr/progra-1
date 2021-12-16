#ifndef __ALLEGRO_ENGINE_H
#define __ALLEGRO_ENGINE_H

#include "GameEngine.h"
#include "../config.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "../libs/sound.h"

#define BLOCK_HEIGHT (64)
#define BLOCK_WIDTH  (64)
#define DISP_HEIGHT (BLOCK_HEIGHT * LEVEL_HEIGHT)
#define DISP_WIDTH (BLOCK_WIDTH * LEVEL_WIDTH)

#define SPAWN_X (LEVEL_WIDTH*BLOCK_WIDTH/2)
#define SPAWN_Y (15)
//a
int AllegroEngine_init(void *q);
void AllegroEngine_render(levelptr_t level);
int AllegroEngine_destroy();
int AllegroEngine_input(levelptr_t level, void* keycode);

#endif