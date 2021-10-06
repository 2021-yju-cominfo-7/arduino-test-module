#include <Servo.h>

Servo throttle;
Servo servo;

int pos = 0;
int M_THROTTLE = 9;
int M_SERVO = 10;
int ANGLE = 90; 

// --------------------------------
int DIR_L = 8;
int DIR_R = 7;

int RED = 12;     // STOP
int GREEN = 13;   // START
// --------------------------------

void start_signal()
{
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
}

void stop_signal()
{
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
}

void turn_signal(int deg)
{
  // TODO 각도 범위는 추후 재 수정 필요
  if (deg < 85)
  {    
    digitalWrite(DIR_L, HIGH);
    digitalWrite(DIR_R, LOW);
  }
  else if (deg > 95)
  {
    digitalWrite(DIR_L, LOW);
    digitalWrite(DIR_R, HIGH);
  }
  else
  {
    digitalWrite(DIR_L, HIGH);
    digitalWrite(DIR_R, HIGH);
  }
}

void setup()
{ 
  Serial.begin(9600);
  
  throttle.attach(M_THROTTLE);
  servo.attach(M_SERVO);

  for (pos = 90; pos <= 100; pos += 1) { 
    Serial.println(pos);
    throttle.write(pos);  
    delay(150);                       
  }

  delay(1000);
  
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{  
  String sig;
  char check[1];
  
  char text_t[2] = {0, 0};
  char text_d[3] = {0, 0, 0};
  int value_t = 0;
  int value_d = 0;
  
  while(Serial.available())
  {
    char wait = Serial.read();
    sig.concat(wait);
  }

  sig.substring(0,1).toCharArray(check,2);

  if (check[0] == 'Q')
  {
 
    sig.substring(1, 3).toCharArray(text_t, 3);
    value_t = atoi(text_t);
    
    sig.substring(3, 6).toCharArray(text_d, 4);
    value_d = atoi(text_d);
    
    if (value_t == 0) {
      stop_signal();
    } else {
      start_signal();
    }

    turn_signal(value_d);

    
    throttle.write(value_t + 100);
    servo.write(180 - value_d);
  }
    
  delay(100);
}
