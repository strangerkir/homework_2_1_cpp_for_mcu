#include "led.h"
#include "config.h"
#include <Arduino.h>

void Led::init(void) {
  pinMode(Config::led_pin, OUTPUT);
  setState(State::OFF);
  Serial.println("LED initialized");
};

void Led::setState(State state) {
  digitalWrite(Config::led_pin, state == State::ON ? HIGH : LOW);
}

Led::State Led::getState(void) {
  return digitalRead(Config::led_pin) == HIGH ? Led::State::ON
                                              : Led::State::OFF;
}