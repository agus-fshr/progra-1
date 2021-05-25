#ifndef GPIO_EMUL_H
#define GPIO_EMUL_H

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
 * @brief
 * @param
 * @return
 */
void bit_set(uint8_t port_id, uint8_t bit);

/**
 * @brief
 * @param
 * @return
 */
void bit_clr(uint8_t port_id, uint8_t bit);

/**
 * @brief
 * @param
 * @return
 */
uint8_t bit_get(uint8_t port_id, uint8_t bit);

/**
 * @brief
 * @param
 * @return
 */
void bit_toggle(uint8_t port_id, uint8_t bit);

/**
 * @brief
 * @param
 * @return
 */
void mask_on(uint8_t port_id, uint16_t mask); 

/**
 * @brief
 * @param
 * @return
 */
void mask_off(uint8_t port_id, uint16_t mask); 

/**
 * @brief
 * @param
 * @return
 */
void mask_toggle(uint8_t port_id, uint16_t mask); 

/**
 * @brief
 * @param
 * @return
 */
void get_port(uint8_t port_id);

/**
 * @brief
 * @param
 * @return
 */
uint16_t get_data(uint8_t port_id);


#endif