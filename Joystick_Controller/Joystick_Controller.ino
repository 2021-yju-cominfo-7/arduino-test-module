#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  int cenX = 510;
  int cenY = 512;
  
  int posX = analogRead(A0) - cenX;
  int posY = analogRead(A1) - cenY;

  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("X:");
  lcd.print(posX);

  if (posX == 0) {
    lcd.print(" / Center");
  } else if (posX < cenX) {
    lcd.print(" / Left");
  } else {
    lcd.print(" / Right");
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Y:");
  lcd.print(posY);
  
  if (posY == 512) {
    lcd.print(" / Center");
  } else if (posY < cenY) {
    lcd.print(" / Down");
  } else {
    lcd.print(" / Up");
  }
  
  Serial.print("X: ");
  Serial.print(posX);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.println(posY);
  
  delay(50);       
}
