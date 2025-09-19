#include <Arduino.h>
#include <Ultrasonic.h>
#include "../include/ultra.h"

char encontra(ultra ultraL, Ultrasonic ultrasonicL, ultra ultraR, Ultrasonic ultrasonicR) {
    float tempo, distL, distR;

    // manda sinal por 10 microsseg
    digitalWrite(ultraL.trig, LOW);  
	delay(2);  
	digitalWrite(ultraL.trig, HIGH);  
	delay(10);  
	digitalWrite(ultraL.trig, LOW);

    // recebe tempo que demorou p/ receber sinal
    tempo = pulseIn(ultraL.echo, HIGH);

    distL = (tempo * 0.343) / 2; // calcula distância

    // manda sinal por 10 microsseg
    digitalWrite(ultraR.trig, LOW);  
	delay(2);  
	digitalWrite(ultraR.trig, HIGH);  
	delay(10);  
	digitalWrite(ultraR.trig, LOW);

    // recebe tempo que demorou p/ receber sinal
    tempo = pulseIn(ultraR.echo, HIGH);

    distR = (tempo * 0.343) / 2; // calcula distância

    distL = ultrasonicL.read();
    distR = ultrasonicR.read();

    Serial.print(distL);
    Serial.print(distR);

    if ((distL < distancia) && (distR < distancia)) {
        return 3;
    } else if ((distR < distancia)) {
        return 2;
    } else if ((distL < distancia)) {
        return 1;
    } else {
        return 0;
    }
}