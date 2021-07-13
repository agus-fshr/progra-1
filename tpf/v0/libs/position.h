#ifndef POSITION_H
#define POSITION_H
#include<stdint.h>


typedef struct {
    uint8_t x;
    uint8_t y;
} coord_t;

typedef enum {MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT} move_t;

#endif