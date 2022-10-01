//#include <SparkFun_TB6612.h>

#include "Angle.hpp"
#include "Motor.hpp"
#include <Wire.h>

RotationSensor rotsens;
//Motor* sensor;
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
    analogWrite(3,150);

  Wire.begin();
  // put your setup code here, to run once:
  //sensor = new Motor(9,10,8,11);
}

void loop() {
    //sensor->move_PWM(200);
   /* digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(8,HIGH);
    analogWrite(3,150);
    //delay(1000);*/
 // sensor.move_PWM(200);
  rotsens.read();
        Serial.print("Y: ");

  Serial.println(rotsens.get_RPM_count());
  delay(1);
}
