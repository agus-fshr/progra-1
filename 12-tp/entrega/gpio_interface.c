#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "gpio_interface.h"

int export_gpio(int pin) {
	FILE *handler;
	int timeout = 0;

	while((handler = fopen("/sys/class/gpio/export", "w")) == NULL && timeout < 100) {
		usleep(5000);
		timeout++;
	}

	if(handler == NULL) return 0;
	char path[3];
	sprintf(path, "%d", pin);
	fputs(path, handler);
	fclose(handler);
	return 1;
}

int unexport_gpio(int pin) {
	FILE *handler;
	int timeout = 0;

	while((handler = fopen("/sys/class/gpio/unexport", "w")) == NULL && timeout < 100) {
		usleep(5000);
		timeout++;
	}

	if(handler == NULL) return 0;
	char path[3];
	sprintf(path, "%d", pin);
	fputs(path, handler);
	fclose(handler);
	return 1;
}

int set_gpio_dir(int pin, char *dir) {
	FILE *handler;
	char pathstr[32];
	sprintf(pathstr, "/sys/class/gpio/gpio%d/direction", pin);
	if((handler = fopen(pathstr, "w")) != NULL) {
		fputs(dir, handler);
		fclose(handler);
		return 1;
	}
	return 0;
}

int write_gpio_status(int pin, int status) {
	FILE *handler;
	char pathstr[28];
	sprintf(pathstr, "/sys/class/gpio/gpio%d/value", pin);
	if((handler = fopen(pathstr, "w")) != NULL) {
		fputc(status + '0', handler);
		fclose(handler);
		return 1;
	}
	return 0;
}


int print_port(uint8_t data) {
	int acum = 0;
	acum += write_gpio_status(BIT_0_PIN, (data >> 0) && 1);
	acum += write_gpio_status(BIT_1_PIN, (data >> 1) && 1);
	acum += write_gpio_status(BIT_2_PIN, (data >> 2) && 1);
	acum += write_gpio_status(BIT_3_PIN, (data >> 3) && 1);
	acum += write_gpio_status(BIT_4_PIN, (data >> 4) && 1);
	acum += write_gpio_status(BIT_5_PIN, (data >> 5) && 1);
	acum += write_gpio_status(BIT_6_PIN, (data >> 6) && 1);
	acum += write_gpio_status(BIT_7_PIN, (data >> 7) && 1);
	return acum;
}

int set_port_direction(char *dir) {
	int acum = 0;
	acum += set_gpio_dir(BIT_0_PIN, "out");
	acum += set_gpio_dir(BIT_1_PIN, "out");
	acum += set_gpio_dir(BIT_2_PIN, "out");
	acum += set_gpio_dir(BIT_3_PIN, "out");
	acum += set_gpio_dir(BIT_4_PIN, "out");
	acum += set_gpio_dir(BIT_5_PIN, "out");
	acum += set_gpio_dir(BIT_6_PIN, "out");
	acum += set_gpio_dir(BIT_7_PIN, "out");
	return acum;
}

int export_port(void) {
	int acum = 0;
	acum += export_gpio(BIT_0_PIN);
	acum += export_gpio(BIT_1_PIN);
	acum += export_gpio(BIT_2_PIN);
	acum += export_gpio(BIT_3_PIN);
	acum += export_gpio(BIT_4_PIN);
	acum += export_gpio(BIT_5_PIN);
	acum += export_gpio(BIT_6_PIN);
	acum += export_gpio(BIT_7_PIN);
	return acum;
}

int unexport_port(void) {
	int acum = 0;
	acum += unexport_gpio(BIT_0_PIN);
	acum += unexport_gpio(BIT_1_PIN);
	acum += unexport_gpio(BIT_2_PIN);
	acum += unexport_gpio(BIT_3_PIN);
	acum += unexport_gpio(BIT_4_PIN);
	acum += unexport_gpio(BIT_5_PIN);
	acum += unexport_gpio(BIT_6_PIN);
	acum += unexport_gpio(BIT_7_PIN);
	return acum;
}
