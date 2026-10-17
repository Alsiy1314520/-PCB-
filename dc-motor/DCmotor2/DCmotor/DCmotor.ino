#define LPWM 27
#define LDIR2 14
#define LDIR1 12
#define RDIR1 13
#define RDIR2 5
#define RPWM 23

#include "DCmotor.h"

DCmotor Lmotor;
DCmotor Rmotor;

void setup() {
  Lmotor.attach(LDIR1, LDIR2, LPWM);
  Rmotor.attach(RDIR1, RDIR2, RPWM);
}

void loop() {
  Lmotor.setSpeed(1, 64);
  Rmotor.setSpeed(1, 64);
  delay(3000);
  Lmotor.stop();
  Rmotor.stop();
  delay(2000);
  Lmotor.setSpeed(0, 192);
  Rmotor.setSpeed(0, 192);
  delay(3000);
  Lmotor.stop();
  Rmotor.brake();
  delay(2000);
}