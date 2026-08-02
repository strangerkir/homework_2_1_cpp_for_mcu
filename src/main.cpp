
#include <Arduino.h>
#include "config.h"
#include "led.h"


void setup(void)
{
  Serial.begin(Config::serial_baud);
  Led led;
  led.init();
}


void loop(void)
{
  static unsigned long led_updated_at = 0;
  static Led led;

  if(millis() - led_updated_at >= Config::blink_interval) {
    led.setState(led.getState() == Led::State::ON ? Led::State::OFF : Led::State::ON);
    led_updated_at = millis();
  }
}