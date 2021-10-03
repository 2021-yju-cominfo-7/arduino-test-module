#include <Servo.h>

Servo throttle;

int pos = 0;
int pin = 9;
int JOYSTICK = 8;

void setup() {

  Serial.begin(9600);
  pinMode(JOYSTICK, INPUT_PULLUP);
    
  throttle.attach(pin);

  // This loop arms the ESC
  for (pos = 90; pos <= 100; pos += 1) { 
    Serial.println(pos);
    throttle.write(pos);  
    delay(150);                       
  }

  delay(1000);
}

void loop() {
//  int posX = analogRead(A0);
  int posY = (analogRead(A1) - 500) / 3 + 58;

  if (posY >= 140) {
    posY = 140;
  }

  Serial.print("Y: ");
  Serial.println(posY);
  
  throttle.write(posY);
}
