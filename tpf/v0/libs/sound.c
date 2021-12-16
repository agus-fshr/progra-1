#include "sound.h"
#include <stdio.h>

void sound_init(void) {
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(5);
} // aa 

void sound_play(soundfx_t sfx) {
    ALLEGRO_SAMPLE *sample = al_load_sample(sounds[sfx]);
    if(sample) {
        al_play_sample(sample, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
    }
}