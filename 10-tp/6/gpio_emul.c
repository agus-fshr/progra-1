#include <stdio.h>
#include <stdint.h>

#include "gpio_emul.h"



/****************************
*           MAIN            *
****************************/
typedef union port{
    struct {
        uint8_t port_B;
        uint8_t port_A;
    };
    uint16_t port_D;
} port_t;

static port_t port = { .port_D = 0 };
static uint8_t port_size;
static void *p_port;


/****************************
*         FUNCTIONS         *
****************************/

void bit_set(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) |= 1 << bit;
    } else if(port_size == 16) {
        *((uint16_t*)p_port) |= 1 << bit;
    }
}

void bit_clr(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) &= ~(1 << bit);
    } else if(port_size == 16) {
        *((uint16_t*)p_port) &= ~(1 << bit);
    }
}

uint8_t bit_get(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    
    if(port_size == 8) {
        return (*((uint8_t*)p_port) & (1 << bit)) >> bit;
    } else if(port_size == 16) {
        return (*((uint16_t*)p_port) & (1 << bit)) >> bit;
    }
    return 0;
}

void bit_toggle(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) ^= (1 << bit);
    } else if(port_size == 16) {
        *((uint16_t*)p_port) ^= (1 << bit);
    }
}

void mask_on(uint8_t port_id, uint16_t mask){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) |= mask;
    } else if(port_size == 16) {
        *((uint16_t*)p_port) |= mask;
    }
}

void mask_off(uint8_t port_id, uint16_t mask){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) &= ~mask;
    } else if(port_size == 16) {
        *((uint16_t*)p_port) &= ~mask;
    }
}

void mask_toggle(uint8_t port_id, uint16_t mask){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) ^= mask;
    } else if(port_size == 16) {
        *((uint16_t*)p_port) ^= mask;
    }
}

uint16_t get_data(uint8_t port_id) {
    get_port(port_id);
    if(port_size == 8) {
        return *((uint8_t*)p_port);
    } else if(port_size == 16) {
        return *((uint16_t*)p_port);
    }
    return 0;
}

// assuming little-endian
void get_port(uint8_t port_id){
    switch (port_id) {
      case PORTA: {
        port_size = 8;
        p_port = &port.port_A;
        break;
      }
      case PORTB: {
        port_size = 8;
        p_port = &port.port_B;
        break;
      }
      case PORTD: {
        port_size = 16;
        p_port = &port.port_D;
        break;
      }
    }
}