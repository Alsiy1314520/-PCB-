#include "DCmotor.h"

// 使用 const int 替代 #define，有类型检查，更安全
const int LPWM = 27;
const int LDIR2 = 14;
const int LDIR1 = 12;
const int RDIR1 = 13;
const int RDIR2 = 5;
const int RPWM = 23;

DCmotor Lmotor;
DCmotor Rmotor;

void setup() {
  Lmotor.attach(LDIR1, LDIR2, LPWM);
  Rmotor.attach(RDIR1, RDIR2, RPWM);
  
  // 💡 调试提示：如果发现左右轮一个向前一个向后，取消下面这行的注释
  // Rmotor.invertDirection(); // 反转右电机方向，让双轮同向
}

void loop() {
  // 1. 双轮慢速前进 3 秒 (速度 64)
  Lmotor.setSpeed(true, 64); 
  Rmotor.setSpeed(true, 64);
  delay(3000);
  
  // 2. 滑行停止 2 秒
  Lmotor.stop();
  Rmotor.stop();
  delay(2000);
  
  // 3. 双轮快速后退 3 秒 (速度 192)
  Lmotor.setSpeed(false, 192); 
  Rmotor.setSpeed(false, 192);
  delay(3000);
  
  // 4. 左轮滑行，右轮刹车，测试区别 (2秒)
  Lmotor.stop();
  Rmotor.brake();
  delay(2000);
}