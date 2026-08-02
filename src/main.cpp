
#include "config.h"
#include "led.h"
#include "time_tracker.h"
#include <Arduino.h>

void setup(void) {
  Serial.begin(Config::serial_baud);
  Led led;
  led.init();
}

void loop(void) {
  static uint16_t iteration = 0;
  static TimeTracker time_tracker;

  if (iteration == 0) {
    time_tracker.start();
  }
  static unsigned long led_updated_at = 0;
  static Led led;

  if (millis() - led_updated_at >= Config::blink_interval) {
    led.setState(led.getState() == Led::State::ON ? Led::State::OFF
                                                  : Led::State::ON);
    led_updated_at = millis();
  }

  if (iteration == 1000) {
    iteration = 0;
    double average_loop_lime = time_tracker.result() / 1000.0;
    Serial.println("Approximate average loop time is " +
                   String(average_loop_lime, 3U) + "ms");
  } else {
    iteration++;
  }
}