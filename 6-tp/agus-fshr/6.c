// Escribir una función que determine si ocurrió una pierna de póker.
// Una mano tiene 5 cartas. Las cartas se identifican con un valor numérico (de 2 a 10,
// J = 11, Q = 12, K = 13 y AS = 1) y con un palo (♠ = 100, ♥ = 200, ♦ = 300 y ♣ = 400).
// La carta se compone de sumar el valor con el palo (211 es J♥).
// Una pierna ocurre cuando hay 3 cartas del mismo valor y distinto palo.
// El prototipo debe ser: int pierna_poker (const int cartas[]);
// La función debe devolver 0 si no hubo pierna, o si hubo el valor (sin palo) de las
// cartas de la pierna. No es necesario validar las cartas ni determinar si ocurrió otro
// juego mayor.

#include <stdio.h>

void pierna(int hand[]);

int hand[] = {212, 312, 111, 212, 313};

int main(){
    pierna(hand);
    return 0;
}

void pierna(int *hand){
    
    int matching_card = 0;
    int matches = 0;

    for (int i=0; i<5; i++){
        matches = 0;

        for (int c=0; c<5; c++){
            if (hand[c]%100 == hand[i]%100){
                matches++;
            }
        }

        if (matches == 3){
            matching_card = hand[i]%100;
            break;
        }
    }
    printf("%d matches\n", matching_card);

}