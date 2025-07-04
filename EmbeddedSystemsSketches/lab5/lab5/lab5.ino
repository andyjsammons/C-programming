#include "ICM_20948.h"
#include <SoftwareSerial.h>


#define WIRE_PORT Wire
#define AD0_VAL 1
#ifdef USE_SPI
ICM_20948_SPI myICM;
#else
ICM_20948_I2C myICM;
#endif


//SoftwareSerial Serial(10,11);


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  Serial.begin(9600);
  WIRE_PORT.begin();
  WIRE_PORT.setClock(400000);
  myICM.enableDebugging();

  bool initialized = false;
  while (!initialized){
    myICM.begin(WIRE_PORT, AD0_VAL);
    Serial.print(F("Initilzation of the sensor returned: "));
    Serial.println(myICM.statusString());
    if (myICM.status != ICM_20948_Stat_Ok)
    {
      Serial.println("Trying again...");
      delay(500);
    }
    else
    {
      initialized = true;
    }
  }

}


void printFormattedFloat(float val, uint8_t leading, uint8_t decimals)
{
  float aval = abs(val);
  if (val < 0)
  {
    Serial.print("-");
  }
  else
  {
    Serial.print("+");
  }
  for (uint8_t indi = 0; indi < leading; indi++)
  {
    uint32_t tenpow = 0;
    if (indi < (leading - 1))
    {
      tenpow = 1;
    }
    for (uint8_t c = 0; c < (leading - 1 - indi); c++)
    {
      tenpow *= 10;
    }
    if (aval < tenpow)
    {
      Serial.print("0");
    }
    else
    {
      break;
    }
  }
  if (val < 0)
  {
    Serial.print(-val, decimals);
  }
  else
  {
    Serial.print(val, decimals);
  }
}



#ifdef USE_SPI
void printScaledAGMT(ICM_20948_SPI *sensor)
{
#else
void printScaledAGMT(ICM_20948_I2C *sensor)
{
#endif
  float aX = sensor->accX();
  float aY = sensor->accY();
  float aZ = sensor->accZ();
  float accTotal = sqrt(aX*aX + aY*aY + aZ*aZ);

  if (accTotal < 300.00){
    Serial.println();
    Serial.println("****FALLING!****");
    Serial.println();
    delay(200);
  }

  Serial.println();
  //Serial.print("Mag (uT) [ ");
  printFormattedFloat(sensor->magX()+33, 3, 0);
  Serial.print(", ");
  printFormattedFloat(sensor->magY()+5, 3, 0);
  Serial.println();
}



void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
    Serial.write(Serial.read());
  if (Serial.available())
    Serial.write(Serial.read());
  if (myICM.dataReady()){
    myICM.getAGMT();
    //printRawAGMT(myICM.agmt);
    printScaledAGMT(&myICM);
    delay(500);
  }
  else{
    Serial.println("Waiting for data");
    delay(500);
  }
}
