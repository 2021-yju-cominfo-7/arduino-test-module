int AA = 6;               //모터A의 A를 6번 핀에 배치
int AB = 7;               //모터A의 B를 7번 핀에 배치

int BA = 4;               //모터B의 A를 2번 핀에 배치
int BB = 5;               //모터B의 A를 3번 핀에 배치

int JOYSTICK = 3;
int MARGIN = 2;
 
void setup() 
{
  Serial.begin(9600);
  pinMode(JOYSTICK, INPUT_PULLUP);
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT); 
  pinMode(BA, OUTPUT);
  pinMode(BB, OUTPUT);

}
 
void loop() 
{
  int push = digitalRead(JOYSTICK);
  int posX = analogRead(A0) - 512;
  int posY = analogRead(A1) - 510;

  Serial.print(push);
  Serial.print(" / ");
  Serial.print(posX);
  Serial.print(" / ");
  Serial.println(posY);

  if (posX > MARGIN) {
    Serial.println("전진");
    
    digitalWrite(AA, HIGH);          //모터A를 정회전
    digitalWrite(AB, LOW);
    digitalWrite(BA, HIGH);          //모터B를 정회전
    digitalWrite(BB, LOW);
  } else if (posX < -MARGIN) {
    Serial.println("후진");  
    
    digitalWrite(AA, LOW);          //모터A를 정회전
    digitalWrite(AB, HIGH);
    digitalWrite(BA, LOW);          //모터B를 정회전
    digitalWrite(BB, HIGH);  
  } else {
    Serial.println("정지");

    digitalWrite(AA, LOW);           //모터A를 정지
    digitalWrite(AB, LOW);
    digitalWrite(BA, LOW);           //모터B를 정지
    digitalWrite(BB, LOW);
  }
  
  delay(100);
//  digitalWrite(AA, HIGH);          //모터A를 정회전
//  digitalWrite(AB, LOW);
//  digitalWrite(BA, HIGH);          //모터B를 정회전
//  digitalWrite(BB, LOW);
//  delay(1000);                     
// 
//  digitalWrite(AA, LOW);           //모터A를 정지
//  digitalWrite(AB, LOW);
//  digitalWrite(BA, LOW);           //모터B를 정지
//  digitalWrite(BB, LOW);
//  delay(250);
//  
//  digitalWrite(AA, LOW);           //모터A를 역회전     
//  digitalWrite(AB, HIGH);  
//  digitalWrite(BA, LOW);           //모터A를 역회전     
//  digitalWrite(BB, HIGH);
//  delay(1000);
}
