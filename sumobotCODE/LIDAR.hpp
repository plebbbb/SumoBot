#include "Adafruit_VL53L1X.h"
#include "Control_loop.hpp"
#include "Pindef.h"

struct LIDAR : public Adafruit_VL53L1X {
  LIDAR(int Address)
    : Adafruit_VL53L1X(SDA, SCL) {
    begin(Address, &Wire);
  }
};

struct LIDARspinner {
}