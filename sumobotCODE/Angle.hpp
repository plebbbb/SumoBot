#include <AS5600.h>

#include "Pindef.h"

#ifndef ANGLE_HPP
#define ANGLE_HPP

struct RotationSensor: public AMS_5600{
  RotationSensor(): AMS_5600(){
  }
  double get_radians(){
    return double(getRawAngle())*ROTSENS_RAW_TO_RAD;
  }
};


#endif