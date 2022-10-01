//#include "Control_loop.hpp"
//#include "Angle.hpp"

#ifndef MOTOR_HPP
#define MOTOR_HPP

struct Motor{
  int Fwd;
  int Bck;
  int PWM;
  int STBY;
  Motor(int fw, int bk, int st, int pwm1){
    Fwd = fw;
    Bck = bk;
    STBY = st;
    PWM = pwm1;
    pinMode(Fwd, OUTPUT);
    pinMode(Bck, OUTPUT);
    pinMode(STBY, OUTPUT);
    pinMode(PWM, OUTPUT);
    Serial.println("HERE");
  }
  void move_PWM(int fac){
    if (fac > 0) {
      digitalWrite(Fwd, HIGH);
      digitalWrite(Bck, LOW);
    }
    else {
      digitalWrite(Fwd, LOW);
      digitalWrite(Bck, HIGH);
    }
    digitalWrite(STBY, HIGH);
    analogWrite(PWM, fac);
  }
  void E_stop(){
    digitalWrite(STBY, LOW);
    digitalWrite(Fwd, LOW);
    digitalWrite(Bck, LOW);
  }

};


#endif