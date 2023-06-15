#include "diode.h"

Diode::Diode(int GPIO_PIN) {
    this->GPIO_PIN = GPIO_PIN;
    this->status = false;
}

void Diode::init() {
    gpio_init(this->GPIO_PIN);
    gpio_set_dir(this->GPIO_PIN, GPIO_OUT);
    gpio_put(this->GPIO_PIN, this->status);
}

void Diode::turn_on() {
    this->status = true;
    gpio_put(this->GPIO_PIN, this->status);
}

void Diode::turn_off() {
    this->status = false;
    gpio_put(this->GPIO_PIN, this->status);
}

void Diode::reverse() {
    this->status = !this->status;
    gpio_put(this->GPIO_PIN, this->status);
}