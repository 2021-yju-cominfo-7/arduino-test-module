void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); //시리얼 통신을 하기위한 통신속도설정
  pinMode(8, INPUT_PULLUP);
   /*
   Z축 스위치에 별도의 저항이 달려있지 않기 때문에 스위치가 눌린지 안눌린지 헷갈려하는
   `플로팅 현상`이 발생 합니다.
   
   이때문에 사용자가 쉽게 플로팅현상을 해결하기 위해서 아두이노에는 기본적으로
   내부에 풀업저항이 달려있습니다.

   플로팅현상을 해결하기 위해서 내부 PULLUP 코드를 사용 하였습니다.
   */


}

void loop() {
  // put your main code here, to run repeatedly:


  int push = digitalRead(3);
  int posX = analogRead(A0);
  int posY = analogRead(A1);

  Serial.print("Push: ");
  Serial.print(push);
  Serial.print("\t");
  Serial.print("X: ");
  Serial.print(posX);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.println(posY);
  delay(1000);               
}
