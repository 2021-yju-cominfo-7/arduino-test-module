#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int JOYSTICK = 8;

void setup() {
  // put your setup code here, to run once:
  
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  pinMode(JOYSTICK, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  int margin = 5;
  int posX = analogRead(A0);
  int posY = analogRead(A1);

  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("X:");
  lcd.print(posX);

  if (posX < 510 - margin) {
    lcd.print(" / Left");
  } else if (posX > 510 + margin) {
    lcd.print(" / Right");
  } else {
    lcd.print(" / Center");
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Y:");
  lcd.print(posY);

  
  if (posY < 512 - margin) {
    lcd.print(" / Down");
  } else if (posY > 512 + margin) {
    lcd.print(" / Up");
  } else {
    lcd.print(" / Center");
  }
  
  Serial.print("X: ");
  Serial.print(posX);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.println(posY);
  
  delay(50);       
}
