#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "objects/Lane.h"
#include "objects/Level.h"
#include <time.h>

#define RANDOM_VERT_SPAWN (rand()%8)*60

uint8_t exists_smthng(laneptr_t lane, uint16_t x);
void must_init(bool test, const char *description);


int main()
{
    levelptr_t level = malloc(sizeof(level_t));
    Level_init(level);
    uint8_t i;
    level->lanes[5]->type = MOB_CAR;
    level->lanes[5]->speed_ticks = 5;
    level->lanes[5]->delta = 4;
    level->lanes[5]->last_position = 0;
    level->frog->position.x = 0;
    level->frog->position.y = 0;

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    
    #define KEY_SEEN     1
    #define KEY_RELEASED 2

    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));
    uint64_t ticks = 0;
    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);
        uint8_t i;
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // once again, no game logic. fishy? maybe.
                for(i = 0; i < LEVEL_HEIGHT; i++) {
                    laneptr_t lane = level->lanes[i];
                    if(lane->speed_ticks != 0){
                        if(!(ticks % lane->speed_ticks))
                            lane->last_position++;
                        if(!(ticks % (lane->speed_ticks*lane->delta)))
                            lane->last_position = 0;
                    }
                }
                ticks++;
                redraw = true;
                break;
        
            case ALLEGRO_EVENT_KEY_DOWN:
                if(event.keyboard.keycode == ALLEGRO_KEY_UP)
                    level->frog->position.y -= 60;
                if(event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                    level->frog->position.y += 60;
                if(event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                    level->frog->position.x -= 60;
                if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                    level->frog->position.x += 60;
        
                if(event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
                    break;
        
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;
    
        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(100, 100, 255));
            //al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", x, y);
            uint16_t i, p;
            
            for(i = 0; i < LEVEL_HEIGHT; i++) {
                for(p = 0; p < LEVEL_WIDTH; p++) {
                    if(exists_smthng(level->lanes[i], p))
                        al_draw_filled_rectangle(p*10, i*10, p*10+60, i*10+60,
                                                al_map_rgb(255, 0, 0)); 
                }
            }
            
            /*
            for (int i=0; i<CAR_LANES; i++){
            	al_draw_filled_rectangle(cars[i].x, cars[i].y, cars[i].x+60, cars[i].y+60, al_map_rgb(0, 0, 255));              //bichito malo
				(cars[i].x)++;
			}                                                                            //update pos en x
            */
            
            uint64_t frogx = level->frog->position.x;
            uint64_t frogy = level->frog->position.y;
            al_draw_filled_rectangle(frogx, frogy, frogx + 60, frogy + 60, 
                                    al_map_rgb(0, 255, 0));

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

uint8_t exists_smthng(laneptr_t lane, uint16_t x) {
    
    //printf("Opa, veamos: \t%d\t%d\t%d\n\r", x, lane->last_position, lane->delta);
    if(x < lane->last_position)
        return 0;
    else if(x == lane->last_position*10)
        return lane->type;
    else if(lane->delta != 0 && ((x - lane->last_position*10) % (lane->delta)) == 0)
        return lane->type;
        
    return 0;
}

void must_init(bool test, const char *description) {
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}