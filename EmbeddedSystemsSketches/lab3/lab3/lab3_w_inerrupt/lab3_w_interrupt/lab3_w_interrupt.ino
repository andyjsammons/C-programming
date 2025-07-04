

int pot = A0;
int GREEN = 6;
int RED = 13;
volatile int RED_state = LOW;
volatile int pot_val=0;
int pwm = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  TCNT1 = 15535; // timer preload value, based on 8-bit prescaler on timer 1.
  //TCNT1 = 1000;
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= B00000010;
  TIMSK1 |= B00000001;
}

void loop() {
  pwm=map(pot_val,0,1023,0,255);
  analogWrite(GREEN,pwm);
  if (pot_val >= 1021 || pot_val <= 2){
    digitalWrite(RED,!RED_state);
    delay(1000);
    digitalWrite(RED,RED_state);
    delay(1000);
  }
}

ISR(TIMER1_OVF_vect){
  if(abs(pot_val - analogRead(pot)) > 1) {
    pot_val = analogRead(pot);
  }
  TCNT1 = 15535;
}
