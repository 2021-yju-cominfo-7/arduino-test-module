#include <Stepper.h>

// 2048:한바퀴(360도), 1024:반바퀴(180도)...
//const int stepsPerRevolution = 2048; 
const int stepsPerRevolution = 64;

// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1
Stepper myStepper(stepsPerRevolution,11,9,10,8);           

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(14); 
}

void loop() {
  // 시계 반대 방향으로 한바퀴 회전
//  myStepper.step(stepsPerRevolution);

  for(int i=0; i<32; i++) {  // 64 * 32 = 2048 한바퀴
    myStepper.step(i * stepsPerRevolution);
    Serial.println(i * stepsPerRevolution);
  }
  delay(100);
  

  // 시계 방향으로 한바퀴 회전
//  myStepper.step(-stepsPerRevolution);

  for(int i=0; i<32; i++) {
    myStepper.step(-i * stepsPerRevolution);
    Serial.println(-i * stepsPerRevolution);
  }
  delay(100);
}
