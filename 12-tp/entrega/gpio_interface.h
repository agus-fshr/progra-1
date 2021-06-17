#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include <stdint.h>

#define BIT_0_PIN 17
#define BIT_1_PIN 4
#define BIT_2_PIN 18
#define BIT_3_PIN 23
#define BIT_4_PIN 24
#define BIT_5_PIN 25
#define BIT_6_PIN 22
#define BIT_7_PIN 27


int print_port(uint8_t data);
int export_port(void);
int unexport_port(void);
int set_port_direction(char *dir);
int write_gpio_status(int pin, int status);
int export_gpio(int pin);
int set_gpio_dir(int pin, char *dir);
int unexport_gpio(int pin);


#endif