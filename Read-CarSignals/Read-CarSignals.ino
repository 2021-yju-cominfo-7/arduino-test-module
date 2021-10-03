
byte PIN_CH1 = 5;   // Steering Servo
byte PIN_CH2 = 6;   // Speed Control

int pwm_value_ch1;
int pwm_value_ch2;

void setup() {
    pinMode(PIN_CH1, INPUT);
    pinMode(PIN_CH2, INPUT);
    Serial.begin(9600);
}

void loop() {
    pwm_value_ch1 = pulseIn(PIN_CH1, HIGH);
    pwm_value_ch2 = pulseIn(PIN_CH2, HIGH);
    Serial.print("Servo : ");
    Serial.print(pwm_value_ch1);
    
    Serial.print("  //  ");
    
    Serial.print("Speed : ");
    Serial.print(pwm_value_ch2);
    
    Serial.println("\n");
}
