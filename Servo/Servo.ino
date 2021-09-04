#include <Servo.h>

Servo servo;

int motor = 9;    // 서브모터 핀
int angle = 90;   // 서브모터 초기 각도 값

void setup() {
  // put your setup code here, to run once:

  servo.attach(motor);  // 서브모터 연결
  Serial.begin(9600);

  Serial.println("Enter the u or d");
  Serial.println("u = angle + 15");
  Serial.println("d = angle - 15");
}

void loop() {
  // put your main code here, to run repeatedly:  

  servo.write(0);

}
