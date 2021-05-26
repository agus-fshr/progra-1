/***********************************************
  @file     gpio_emul.h
  @brief    Header file for gpio_emul module
  @author   Grupo 7 Inc.
 **********************************************/

#ifndef GPIO_EMUL_H
#define GPIO_EMUL_H

/**************************
 *  INCLUDE HEADER FILES  *
 *************************/

#include <stdint.h>

/****************************
*         CONSTANTS         *
****************************/

#define PORTA 1
#define PORTB 2
#define PORTD 3

#define PIN_0 1 << 0
#define PIN_1 1 << 1
#define PIN_2 1 << 2
#define PIN_3 1 << 3
#define PIN_4 1 << 4
#define PIN_5 1 << 5
#define PIN_6 1 << 6
#define PIN_7 1 << 7
#define PIN_8 1 << 8
#define PIN_9 1 << 9
#define PIN_10 1 << 10
#define PIN_11 1 << 11
#define PIN_12 1 << 12
#define PIN_13 1 << 13
#define PIN_14 1 << 14
#define PIN_15 1 << 15


/****************************
*          PROTYPES         *
****************************/

/**
 * @brief Sets a bit of the desired port
 * @param port_id Port to manipulate
 * @param bit Bit to set
 */
void bit_set(uint8_t port_id, uint8_t bit);

/**
 * @brief Clears a bit of the desired port
 * @param port_id Port to manipulate
 * @param bit Bit to clear
 */
void bit_clr(uint8_t port_id, uint8_t bit);

/**
 * @brief Reads a bit from the desired port
 * @param port_id Port to read
 * @param bit Bit to read
 * @return State of the read bit
 */
uint8_t bit_get(uint8_t port_id, uint8_t bit);

/**
 * @brief Toggles a bit of the desired port
 * @param port_id Port to manipulate
 * @param bit Bit to toggle
 */
void bit_toggle(uint8_t port_id, uint8_t bit);

/**
 * @brief Sets all the set bits of the mask in a port
 * @param port_id Port to manipulate
 * @param mask Mask to apply
 */
void mask_on(uint8_t port_id, uint16_t mask); 

/**
 * @brief Clears all the set bits of the mask in a port
 * @param port_id Port to manipulate
 * @param mask Mask to apply
 */
void mask_off(uint8_t port_id, uint16_t mask); 

/**
 * @brief Toggles all the set bits of the mask in a port
 * @param port_id Port to manipulate
 * @param mask Mask to apply
 */
void mask_toggle(uint8_t port_id, uint16_t mask); 

/**
 * @brief Reads entire port data
 * @param port_id Port to read
 * @return Port state
 */
uint16_t get_data(uint8_t port_id);


#endif