#include "DCmotor.h"
#include <Arduino.h>

DCmotor::DCmotor() {};
DCmotor::~DCmotor() {};

void DCmotor::attach(unsigned int IN1, unsigned int IN2, unsigned int PWM) {
  in1 = IN1;
  in2 = IN2;
  pwm = PWM;
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pwm, OUTPUT);
  isAttached = true;
}

void DCmotor::invertDirection() {
  if (!isAttached) return;
  isInvertdirection = !isInvertdirection;
}

void DCmotor::setSpeed(bool direction, unsigned int value) {
  if (!isAttached) return; // ✅ 修复 BUG
  
  // 异或操作巧妙处理方向反转
  digitalWrite(in1, direction ^ isInvertdirection);
  digitalWrite(in2, !direction ^ isInvertdirection);
  
  if (value > 255) value = 255;
  analogWrite(pwm, value);
  isSetdirection = true;
}

void DCmotor::setSpeed(unsigned int value) {
  if (!isAttached) return;
  
  // 优化：如果没有设置过方向，默认给正转
  if (!isSetdirection) {
    setSpeed(true, value); 
  } else {
    if (value > 255) value = 255;
    analogWrite(pwm, value);
  }
}

void DCmotor::brake() {
  if (!isAttached) return; // ✅ 修复 BUG
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  isSetdirection = false; 
}

void DCmotor::stop() {
  if (!isAttached) return; // ✅ 修复 BUG
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  isSetdirection = false;
}