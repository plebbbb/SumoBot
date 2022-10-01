#include <I2Cdev.h>
#include <AS5600.h>


#include "Pindef.h"

#ifndef ANGLE_HPP
#define ANGLE_HPP

struct RotationSensor: public AMS_5600{
  int readtime_cur = 0;
  int readtime_prev = 0;
  int rawbuffer_cur = 0;
  int rawbuffer_prev = 0;
  int readtime_RPM = 0;
  int lastrpm = 0;
  int CTR = 0;
  RotationSensor(): AMS_5600(){
  }
  void read(){
    readtime_prev = readtime_cur;
    readtime_cur = millis();
    rawbuffer_prev = rawbuffer_cur;
    rawbuffer_cur = getRawAngle();
  }
  float get_radians(){
    return float(rawbuffer_cur)*ROTSENS_RAW_TO_RAD;
  }
  double get_RPM(){
      return double(get_rel_ang())*ROTSENS_RAW_TO_ROT/(readtime_cur-readtime_prev)*60000.0;
  }
  int get_rel_ang(){
    if (abs(rawbuffer_cur - rawbuffer_prev) > 2000){
      return 4096+(rawbuffer_cur - rawbuffer_prev);
    }
    return (rawbuffer_cur - rawbuffer_prev);
  }
  double get_RPM_count(){
    if (abs(rawbuffer_cur-rawbuffer_prev) > 2000){
      CTR++;
    }
    if (CTR > 5){
      lastrpm = CTR/float(readtime_cur-readtime_RPM)*60000.0;
      readtime_RPM = readtime_cur;
      CTR = 0;
    }
    return lastrpm;
  }
};


#endif