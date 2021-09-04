#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  
  // LCD 초기화
  lcd.init();

  // LCD 의 백라이트 켜기
  lcd.backlight();

  // Print a message to the LCD.
//  lcd.setCursor(0,0);             // 1번째, 1라인
//  lcd.print("Hello, world!");
//  lcd.setCursor(0,1);             // 1번째, 2라인
//  lcd.print("Enjoy - Eduino");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(2, 0);
  lcd.print("Hello World!");

  lcd.setCursor(2, 1);
  lcd.print("- Copynull -");
}
