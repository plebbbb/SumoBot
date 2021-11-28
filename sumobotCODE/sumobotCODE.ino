#include "Angle.hpp"
#include <Wire.h>

RotationSensor* addr;
void setup() {
  Serial.begin(9600);
  Wire.begin();

  // put your setup code here, to run once:
  *addr = RotationSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(addr->get_radians());
  delay(10);
}
