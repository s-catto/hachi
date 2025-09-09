#include <Arduino.h>
#include "../include/motores.h"

void frente (motor motorL, motor motorR) {
    // seta os dois motores pro sentido "direito
    digitalWrite(motorL.h0, HIGH);
    digitalWrite(motorL.h1, LOW);
    
    digitalWrite(motorR.h0, HIGH);
    digitalWrite(motorR.h1, LOW);
    return;
}

void re (motor motorL, motor motorR) {
    // seta os dois motores pro sentido "direito
    digitalWrite(motorL.h0, LOW);
    digitalWrite(motorL.h1, HIGH);
    
    digitalWrite(motorR.h0, LOW);
    digitalWrite(motorR.h1, HIGH);
    return;
}

void esquerda (motor motorL, motor motorR) {
    // seta o motor esquerdo pro sentido "reverso"
    digitalWrite(motorL.h0, LOW);
    digitalWrite(motorL.h1, HIGH);
    
    // seta o motor direito pro sentido "direito"
    digitalWrite(motorR.h0, HIGH);
    digitalWrite(motorR.h1, LOW);
    return;
}

void direita (motor motorL, motor motorR) {
    // seta o motor esquerdo pro sentido "direito"
    digitalWrite(motorL.h0, HIGH);
    digitalWrite(motorL.h1, LOW);
    
    // seta o motor direito pro sentido "reverso"
    digitalWrite(motorR.h0, LOW);
    digitalWrite(motorR.h1, HIGH);
    return;
}

// freia
void freio (motor motorL, motor motorR) {
    // seta os dois motores em freio
    digitalWrite(motorL.h0, LOW);
    digitalWrite(motorL.h1, LOW);
    
    digitalWrite(motorR.h0, LOW);
    digitalWrite(motorR.h1, LOW);
}