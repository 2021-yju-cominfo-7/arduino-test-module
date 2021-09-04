#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int JOYSTICK = 8;
int MOTOR = 9;
int ANGLE = 90; 

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

  int margin = 5;
  int posX = analogRead(A0) - 510;
  int posY = analogRead(A1) - 512;
  
  int tmp = 89.5;

  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("X:");
  lcd.print(posX);

  if (posX < 0 - margin) {
    lcd.print(" / Left");
    tmp = ANGLE + posX / 1020.0 * 180;
  } else if (posX > 0 + margin) {
    lcd.print(" / Right");
    tmp = ANGLE + posX / 1037.5 * 180;
  } else {
    lcd.print(" / Center");
  }

  tmp = 179 - tmp;
  Serial.println(tmp);
  servo.write(tmp);
  
  lcd.setCursor(0, 1);
  lcd.print("Y:");
  lcd.print(posY);

  
  if (posY < 0 - margin) {
    lcd.print(" / Down");
  } else if (posY > 0 + margin) {
    lcd.print(" / Up");
  } else {
    lcd.print(" / Center");
  }
  
  delay(50);       
}
