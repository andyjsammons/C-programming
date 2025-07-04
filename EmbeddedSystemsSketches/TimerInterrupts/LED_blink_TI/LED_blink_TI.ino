const int led_pin = 13;
const uint16_t t1_load=0;
const uint16_t t1_comp=5000;
bool status=LOW;

void setup() {
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin,status);
  TCCR1A=0;
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);

  TCNT1=t1_load;
  OCR1A=t1_comp;
  TIMSK1 = (1 << OCIE1A);
  sei();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10000);
}


ISR(TIMER1_COMPA_vect){
  TCNT1=t1_load;
  status=!status;
  digitalWrite(led_pin,status);
}