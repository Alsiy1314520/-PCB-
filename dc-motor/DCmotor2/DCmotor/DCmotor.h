#ifndef DCMOTOR_H
#define DCMOTOR_H

class DCmotor {
  public:
    DCmotor();
    ~DCmotor();
    void attach(unsigned int IN1, unsigned int IN2, unsigned int PWM);
    void invertDirection();
    void setSpeed(unsigned int value);
    void setSpeed(bool direction, unsigned int value);
    void stop();
    void brake();
    private:
    unsigned int in1, in2, pwm;
    bool isAttached = 0;
    bool isInvertdirection = 0;
    bool isSetdirection = 0;
};

#endif