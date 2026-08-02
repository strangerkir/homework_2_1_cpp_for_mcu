class TimeTracker {
public:
  void start();
  unsigned long result();

private:
  unsigned long started_at;
};