#include <TimerOne.h>

void setup() {
  pinMode(9, OUTPUT);

  Timer1.initialize(10);
  Timer1.pwm(9,102);
}

void loop() {
}
