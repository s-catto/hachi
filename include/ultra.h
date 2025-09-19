#ifndef _ULTRA_H
#define _ULTRA_H

#define distancia 20

struct ultra {
  char echo;
  char trig;
};

// retorna 1 caso inimigo seja detectado somente por ultraL
//         2 ... somente por ultraR
//         3 ... pelos 2 sensores
char encontra(ultra ultraL, Ultrasonic ultrasonicL, ultra ultraR, Ultrasonic ultrasonicR);

#endif