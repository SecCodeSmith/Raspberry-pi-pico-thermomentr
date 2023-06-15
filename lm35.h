#pragma once
#include <hardware/adc.h>
#include <hardware/gpio.h>
#include <pico/stdlib.h>
#include <stdio.h>
#include <math.h>

/* Temperature sensor ADC channel and pin */
#define VREF 5
#define ADC_MAX 65535

class LM35 {

protected:
    int GPIO_PIN;
    int ADC_PIN;
public:
    LM35(int GPIO_PIN, int ADC_PIN);
    int init();
    float temperature_get_data();
};