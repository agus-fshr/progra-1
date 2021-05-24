#include <stdio.h>
#include <stdlib.h>

/****************************
*         CONSTANTS         *
****************************/
#define PORT8BITS 8
#define PORT16BITS 16
/****************************
*          PROTYPES         *
****************************/
void bitSet(char port_id, int bit);
void bitClr(char port_id, int bit);
int bitGet(char port_id, int bit);
void bitToggle(char port_id, int bit);
// void maskOn(char port_id, int mask); 

void getPort(char port_id);
// static int getNum(char *p_port, int port_len);
// static double power(double x, int exp);
/****************************
*           MAIN            *
****************************/
typedef union port{
    struct {
        char portB[PORT8BITS];
        char portA[PORT8BITS];
    };
    char portD[PORT16BITS];
} port_t;
static port_t port;

int port_size;
char *p_port;

int main(void){

    for (int i=0; i<8; i++){    
        printf("%d", port.portA[i]);
    }

    printf("\n");


    for (int i=0; i<8; i++){
        printf("%d", port.portA[i]);
    }


}
/****************************
*         FUNCTIONS         *
****************************/
void bitSet(char port_id, int bit){
    getPort(port_id);
    *(p_port + bit) = 1;
}

void bitClr(char port_id, int bit){
    getPort(port_id);
    *(p_port + bit) = 0;
}

int bitGet(char port_id, int bit){
    getPort(port_id);
    return *(p_port + bit);
}

void bitToggle(char port_id, int bit){
    getPort(port_id);
    if(bitGet(p_port, bit)){
        bitSet(p_port, bit);
    }
    else{
        bitClr(p_port, bit);
    }
}

// void maskOn(char port_id, int mask){

// }

// void putNum(char *p_port, int port_data){
    
// }

// int getNum(char *p_port, int port_len){
//     int ans = 0;
//     for(int i = 0; i < 8; i++){
//         ans += *(p_port + i)*power(2,7-i);
//     }
//     return ans;
// }    

// double power(double x, int exp) {
//     double ans = 1;
//     for (int n=1; n<=exp; n++){
//         ans *= x;
//     }
//     return ans;
// }

void getPort(char port_id){
    switch (port_id) {
      case 'a': {
        port_size = 8;
        p_port = port.portA;
        break;
      }

      case 'b': {
        port_size = 8;
        p_port = port.portB;
        break;
      }

      case 'd': {
        port_size = 16;
        p_port = port.portD;
        break;
      }

      default : {
        break;
      }
    }
}