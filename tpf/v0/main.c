#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "objects/Lane.h"
#include "objects/Level.h"
#include <time.h>

#define RANDOM_VERT_SPAWN (rand()%8)*60
#define BLOCK_HEIGHT (60)
#define BLOCK_WIDTH  (60)
#define DISP_HEIGHT (BLOCK_HEIGHT * LEVEL_HEIGHT)
#define DISP_WIDTH (BLOCK_WIDTH * LEVEL_WIDTH)

#define POSITION_STEP (10)
#define STEPS_PER_BLOCK (BLOCK_WIDTH/POSITION_STEP)

uint8_t exists_smthng(laneptr_t lane, uint16_t x);
void must_init(bool test, const char *description);
int16_t Lane_get_elem_x(laneptr_t lane, int8_t elem);
int16_t Lane_get_elem_x_end(laneptr_t lane, int8_t elem);
int8_t is_in_array(int8_t *arr, int8_t elem, int8_t len);


uint8_t lost = 0;
uint8_t won = 0;
int8_t finishers[5] = {-1,-1,-1,-1,-1};
uint8_t finisher_count = 0;


int main()
{
    levelptr_t level = malloc(sizeof(level_t));
    Level_init(level);
    uint8_t i;
    
    level->lanes[0]->type = MOB_FINISH;
    level->lanes[0]->speed_ticks = 0;
    level->lanes[0]->delta = 4;
    level->lanes[0]->step = 12;
    level->lanes[0]->x0 = 2;
    level->lanes[0]->mob_length = 1;
    
    level->lanes[3]->type = MOB_CAR;
    level->lanes[3]->speed_ticks = 0;
    level->lanes[3]->delta = 10;
    level->lanes[3]->step = 20;
    level->lanes[3]->x0 = 0;
    level->lanes[3]->mob_length = 3;
    /*
    level->lanes[5]->type = MOB_CAR;
    level->lanes[5]->speed_ticks = 5;
    level->lanes[5]->delta = 5;
    level->lanes[5]->step = 0;
    level->lanes[5]->x0 = 0;
    level->lanes[5]->mob_length = 2;

    level->lanes[3]->type = MOB_CAR;
    level->lanes[3]->speed_ticks = -2;
    level->lanes[3]->delta = 7;
    level->lanes[3]->step = 0;
    level->lanes[3]->x0 = 0;
    level->lanes[3]->mob_length = 3;
    
    level->lanes[8]->type = MOB_CAR;
    level->lanes[8]->speed_ticks = -1;
    level->lanes[8]->delta = 5;
    level->lanes[8]->step = 0;
    level->lanes[8]->x0 = 0;
    level->lanes[8]->mob_length = 1;
    */
    level->frog->position.x = 16/2;
    level->frog->position.y = 1;
    level->frog->lives = 3;

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
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
    al_start_timer(timer);

    while(1)
    {
        al_wait_for_event(queue, &event);
        uint8_t i;
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                for(i = 0; i < LEVEL_HEIGHT; i++) {
                    laneptr_t lane = level->lanes[i];
                    Lane_tick(lane);
                    lane->x0 = lane->step * POSITION_STEP;
                }
                redraw = true;
                break;
        
            case ALLEGRO_EVENT_KEY_DOWN:
                if(event.keyboard.keycode == ALLEGRO_KEY_UP)
                    if(level->frog->position.y >= 1)
                        level->frog->position.y -= 1;
                if(event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                    if(level->frog->position.y < LEVEL_HEIGHT-1)
                        level->frog->position.y += 1;
                if(event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                    if(level->frog->position.x >= 1)
                        level->frog->position.x -= 1;
                if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                    if(level->frog->position.x < LEVEL_WIDTH-1)
                        level->frog->position.x += 1;
        
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
            al_clear_to_color(al_map_rgb(50, 50, 255));
            //al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", x, y);
            int16_t i, p;
            for(i = 0; i < LEVEL_HEIGHT; i++) {
                laneptr_t lane = level->lanes[i];
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;
                if(lane->type == MOB_CAR) {
                    red = 255;
                    green = 0;
                    blue = 0;
                } else if(lane->type == MOB_FINISH) {
                    red = 0;
                    green = 150;
                    blue = 0;
                }
                if(lane->delta != 0) {
                    for(p = -1; p < LEVEL_WIDTH / lane->delta + 1; p++) {
                        al_draw_filled_rectangle(
                                Lane_get_elem_x(lane, p) < 0 ? 0 : Lane_get_elem_x(lane, p),
                                i*BLOCK_HEIGHT,
                                Lane_get_elem_x_end(lane, p) < 0 ? 0 : Lane_get_elem_x_end(lane, p),
                                (1 + i)*BLOCK_HEIGHT,
                                al_map_rgb(red, green, blue)); 
                    }
                }
                
            }
            
            uint64_t frogx = level->frog->position.x;
            uint64_t frogy = level->frog->position.y;
            al_draw_filled_rectangle(frogx*BLOCK_WIDTH, frogy*BLOCK_WIDTH, (frogx + 1)*BLOCK_WIDTH, (frogy + 1)*BLOCK_HEIGHT, 
                                    al_map_rgb(0, 255, 0));
            
            for(i = 0; i < 5; i++) {
                al_draw_filled_rectangle(finishers[i]*BLOCK_WIDTH, 0, (finishers[i] + 1)*BLOCK_WIDTH, BLOCK_HEIGHT, 
                    al_map_rgb(255, 255, 0));
            }
            
            al_flip_display();
            switch(Level_check_collisions(level)){
                //printf("COLISION\n\r");
                case MOB_CAR:
                case MOB_LOG:
                    lost++;
                    if(Frog_kill(level->frog) == 0)
                        done = 1;
                    break;
                case MOB_FINISH:
                    if(is_in_array(finishers, frogx, 5)){
                        lost++;
                        if(Frog_kill(level->frog) == 0)
                            done = 1;
                    } else{
                        finishers[finisher_count++] = frogx;
                        won++;
                        if(won == 4)
                            done = 1;
                    }
                    break;
                default:
                    break;
                level->frog->position.y = 15;
                printf("Lost: %d \tWon: %d\n", lost, won);
            }
            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

void must_init(bool test, const char *description) {
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int8_t is_in_array(int8_t *arr, int8_t elem, int8_t len) {
    uint8_t i = 0;
    for(i = 0; i < len; i++) {
        if(arr[i] == elem) return 1;
    }
    return 0;
}

int16_t Lane_get_elem_x(laneptr_t lane, int8_t elem) {
    return lane->x0 + elem*lane->delta*BLOCK_WIDTH;
}

int16_t Lane_get_elem_x_end(laneptr_t lane, int8_t elem) {
    return lane->x0 + (elem * lane->delta + lane->mob_length)*BLOCK_WIDTH;
}