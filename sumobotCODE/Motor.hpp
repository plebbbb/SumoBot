#include "Control_loop.hpp"
#include "Angle.hpp"

#ifndef MOTOR_HPP
#define MOTOR_HPP

struct Motor{
  int P1;
  int P2;
  Motor(int e1, int e2):P1(e1),P2(e2){}
  void move_PWM(short fac){ //cant confirm how driver boards work, this is an assumption
    if(fac>>7 & 1) analogWrite(P1, fac);
    else analogWrite(P2, fac);
  }

}


#endif