// Sea una funcion que recibe un double y devuelve el valor
// absoluto de dicho numero.


// A.  Escribir el prototipo de la funcion

// B.  Escribir en una linea una llamada a dicha funcion, 
//     pasandole el valor -4.3 y guardando el resultado
//     en una variable

// C.  Escribir la definicion de la funcion

#include <stdio.h>
int main(void){
//A
double vabs(double);

//B
double rta = vabs(-4.3);
printf("%f\n", rta);

return 0;
}

//C
double vabs(double num) {
    if (num >= 0){
        return num;
    }
    else if (num < 0){
        return -num;
    }
    else{
        printf("What the fuck\n");
        return 0.0;
    }
}