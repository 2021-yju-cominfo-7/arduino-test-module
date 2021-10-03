int AA = 6;               //모터A의 A를 6번 핀에 배치
int AB = 7;               //모터A의 B를 7번 핀에 배치

int BA = 2;               //모터B의 A를 2번 핀에 배치
int BB = 3;               //모터B의 A를 3번 핀에 배치


 
void setup() 
{
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT); 
  pinMode(BA, OUTPUT);
  pinMode(BB, OUTPUT);

}
 
void loop() 
{
  digitalWrite(AA, HIGH);          //모터A를 정회전
  digitalWrite(AB, LOW);
  digitalWrite(BA, HIGH);          //모터B를 정회전
  digitalWrite(BB, LOW);
  delay(1000);                     
 
  digitalWrite(AA, LOW);           //모터A를 정지
  digitalWrite(AB, LOW);
  digitalWrite(BA, LOW);           //모터B를 정지
  digitalWrite(BB, LOW);
  delay(250);
  
  digitalWrite(AA, LOW);           //모터A를 역회전     
  digitalWrite(AB, HIGH);  
  digitalWrite(BA, LOW);           //모터A를 역회전     
  digitalWrite(BB, HIGH);
  delay(1000);
}
