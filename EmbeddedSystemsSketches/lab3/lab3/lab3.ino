#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5
#define VCC 5
#define FULL_ANGLE 300
#define RED 13
#define GREEN 3


const int HI = 255;
const int LO = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void blink_red(){
  digitalWrite(RED,HI);
  delay(1000);
  digitalWrite(RED,LO);
  delay(1000);
  return;
}

void modulate_LED(int level){
  if (level > HI) {
    level = HI;
  };
  analogWrite(GREEN,level);
  return;
}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage;
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  voltage = (float)sensor_value*ADC_REF/1023;
  float degrees = (voltage*FULL_ANGLE)/VCC;

  int level = degrees*((float)HI/(float)FULL_ANGLE); // ensure level only ranges between 0 and 255
  Serial.println(level);
  modulate_LED(level);

  if (degrees == (float)FULL_ANGLE || degrees == 0.0){
    blink_red();
  };

  delay(25);
}
