/***********************************************
  @file     gpio_emul.c
  @brief    Source file for gpio_emul module
  @author   Grupo 7 Inc.
 **********************************************/

#include <stdio.h>
#include <stdint.h>

#include "gpio_emul.h"


/************
 * TYPEDEFS *
 ***********/

typedef union port{
    struct {
        uint8_t port_B;
        uint8_t port_A;
    };
    uint16_t port_D;
} port_t;


/**************************
 * LOCAL FUNC. PROTOTYPES *
 *************************/

/**
 * @brief Configs the local file vars to the desired port
 * @param port_id Port to manipulate
 */
static void get_port(uint8_t port_id);

/***************************************
 * STATIC VARIABLES W FILE LEVEL SCOPE *
 **************************************/

static port_t port = { .port_D = 0 };
static uint8_t port_size;
static void *p_port;


/****************************
*      GLOBAL FUNCTIONS     *
****************************/

// Bitwise OR to the previous port data with
// all 0s and a 1 in the desired bit's position
void bit_set(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) |= 1 << bit;
    } else if(port_size == 16) {
        *((uint16_t*)p_port) |= 1 << bit;
    }
}

// Bitwise AND to the previous port data with
// all 1s and a 0 in the desired bit's position
void bit_clr(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) &= ~(1 << bit);
    } else if(port_size == 16) {
        *((uint16_t*)p_port) &= ~(1 << bit);
    }
}


// Bitwise AND to the port data with a 1 in the desired bit's 
// position, and then shift the same number of positions to the right.
uint8_t bit_get(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    if(port_size == 8) {
        return (*((uint8_t*)p_port) & (1 << bit)) >> bit;
    } else if(port_size == 16) {
        return (*((uint16_t*)p_port) & (1 << bit)) >> bit;
    }
    return 0;
}

// Bitwise XOR to the previous port data with
// all 0s and a 1 in the desired bit's position
// (0 XOR 1 = 1 and 1 XOR 1 = 0) (controlled NOT)
void bit_toggle(uint8_t port_id, uint8_t bit){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) ^= (1 << bit);
    } else if(port_size == 16) {
        *((uint16_t*)p_port) ^= (1 << bit);
    }
}

// Bitwise OR to the previous port data with the mask
void mask_on(uint8_t port_id, uint16_t mask){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) |= mask;
    } else if(port_size == 16) {
        *((uint16_t*)p_port) |= mask;
    }
}

// Bitwise AND to the previous port data with the mask's 1s complement
void mask_off(uint8_t port_id, uint16_t mask){
    get_port(port_id);
    if(port_size == 8) {
        *((uint8_t*)p_port) &= ~mask;
    } else if(port_size == 16) {
        *((uint16_t*)p_port) &= ~mask;
    }
}

// Bitwise XOR to the previous port data with the mask
// (controlled NOT)
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



/****************************
*       LOCAL FUNCTIONS     *
****************************/

// assuming little-endian
static void get_port(uint8_t port_id){
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
      default:{
          break;
      }
    }
}

