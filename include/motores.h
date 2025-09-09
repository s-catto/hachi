#ifndef _MOTORES_H
#define _MOTORES_H

struct motor {
  char pwm;
  // entradas ponte h
  char h0; 
  char h1;
};

// move pra frente
void frente (motor motorL, motor motorR);
// move para trás
void re (motor motorL, motor motorR);
// gira pra esquerda
void esquerda (motor motorL, motor motorR);
// gira pra direita
void direita (motor motorL, motor motorR);
// freia
void freio (motor motorL, motor motorR);

#endif