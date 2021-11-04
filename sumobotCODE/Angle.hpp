#include "AS5600.h"
#include "Pindef.h"

#ifndef ANGLE_HPP
#define ANGLE_HPP

struct RotationSensor: public AMS5600{
  RotationSensor(): AMS5600(){
  }
  double get_radians(){
    return double(getRawAngle())*ROTSENS_RAW_TO_RAD;
  }
}


#endif