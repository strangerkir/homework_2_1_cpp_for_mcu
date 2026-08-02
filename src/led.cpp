#include <Arduino.h>
#include "config.h"
#include "led.h"

void Led::init() {
    pinMode(Config::led_pin, OUTPUT);
    setState(State::OFF);
    Serial.println("LED initialized\n");
};


void Led::setState(State state) {
    digitalWrite(Config::led_pin, state == State::ON ? HIGH : LOW);
}

Led::State Led::getState() {
    return digitalRead(Config::led_pin) == HIGH ? Led::State::ON : Led::State::OFF;
}