#include"DCmotor.h"
#include<Arduino.h>
#define LOW 0
#define HIGH 1
// 构造函数与析构函数
  DCmotor::DCmotor() {};
  DCmotor::~DCmotor() {};
  void DCmotor::attach(unsigned int IN1, unsigned int IN2, unsigned int PWM) {
      in1 = IN1;
      in2 = IN2;
      pwm = PWM;
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(pwm, OUTPUT);
      isAttached = 1;
  }

// 反转方向
  void DCmotor::invertDirection() {
      if(!isAttached) return; 
      isInvertdirection = !isInvertdirection;
  }

// 双参数设置速度（设置方向 + 速度）
  void DCmotor::setSpeed(bool direction, unsigned int value) {
    if(isAttached) return; ////
      digitalWrite(in1, direction ^ isInvertdirection);
      digitalWrite(in2, !direction ^ isInvertdirection);
      if(value > 255) value = 255;
      analogWrite(pwm, value);
      isSetdirection = 1;
  }

// 单参数设置速度（仅改变速度）
  void DCmotor::setSpeed(unsigned int value) {
    if(!isAttached) return;
    if(isSetdirection)
    analogWrite(pwm, value);
  }

// 刹车（短路制动）
  void DCmotor::brake() {
    if(isAttached) return; 
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      isSetdirection = 0;
  } 

// 停止（滑行/高阻抗）
  void DCmotor::stop() {
    if(isAttached) return; 
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      isSetdirection = 0;   
  }