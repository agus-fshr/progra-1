#include "AllegroEngine.h"
#include <stdio.h>

static int16_t Lane_get_elem_x(laneptr_t lane, int8_t elem);
static int16_t Lane_get_elem_x_end(laneptr_t lane, int8_t elem);
static void render_map(levelptr_t level);
static ALLEGRO_DISPLAY* disp;
static ALLEGRO_BITMAP* bitmap;

int AllegroEngine_init(ALLEGRO_EVENT_QUEUE *q) {
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
    disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
    al_register_event_source(q, al_get_display_event_source(disp));

    return al_init_image_addon();  	  		
}

int AllegroEngine_destroy(){
    al_destroy_bitmap(bitmap);
    al_destroy_display(disp);
    return 0;
}

void AllegroEngine_render(levelptr_t level) {
    if(level->paused) {
    } else {
        render_map(level);
    }
}

void render_pause(levelptr_t level) {
    al_clear_to_color(al_map_rgb(50, 50, 255));
}
// a a

void render_map(levelptr_t level) {
    al_clear_to_color(al_map_rgb(50, 50, 255));
    int16_t i, p;
    for(i = 0; i < LEVEL_HEIGHT; i++) {
        laneptr_t lane = level->lanes[i];
        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;
        if(lane->type == MOB_CAR) {
            al_draw_filled_rectangle(
                0, i*BLOCK_HEIGHT, DISP_WIDTH,
                (1 + i)*BLOCK_HEIGHT, al_map_rgb(90, 90, 90)); 
            red = 255;
            green = 0;
            blue = 0;
        } else if(lane->type == MOB_LOG) {
            al_draw_filled_rectangle(
                0, i*BLOCK_HEIGHT, DISP_WIDTH,
                (1 + i)*BLOCK_HEIGHT, al_map_rgb(50, 50, 255)); 
            red = 150;
            green = 100;
            blue = 100;
        } else if(lane->type == MOB_FINISH) {
            red = 0;
            green = 150;
            blue = 0;
        } else if(lane->type == MOB_FLOOR) {
            al_draw_filled_rectangle(
                0, i*BLOCK_HEIGHT, DISP_WIDTH,
                (1 + i)*BLOCK_HEIGHT, al_map_rgb(150, 150, 150)); 
        }
        if(lane->delta != 0) {
            for(p = -1; p < (LEVEL_WIDTH / lane->delta) + 2; p++) {
                al_draw_filled_rectangle(
                        Lane_get_elem_x(lane, p) < 0 ? 0 : Lane_get_elem_x(lane, p),
                        i*BLOCK_HEIGHT,
                        Lane_get_elem_x_end(lane, p) < 0 ? 0 : Lane_get_elem_x_end(lane, p),
                        (1 + i)*BLOCK_HEIGHT,
                        al_map_rgb(red, green, blue)); 
            }
        }
        
    }
    
    uint16_t frogx = level->frog->x;
    uint16_t frogy = level->frog->lane;
    bitmap = al_load_bitmap("sprites/frog_64.png");

    al_draw_filled_rectangle(frogx, frogy*BLOCK_WIDTH, frogx + BLOCK_WIDTH, (frogy + 1)*BLOCK_HEIGHT, 
                            al_map_rgb(0, 255, 0));
    laneptr_t finisherlane = level->lanes[0];
    for(i = 0; i < 5; i++) {
            al_draw_filled_rectangle(
            Lane_get_elem_x(finisherlane, level->finishers[i]),
            0,
            Lane_get_elem_x_end(finisherlane, level->finishers[i]),
            BLOCK_HEIGHT,
            al_map_rgb(255, 255, 0)); 
    }
    al_draw_bitmap(bitmap, frogx, frogy*BLOCK_HEIGHT, 0);
    
    al_flip_display();
}

int16_t Lane_get_elem_x(laneptr_t lane, int8_t elem) {
    return lane->x0 + elem*lane->delta*BLOCK_WIDTH;
}

int16_t Lane_get_elem_x_end(laneptr_t lane, int8_t elem) {
    return lane->x0 + (elem * lane->delta + lane->mob_length)*BLOCK_WIDTH;
}