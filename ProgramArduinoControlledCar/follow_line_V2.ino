#include <Adafruit_MotorShield.h>
#include <math.h>
#include <LiquidCrystal.h>

int M1_Speed = 70; // speed of motor 1 
int M2_Speed = 70; // speed of motor 2
int LeftRotationSpeed = 150; // Left Rotation Speed
int RightRotationSpeed = 150; // Right Rotation Speed

const int trigPin = 9;
const int echoPin = 10;
const int rs = 3, en = 5, d4 = 8, d5 = 13, d6 = 12, d7 = 11;
long duration;
int distance_cm;

int RIGHT_SENSOR;
int LEFT_SENSOR;
int CROSS_SENSOR;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Left = AFMS.getMotor(1);
Adafruit_DCMotor *Right = AFMS.getMotor(2);
LiquidCrystal lcd (rs, en, d4, d5, d6 ,d7);
 
void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello, world!");
  delay(2000);
  Serial.begin(9600);
  AFMS.begin();
  pinMode(7, INPUT); // initialize Left sensor as an input
  pinMode(4, INPUT); // initialize Right sensor as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  CROSS_SENSOR = digitalRead(2);
  LEFT_SENSOR = digitalRead(7);
  RIGHT_SENSOR = digitalRead(4);

  Serial.print("distance: ");
  Serial.println(distance_cm);


  if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
    lcd.print("Moving Forward");
    forward(); //FORWARD
  }
 
  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
    right(); //Move Right
   }
 
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
    left(); //Move Left
  }
 /*
  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==0 && !CROSS_SENSOR==0) {
    while (RIGHT_SENSOR==0 && LEFT_SENSOR==0){
      forward();
      delay(300);
      RIGHT_SENSOR = digitalRead(4);
      LEFT_SENSOR = digitalRead(7);
    }
    while (RIGHT_SENSOR != 0 && LEFT_SENSOR != 0){
      forward();
      RIGHT_SENSOR = digitalRead(4);
      LEFT_SENSOR = digitalRead(7);
    }
    Stop();
    right();
    delay(900);
    while(LEFT_SENSOR != 0){
      RIGHT_SENSOR = digitalRead(4);
      LEFT_SENSOR = digitalRead(7);
      right();
      if (LEFT_SENSOR == 0){
        break;
      }
    }
   }
   */
  else if(CROSS_SENSOR==0 && RIGHT_SENSOR==0){
    Stop();
    delay(5000);
    forward();
    delay(500);
  }

}
 
void forward()
{
  lcd.setCursor(0, 0);
  lcd.print("Moving Forward   \n\n");
  Left->run(FORWARD);
  Right->run(FORWARD);
  Left->setSpeed(M1_Speed);
  Right->setSpeed(M2_Speed);
  digitalWrite(echoPin, LOW);
  digitalWrite(echoPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
/*
  duration = pulseIn(echoPin, HIGH);
  distance_cm = microsecondsToCentimeters(duration);

  if (distance_cm < 15 && distance_cm != 0){
    Stop();
    delay(10000);
    digitalWrite(echoPin, LOW);
    digitalWrite(echoPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance_cm = microsecondsToCentimeters(duration);

    if (distance_cm < 15 && distance_cm != 0){
      backward();
      delay(1200);
      left();
      delay(1279);
      forward();
      delay(500);
    }
  }
  */
}
  
void backward()
{
      lcd.setCursor(0, 0);
      lcd.print("Moving Backward    \n\n");
      Left->run(BACKWARD);
      Right->run(BACKWARD);
      Left->setSpeed(M1_Speed);
      Right->setSpeed(M2_Speed);
}
  
void right()
{
      lcd.setCursor(0, 0);
      lcd.print("Turning Right      \n\n");
      Left->run(FORWARD);
      Right->run(BACKWARD);
      Left->setSpeed(LeftRotationSpeed);
      Right->setSpeed(RightRotationSpeed);
      RIGHT_SENSOR = digitalRead(4);
      LEFT_SENSOR = digitalRead(7);
      CROSS_SENSOR = digitalRead(2);

      if(RIGHT_SENSOR==0 && LEFT_SENSOR==0 && !CROSS_SENSOR==0) {
        while (RIGHT_SENSOR==0 && LEFT_SENSOR==0){
          forward();
          RIGHT_SENSOR = digitalRead(4);
          LEFT_SENSOR = digitalRead(7);
        }
        while (RIGHT_SENSOR != 0 && LEFT_SENSOR != 0){
          forward();
          RIGHT_SENSOR = digitalRead(4);
          LEFT_SENSOR = digitalRead(7);
        }
        Left->run(FORWARD);
        Right->run(BACKWARD);
        Left->setSpeed(LeftRotationSpeed);
        Right->setSpeed(RightRotationSpeed);
        delay(700);
        while(LEFT_SENSOR != 0){
          RIGHT_SENSOR = digitalRead(4);
          LEFT_SENSOR = digitalRead(7);
          Left->run(FORWARD);
          Right->run(BACKWARD);
          Left->setSpeed(LeftRotationSpeed);
          Right->setSpeed(RightRotationSpeed);
          if (LEFT_SENSOR == 0){
            break;
          }
        }
      }
}
  
void left()
{
      lcd.setCursor(0, 0);
      lcd.print("Turning Left        \n\n");
      Left->run(BACKWARD);
      Right->run(FORWARD);
      Left->setSpeed(LeftRotationSpeed);
      Right->setSpeed(RightRotationSpeed);
      RIGHT_SENSOR = digitalRead(4);
      LEFT_SENSOR = digitalRead(7);
      if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 0){
        left();
        delay(200);
      }
      
}
  
void Stop()
{
      lcd.setCursor(0, 0);
      lcd.print("Stopped...         \n\n");
      Left->setSpeed(0);
      Right->setSpeed(0);
}

long microsecondsToCentimeters(long duration_ms){
  return 34*duration_ms/2000;
}