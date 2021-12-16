#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "objects/Lane.h"
#include "objects/Level.h"
#include "config.h"
#include "libs/sound.h"
#include "objects/GameEngine.h"
#include <time.h>

#ifdef LEDMAT
    #include "objects/LEDMatrixEngine.h"
    #define INIT_FUN (LedMat_render)
    //#define RENDER_FUN (AllegroEngine_render)
    //#define DESTROY_FUN (AllegroEngine_destroy)
    //#define INPUT_FUN ()
#else
    #include "objects/AllegroEngine.h"
    #define INIT_FUN (&AllegroEngine_init)
    #define RENDER_FUN (&AllegroEngine_render)
    #define DESTROY_FUN (&AllegroEngine_destroy)
    #define INPUT_FUN (&AllegroEngine_input)
#endif

void must_init(bool test, const char *description);
uint8_t is_in_array(int16_t *arr, int16_t elem, int16_t len);

int main()
{
    uint8_t input_cooldown = 0, i = 0;

    engineptr_t engine = malloc(sizeof(engine_t));
    engine->render = RENDER_FUN;
    engine->init = INIT_FUN;
    engine->destroy = DESTROY_FUN;
    engine->process_input = INPUT_FUN;

    srand((unsigned int) time(NULL));

    levelptr_t level = malloc(sizeof(level_t));
    Level_init(level);
    
    level->lanes[0]->type = MOB_FINISH;
    level->lanes[0]->delta = 4;
    level->lanes[0]->step = 0;
    level->lanes[0]->x0 = 50;
    level->lanes[0]->mob_length = 1;
    Level_reset(level);

    Frog_move(level->frog, SPAWN_X, SPAWN_Y);
    Frog_reset_lives(level->frog);

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
    al_play_sample(sample, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, 0);

    while(1) {
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
                        if((newx > 0) && (newx+BLOCK_WIDTH < BLOCK_WIDTH*LEVEL_WIDTH)) {
                            level->frog->x = newx;
                        }
                    }
                    // Si vas y venis en el lugar arriba de un tronco
                    // te deslizas por una desincronización entre
                    // el movimiento y el acompañamiento
                    // SOLUCIONADO: como? No se, pero solucionado
                }

                redraw = 1;
                break;
        
            case ALLEGRO_EVENT_KEY_DOWN:
                done = engine->process_input(level, &event.keyboard.keycode);
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = 1;
                break;
        }

        if(done)
            break;
    
        // BUG: si apretas rapido no analiza colisiones
        // SOLUCIONADO: no se como tampoco, pero bueno pero es ser de boca
        if(!done && redraw && al_is_event_queue_empty(queue))
        {
            engine->render(level);
            //printf("%d\n", level->frog->lives);
            done = Level_process_collisions(level);
            redraw = 0;
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
