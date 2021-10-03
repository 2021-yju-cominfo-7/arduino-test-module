#include <Servo.h>

Servo servo;

int motor = 10;    // 서브모터 핀
int angle = 90;   // 서브모터 초기 각도 값

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  servo.attach(motor);  // 서브모터 연결
}

void loop() {
  Serial.println("11");
  servo.write(140);
}
