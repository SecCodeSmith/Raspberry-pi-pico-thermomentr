#include <string>
#include <sstream>
#include <math.h>
#include "pico/stdlib.h"
#include "lm35.h"
#include "diode.h"
#include "lcd_display.hpp"

LCDdisplay myLCD(2, 3, 4, 5, 14, 15, 16, 2); // DB4, DB5, DB6, DB7, RS, E, character_width, no_of_lines

Diode diode1(0);
Diode diode2(1);
Diode diode3(11);
Diode diode4(12);
Diode diode5(13);

LM35 lm35_1(27, 0);
LM35 lm35_2(26, 1);

int main()
{
    myLCD.init();

    float read_value = 0;
    float old_data = 0;

    myLCD.print_wrapped("STARTING...");
    
    diode1.init();
    diode1.turn_on();
    diode2.init();
    diode2.turn_on();
    diode3.init();
    diode3.turn_on();
    diode4.init();
    diode4.turn_on();
    diode5.init();
    diode5.turn_on();

    lm35_1.init();
    lm35_2.init();


    myLCD.print_wrapped("INITIALIZED");
    sleep_ms(250);

    while (1)
    {
        float data1, data2;

        data1 = lm35_1.temperature_get_data();
        data2 = lm35_2.temperature_get_data();

        if (abs(data1 - data2) > 2.) {
            myLCD.clear();
            myLCD.print_wrapped("ERROR");

            diode1.turn_on();
            diode2.turn_on();
            diode3.turn_on();
            diode4.turn_on();
        }

        read_value = (data1 + data2) / 2;

        if (read_value > 33) {
            diode1.turn_on();
            diode2.turn_off();
            diode3.turn_off();
            diode4.turn_off();
        } else if (read_value > 25) {
            diode1.turn_off();
            diode2.turn_on();
            diode3.turn_off();
            diode4.turn_off();
        } else if (read_value > 17) {
            diode1.turn_off();
            diode2.turn_off();
            diode3.turn_on();
            diode4.turn_off();
        } else {
            diode1.turn_off();
            diode2.turn_off();
            diode3.turn_off();
            diode4.turn_on();
        }

        if (abs(old_data - read_value) > 0.25 || read_value == 0)
        {
            std::string name = "Temperatura:    ";
            std::stringstream ss;
            ss << read_value;
            name += ss.str();
            myLCD.clear();
            myLCD.print_wrapped(name.c_str());
            old_data = read_value;
        }
        

        diode5.turn_on();
        sleep_ms(125);
        diode5.turn_off();
        sleep_ms(125);
    }
}