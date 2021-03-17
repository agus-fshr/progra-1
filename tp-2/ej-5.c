#include <stdio.h>

#define NRO_DE_TERMS 200

int main(void) {

	int term;
        float x = 0.3;
        double ans = 0;

        for(term=NRO_DE_TERMS; term>=0; term--){
        int i;
        double numerador = 1;
        float denominador = 1;
                for(i=term; i>0; --i){
                numerador *= x;
                denominador *= i;
                }

        ans += numerador/denominador;
        }
        printf("e^(%f) da aproximadamente %.10f\n", x, ans);
        return 0;
}
