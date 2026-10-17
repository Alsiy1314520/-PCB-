#ifndef DCMOTOR_H
#define DCMOTOR_H

class DCmotor {
  public:
    DCmotor();
    ~DCmotor();
    
    // 初始化引脚
    void attach(unsigned int IN1, unsigned int IN2, unsigned int PWM);
    
    // 反转电机方向（用于左右电机对称安装）
    void invertDirection();
    
    // 设置速度（保留当前方向）
    void setSpeed(unsigned int value);
    
    // 设置方向和速度 (direction: true=正转, false=反转)
    void setSpeed(bool direction, unsigned int value);
    
    // 滑行停止（高阻抗）
    void stop();
    
    // 刹车制动（短路制动）
    void brake();

  private:
    unsigned int in1, in2, pwm;
    bool isAttached = false;
    bool isInvertdirection = false;
    bool isSetdirection = false;
};

#endif