#include <Servo.h>

Servo throttle;
Servo servo;

int pos = 0;
int JOYSTICK = 8;
int M_THROTTLE = 9;
int M_SERVO = 10;
int ANGLE = 90; 

void setup() {

  Serial.begin(9600);
  pinMode(JOYSTICK, INPUT_PULLUP);
    
  throttle.attach(M_THROTTLE);
  servo.attach(M_SERVO);

  // This loop arms the ESC
  for (pos = 90; pos <= 100; pos += 1) { 
    Serial.println(pos);
    throttle.write(pos);  
    delay(150);                       
  }

  delay(1000);
}

void loop() {
  
  int margin = 5;
  int posX = (analogRead(A0) - 512) / 8;
  int posY = (analogRead(A1) - 500) / 3 + 58;


  if (posX < 0 - margin) {
    Serial.print("Left / ");
  } else if (posX > 0 + margin) {
    Serial.print("Right / ");
  } else {
    Serial.print("Center / ");
  }
  
  if (posY >= 140) {
    posY = 140;
  }


  int deg = (ANGLE + posX) / 10 * 10;
  if (deg < 30) {
    deg = 30;
  } else if (deg > 150) {
    deg = 150; 
  } else if (deg >= 80 && deg <= 100) {
    deg = 90;
  }
  
  Serial.print("D: ");
  Serial.print(deg);
  servo.write(deg);

  Serial.print(" / ");
  
  Serial.print("S: ");
  Serial.println(posY);
  throttle.write(posY);
}
