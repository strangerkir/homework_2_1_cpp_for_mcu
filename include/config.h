#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

class Config {
public:
  static constexpr unsigned long serial_baud = 115200;
  static constexpr uint8_t led_pin = 16;
  static constexpr unsigned long blink_interval =
      1000; // Blink interval in ms, unsigned long for millis() compatibility
};

#endif