#include <Arduino.h>


// put function declarations here:
int myFunction(int, int);

// A0 - led
// 10 a 13 - ponte h
// 9 e 8 - 1 sensor ultrassônico 
// 7 - 1 sensor infravermelho 
// 6 e 5 - pwm do motor 
// 4 e 3 - 1 sensor ultrassônico 
// 2 - 1 sensor infravermelho

// infravermelhos
const char infra0 = 2;
const char infra1 = 7;

// ultrassons 
const char echo0 = 3;
const char trig0 = 4;
const char echo1 = 8;
const char trig1 = 9;

// pwm motores
const char pwmL = 5;
const char pwmR = 6;

// ponte H
const char hL0 = 11;
const char hL1 = 10;
const char hR0 = 12;
const char hR1 = 13;

void setup() {
  // LED
  pinMode(A0, OUTPUT);

  // infravermelho
  pinMode(infra0, INPUT);
  pinMode(infra1, INPUT);

  // ultrassom
  pinMode(echo0, INPUT);
  pinMode(trig0, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);

  // pwm motores
  pinMode(pwmL, OUTPUT);
  pinMode(pwmR, OUTPUT);

  // ponte H
  pinMode(hL0, OUTPUT);
  pinMode(hL1, OUTPUT);
  pinMode(hR0, OUTPUT);
  pinMode(hR1, OUTPUT);
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

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}