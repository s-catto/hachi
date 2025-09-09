#include <Arduino.h>

#include "../include/motores.h"
#include "../include/ultra.h"
#include "../include/infra.h"

// declaração pinos ++++++++++++++++++++++++++++++++++++++++++++++++++++++

// infravermelhos
const char infra0 = 2;
const char infra1 = 7;

const ultra ultra0 = {.echo = 3, .trig = 4};
const ultra ultra1 = {.echo = 8, .trig = 9};

const motor motorL = {.pwm = 5, .h0 = 11, .h1 = 10};
const motor motorR = {.pwm = 6, .h0 = 12, .h1 = 13};

// declaração funções auxiliares +++++++++++++++++++++++++++++++++++++++



// funções principais +++++++++++++++++++++++++++++++++++++++++++++++++++

void setup() {
  // LED
  pinMode(A0, OUTPUT);

  // infravermelho
  pinMode(infra0, INPUT);
  pinMode(infra1, INPUT);

  // ultrassom
  pinMode(ultra0.echo, INPUT);
  pinMode(ultra0.trig, OUTPUT);
  pinMode(ultra1.echo, INPUT);
  pinMode(ultra1.trig, OUTPUT);

  // motores
  pinMode(motorL.pwm, OUTPUT);
  pinMode(motorR.pwm, OUTPUT);

  // ponte H
  pinMode(motorL.h0, OUTPUT);
  pinMode(motorL.h1, OUTPUT);
  pinMode(motorR.h0, OUTPUT);
  pinMode(motorR.h1, OUTPUT);
}

void loop() {
  // espera 5 seg, piscando o LED
  for (int i = 0; i < 5; i++) {
    digitalWrite(A0, HIGH);
    delay(500);
    digitalWrite(A0, LOW);
    delay(500);
  }

  //deixa o LED ligado
  digitalWrite(A0, HIGH);
}

// funções auxiliares ++++++++++++++++++++++++++++++++++++++++++++++++