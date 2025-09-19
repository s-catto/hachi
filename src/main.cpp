#include <Arduino.h>
#include <Ultrasonic.h>

#include "../include/motores.h"
#include "../include/ultra.h"
#include "../include/infra.h"

// declaração pinos ++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define LED A1

// infravermelhos
#define infraL A2
#define infraR A3

const ultra ultraL = {.echo = 3, .trig = 4};
const ultra ultraR = {.echo = 8, .trig = 9};

Ultrasonic ultrasonicL(ultraL.trig, ultraL.echo);
Ultrasonic ultrasonicR(ultraR.trig, ultraR.echo);

const motor motorL = {.pwm = 5, .h0 = 11, .h1 = 10};
const motor motorR = {.pwm = 6, .h0 = 12, .h1 = 13};

// declaração funções auxiliares +++++++++++++++++++++++++++++++++++++++

// procura oponente
void procura();

// funções principais +++++++++++++++++++++++++++++++++++++++++++++++++++

void setup() {
  // LED
  pinMode(LED, OUTPUT);

  // infravermelho
  pinMode(infraL, INPUT);
  pinMode(infraR, INPUT);

  // ultrassom
  pinMode(ultraL.echo, INPUT);
  pinMode(ultraL.trig, OUTPUT);
  pinMode(ultraR.echo, INPUT);
  pinMode(ultraR.trig, OUTPUT);

  // motores
  pinMode(motorL.pwm, OUTPUT);
  pinMode(motorL.h0, OUTPUT);
  pinMode(motorL.h1, OUTPUT);

  pinMode(motorR.pwm, OUTPUT);
  pinMode(motorR.h0, OUTPUT);
  pinMode(motorR.h1, OUTPUT);

  Serial.begin(9600);

  freio(motorL, motorR);

  // espera 5 seg, piscando o LED
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }

  //deixa o LED ligado
  digitalWrite(LED, HIGH);

  analogWrite(motorL.pwm, 50);
  analogWrite(motorR.pwm, 50);
}

void loop() {

  // se não encontra linha
  if ((!linha(infraL) && !linha(infraR))){

    // se encontra oponente
    if (encontra(ultraL, ultrasonicL, ultraR, ultrasonicR)) {
      while (!(linha(infraL) || linha(infraR))) 
        frente(motorL, motorR);
      
      re(motorL, motorR);
      delay(300);
    
    // se nao encontra oponente
    } else
      procura();

  // se encontra linha na esquerda
  } else if (linha(infraL)) { 
    direita(motorL, motorR);
    delay(300);
    frente(motorL, motorR);
    delay(300);

  // se encontra linha na direita
  } else if (linha(infraR)) {
    esquerda(motorL, motorR);
    delay(300);
    frente(motorL, motorR);
    delay(300);
  } 
}
// funções auxiliares ++++++++++++++++++++++++++++++++++++++++++++++++

void procura() {
  frente(motorL, motorR);
  delay(300);
  esquerda(motorL, motorR);
  delay(300);

  // estratégia 2:
  // esquerda(motorL, motorR);
}