#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);

void setup() {
  // put your setup code here, to run once:
  pinMode(9, HIGH);
  Serial.begin(9600);
  BTSerial.begin(38400);
  Serial.println("***AT commands mode*** \n Etner AT commands: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  if (Serial.available())
    BTSerial.write(Serial.read());
}
