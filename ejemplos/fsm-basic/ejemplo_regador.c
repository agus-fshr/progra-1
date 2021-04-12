



#define TIEMPO_RIEGO 60*20 // 20 min

#define ON 1
#define OFF 0

#define REGANDO_CIRCUITO_1 33
#define REGANDO_CIRCUITO_2 29
#define SISTEMA_APAGADO 23

#define ELECTROVALVULA_C1 156
#define ELECTROVALVULA_C2 5
#define BOMBA_RIEGO 25

#define INPUT_RIEGO 54


void accionar_salida(int, int);
void setup(void);

int segundos = 0;


int main(void) {
    setup();
    int estado = SISTEMA_APAGADO;
    while(1){
        int input = read_input(INPUT_RIEGO);
        switch(estado) {
            case SISTEMA_APAGADO:
                accionar_salida(ELECTROVALVULA_C1, OFF);
                accionar_salida(ELECTROVALVULA_C2, OFF);
                accionar_salida(BOMBA_RIEGO, OFF);
                if(input) {
                    estado = REGANDO_CIRCUITO_1;
                    segundos = 0;
                }
                break;

            case REGANDO_CIRCUITO_1:
                if(segundos < TIEMPO_RIEGO) {
                    accionar_salida(ELECTROVALVULA_C1, ON);
                    accionar_salida(ELECTROVALVULA_C2, OFF);
                    accionar_salida(BOMBA_RIEGO, ON);
                } else {
                    estado = REGANDO_CIRCUITO_2;
                    segundos = 0;
                }
                break;

            case REGANDO_CIRCUITO_2:
                if(segundos < TIEMPO_RIEGO) {
                    accionar_salida(ELECTROVALVULA_C1, OFF);
                    accionar_salida(ELECTROVALVULA_C2, ON);
                    accionar_salida(BOMBA_RIEGO, ON);
                } else {
                    estado = SISTEMA_APAGADO;
                }
                break;
        }
    }
    return 0;
}

void accionar_salida(int salida, int estado){
    set_output(salida, estado == ON);
}

void TIMER_IRQ(){
    segundos++;
}