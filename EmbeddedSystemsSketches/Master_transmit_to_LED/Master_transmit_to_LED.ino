#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  randomSeed(420);
  Serial.begin(9600);

}
long randNumber;
byte x = 0;

void loop() {
  // put your main code here, to run repeatedly:
  randNumber = random(10000);
  Wire.beginTransmission(2);
  Serial.println(randNumber);
  if (randNumber % 2 == 0){
    Wire.write(0);
    Serial.println("Zero!");
  }
  else {
    Wire.write(1);
    Serial.println("Not zero!");
  }
  delay(5000);
  Wire.endTransmission();
}