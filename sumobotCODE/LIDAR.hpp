#include <Adafruit_VL53L1X.h>
#include "Control_loop.hpp"
#include "Pindef.h"

#ifndef LIDAR_HPP
#define LIDAR_HPP
struct LIDAR : public Adafruit_VL53L1X {
  LIDAR(int Address) //REMEMBER TO DISABLE EVERYTHING ON THE BUS PRE ASSIGNMENT
    : Adafruit_VL53L1X(SDA, SCL) {
    begin(Address, &Wire);
  }
};

struct LIDARspinner {



}

#endif