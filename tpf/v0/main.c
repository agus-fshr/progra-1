#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "objects/Lane.h"
#include "objects/Level.h"
#include "config.h"
#include "libs/sound.h"
#include "objects/RenderEngine.h"
#include <time.h>

#ifdef LEDMAT
    #include "objects/LEDMatrixEngine.h"
    #define INIT_FUN (LedMat_render)
    //#define RENDER_FUN (AllegroEngine_render)
    //#define DESTROY_FUN (AllegroEngine_destroy)
#else
    #include "objects/AllegroEngine.h"
    #define INIT_FUN (AllegroEngine_init)
    #define RENDER_FUN (AllegroEngine_render)
    #define DESTROY_FUN (AllegroEngine_destroy)
#endif

void must_init(bool test, const char *description);
uint8_t is_in_array(int16_t *arr, int16_t elem, int16_t len);

int main()
{
    uint8_t input_cooldown = 0;
    uint8_t i;

    engineptr_t engine = malloc(sizeof(engineptr_t));
    engine->render = RENDER_FUN;
    engine->init = INIT_FUN;
    engine->destroy = DESTROY_FUN;
    
    srand((unsigned int) time(NULL));

    levelptr_t level = malloc(sizeof(level_t));
    Level_init(level);
    
    level->lanes[0]->type = MOB_FINISH;
    level->lanes[0]->delta = 4;
    level->lanes[0]->step = 0;
    level->lanes[0]->x0 = 50;
    level->lanes[0]->mob_length = 1;
    level->number = 0;
    Level_gen(level);
 
    level->frog->x = 16*60/2;
    level->frog->lane = 15;
    level->frog->lives = 3;

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(TIMEBASE);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");


    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    sound_init();
    engine->init(queue);

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;
    
    #define KEY_SEEN     1
    #define KEY_RELEASED 2

    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));
    al_start_timer(timer);
    ALLEGRO_SAMPLE *sample = al_load_sample(sounds[SFX_JINGLE]);
    al_play_sample(sample, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, 0);
    while(1)
    {
        al_wait_for_event(queue, &event);
        uint8_t i;
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                if(!level->paused) {
                    for(i = 0; i < LEVEL_HEIGHT; i++) {
                        Lane_tick(level->lanes[i]);
                    }
                    laneptr_t lane = level->lanes[level->frog->lane];
                    if(lane->type == MOB_LOG) {
                        int16_t newx = level->frog->x + lane->step;
                        if((newx > 0) && (newx+60 < BLOCK_WIDTH*LEVEL_WIDTH)) {
                            if(input_cooldown != 3)
                                level->frog->x = newx;
                        }
                    }
                    // Si vas y venis en el lugar arriba de un tronco
                    // te deslizas por una desincronización entre
                    // el movimiento y el acompañamiento
                }

                if(input_cooldown > 0) input_cooldown--;
                redraw = true;
                break;
        
            case ALLEGRO_EVENT_KEY_DOWN:
                if(input_cooldown != 0) break;
                if(event.keyboard.keycode == ALLEGRO_KEY_UP){
                    level->frog->movement = MOVE_UP;
                    if(level->frog->lane >= 1)
                        level->frog->lane -= 1;
                } else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
                    level->frog->movement = MOVE_DOWN;
                    if(level->frog->lane < LEVEL_HEIGHT-1)
                        level->frog->lane += 1;
                } else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                    level->frog->movement = MOVE_LEFT;
                    if(level->frog->x >= BLOCK_WIDTH)
                        level->frog->x -= BLOCK_WIDTH;
                }else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    level->frog->movement = MOVE_RIGHT;
                    if(level->frog->x < (LEVEL_WIDTH-1)*BLOCK_WIDTH)
                        level->frog->x += BLOCK_WIDTH;
                }

                switch(event.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                    case ALLEGRO_KEY_DOWN:
                    case ALLEGRO_KEY_RIGHT:
                    case ALLEGRO_KEY_LEFT:
                        sound_play(SFX_HOP);
                        break;
                    default: break;
                }
                if(event.keyboard.keycode == ALLEGRO_KEY_P) {
                    level->paused = !level->paused;
                }
                input_cooldown = 3; //a
                if(event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
                    break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;
    
        // BUG: si apretas rapido no analiza colisiones
        if(!done && redraw && al_is_event_queue_empty(queue))
        {
            engine->render(level);
            //printf("%d %d\n", level->lanes[14]->x0, level->lanes[14]->step);
            printf("%d\n", level->frog->lives);
            /*
            for(i = 0; i < 5; i++) {
                printf("%d ", finishers[i]);
            }
            printf("\n");
            */

            uint16_t frogx = level->frog->x;
            uint16_t frogy = level->frog->lane;
            uint8_t finish_order;
            uint8_t collided = Level_check_collisions(level, &finish_order);
            if(collided && level->lanes[frogy]->type == MOB_CAR) {
                sound_play(SFX_SQUASH);
                if(Frog_kill(level->frog) == 0)
                    done = 1;
            }
            if(!collided && level->lanes[frogy]->type == MOB_LOG) {
                sound_play(SFX_PLUNK);
                if(Frog_kill(level->frog) == 0)
                    done = 1;
            }
            if(!collided && level->lanes[frogy]->type == MOB_FINISH) {
                sound_play(SFX_SQUASH);
                if(Frog_kill(level->frog) == 0)
                    done = 1;
            }
            
            if(collided && level->lanes[frogy]->type == MOB_FINISH) {
                if(is_in_array(level->finishers, finish_order, 5)){
                        if(Frog_kill(level->frog) == 0)
                            done = 1;
                    } else{
                        level->finishers[level->finisher_count++] = finish_order;
                        Frog_reset(level->frog);
                        level->score += 1;
                        if(level->finisher_count == 5){
                            level->score += 5*(level->number + 1);
                            level->number++;
                            Level_gen(level);
                        }
                    }
            }
            redraw = false; // a
        }
    }

    al_destroy_font(font);
    engine->destroy();
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

void must_init(bool test, const char *description) {
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

uint8_t is_in_array(int16_t *arr, int16_t elem, int16_t len) {
    uint8_t i = 0;
    for(i = 0; i < len; i++) {
        if(arr[i] == elem) return 1;
    }
    return 0;
}