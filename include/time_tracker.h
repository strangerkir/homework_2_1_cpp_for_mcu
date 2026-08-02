#ifndef TIME_TRACKER_H
#define TIME_TRACKER_H

class TimeTracker {
public:
  void start();
  unsigned long result();

private:
  unsigned long started_at;
};

#endif