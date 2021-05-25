#include <stdint.h>
#include <stdio.h>

typedef struct bit8 {
    char data[8];
} bit8_t;

typedef struct bit16 {
    char data[16];
} bit16_t;

typedef union port{
  struct {
    bit8_t portB;
    bit8_t portA;
  };
  bit16_t portD;
} port_t;

port_t port;



void bitSet(char * p, int bit) {
    *(p + bit) = 1;
}

int main() {
    for (int i=0; i<16; i++){
        printf("%d", port.portD.data[i]);
    }
    printf("\n");
    bitSet(port.portD, 4);
    for (int i=0; i<16; i++){
        printf("%d", port.portD.data[i]);
    }
}