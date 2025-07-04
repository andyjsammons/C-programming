/*
Experiment 1:
  Set the various Flags and do a Serial Print of Flags
Experiment 2:
  Set Toggle with Limit as 2000 & Print check as OCR1A
  Next print check as TCNT1-now we get ZEROS
Experiment 3:
  Do not set WGM 12 and manually reset TCNT1
  Now check is 2001
Experiment 4:
  Vary Limits and see results
  9875*1024/16000000 = 0.6
*/

uint16_t ini=0;
//uint16_t limit = 2000;
uint16_t limit = 2000;
uint16_t check=0;
const int led_pin = 13;
bool status = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);
  TCNT1=0;
  //PRESCALER of 1024
  TCCR1B=0;
  TCCR1B|=(1<<CS10);
  TCCR1B|=(1<<CS12);
  TCCR1B|=(1<<WGM12);//Clear Timer on Compare
  TCCR1A=0;
  TIMSK1=0;
  TIMSK1|=(1<<OCIE1A);
  OCR1A=limit;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(check);
}

ISR(TIMER1_COMPA_vect){
  status!=status;
  digitalWrite(led_pin,status);
  check=TCNT1;
}
