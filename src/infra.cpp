#include <Arduino.h>
#include "../include/infra.h"

char linha (char infra) {
    char val;

    val = analogRead(infra);

    if (val > border) 
        return 0;

    return 1;
}