int adjust=A0;
int led=6;
int adjust_val=0;
int pwm=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  adjust_val=analogRead(adjust);
  pwm=map(adjust_val,0,1024,0,255);
  analogWrite(led,pwm);
  delay(25);
  Serial.println(adjust_val);
}
