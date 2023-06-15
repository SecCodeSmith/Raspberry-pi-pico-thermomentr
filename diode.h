#pragma once
#include "pico/stdlib.h"

class Diode {
protected:
    int GPIO_PIN;
    bool status;
public:
    Diode(int GPIO_PIN);
    void init();
    void turn_on();
    void turn_off();
    void reverse();
};