#include <OneWire.h>
#include <DallasTemperature.h>
#include <EEPROM.h>

#define ONE_WIRE_BUS 4 // Data wire is connected to Arduino digital 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const byte ledPin = 13;
const byte buttonPin = 2;
volatile byte buttonState = LOW;
int addr = 0;

void pin_ISR(){
  for (int i = 0; i < EEPROM.length(); i++){
    Serial.print(EEPROM[i]);
    Serial.println();
  };
  for (int i = 0; i < EEPROM.length(); i++){
    EEPROM.write(i,0);
  };
  addr = 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), pin_ISR, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sensors.requestTemperatures();
  if (addr == EEPROM.length()){
    digitalWrite(ledPin, HIGH);
  }
  else{
    EEPROM.write(addr, sensors.getTempCByIndex(0));
    Serial.print("EERPROM len: ");
    Serial.println(EEPROM.length());
    Serial.print("Addr: ");
    Serial.println(addr);
    addr += 1;
  }
  delay(500);
  digitalWrite(ledPin,LOW);
}
