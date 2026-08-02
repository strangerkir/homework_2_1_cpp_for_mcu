#include "time_tracker.h"
#include <Arduino.h>

void TimeTracker::start() {
  this->started_at = millis();
}

unsigned long TimeTracker::result() {
  if (this->started_at == 0) {
    return 0;
  }

  return millis() - this->started_at;
}