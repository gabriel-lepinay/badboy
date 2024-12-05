#include "rgb.hpp"

QuackLed::QuackLed(uint8_t r_pin, uint8_t g_pin, uint8_t b_pin) : 
        r_pin(r_pin), g_pin(g_pin), b_pin(b_pin) {
    pinMode(this->r_pin, OUTPUT);
    pinMode(this->g_pin, OUTPUT);
    pinMode(this->b_pin, OUTPUT);
}

void QuackLed::set_color(int r, int g, int b) {
    analogWrite(this->r_pin, 255 - r);
    analogWrite(this->g_pin, 255 - g);
    analogWrite(this->b_pin, 255 - b);
}

void QuackLed::on() {
    analogWrite(this->r_pin, 0);
    analogWrite(this->g_pin, 0);
    analogWrite(this->b_pin, 0);
}

void QuackLed::off() {
    analogWrite(this->r_pin, 255);
    analogWrite(this->g_pin, 255);
    analogWrite(this->b_pin, 255);
}