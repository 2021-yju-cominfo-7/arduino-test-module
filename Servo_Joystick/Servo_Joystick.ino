#include <Servo.h>

Servo servo;

int JOYSTICK = 13;
int MOTOR = 10;
int ANGLE = 90; 

void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);
  pinMode(JOYSTICK, INPUT_PULLUP);

  servo.attach(MOTOR);
}

void loop() {
  // put your main code here, to run repeatedly:

  int margin = 5;
  int posX = (analogRead(A0) - 512) / 9;
  int posY = analogRead(A1) - 512;

//  Serial.println(posX);

  if (posX < 0 - margin) {
    Serial.print("Left / ");
  } else if (posX > 0 + margin) {
    Serial.print("Right / ");
  } else {
    Serial.print("Center / ");
  }

  int deg = ANGLE + posX;
  Serial.println(deg);
  servo.write(deg);
  
  delay(50);       
}
