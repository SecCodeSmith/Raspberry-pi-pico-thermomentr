#include "lm35.h"



LM35::LM35(int GPIO_PIN, int ADC_PIN) {
    this->GPIO_PIN = GPIO_PIN;
    this->ADC_PIN = ADC_PIN;
}

int LM35::init() {
    adc_init();
    adc_gpio_init(this->GPIO_PIN);
    return 0;
}

float LM35::temperature_get_data() {
    float data1;
    float data2;
    adc_select_input(this->ADC_PIN);
    return (adc_read() * VREF * 1000.0) / ADC_MAX; // -> mV
}
