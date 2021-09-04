#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Stepper.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

int JOYSTICK = 7;
int MOTOR = 6;
int ANGLE = 90; 
int MARGIN = 1;
float distance = 0.0;

void setup() {
  // put your setup code here, to run once:
  
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  pinMode(JOYSTICK, INPUT_PULLUP);

  servo.attach(MOTOR);
}

void loop() {
  // put your main code here, to run repeatedly:

  int push = digitalRead(JOYSTICK);
  int posX = analogRead(A0) - 510;
  int posY = analogRead(A1) - 512;
  
  float current_speed = 0;
  float tmpX = 89.5;
  float tmpY = 1.0;

  if (push == 0) {
    distance = 0.0;
    tmpX = 0.0;
  }
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("X:");

  if (posX < 0 - MARGIN) {
    lcd.print("L/");
    tmpX = ANGLE + posX / 1020.0 * 180;
  } else if (posX > 0 + MARGIN) {
    lcd.print("R/");
    tmpX = ANGLE + posX / 1037.5 * 180;
  } else {
    lcd.print("C/");
  }

  lcd.print(posX);

  tmpX = 179 - tmpX;
  servo.write(tmpX);

  lcd.setCursor(0, 1);
  lcd.print("Y:");
  
  if (posY < 0 - MARGIN) {
    lcd.print("D/");
    tmpY = posY / 512.0 * 500;
    current_speed += tmpY;
  } else if (posY > 0 + MARGIN) {
    lcd.print("U/");
    tmpY = posY / 511.0 * 500;
    current_speed += tmpY;
  } else {
    lcd.print("C/");
    current_speed = 0;
  }

  lcd.print(posY);
  
  distance += current_speed;

  Serial.print("Speed: ");
  Serial.print(current_speed);
  Serial.print("    ");
  lcd.setCursor(9, 0);
  lcd.print(current_speed);
  
  
  Serial.print("Distance: ");
  Serial.println(distance, 1);
  lcd.setCursor(9, 1);
  lcd.print(distance);
  
  delay(50);       
}
