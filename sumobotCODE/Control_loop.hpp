#include "ARDUINO_AVRSTL.h"

#ifndef CONTROL_LOOP_HPP
#define CONTROL_LOOP_HPP

  //if anyone wants to try, it would be nice if we could implicitly construct these. It would require a restructuring of everything though.
  struct controlelement{
      double factor;
      double maxcap;
      double mincap;
      controlelement(double fac, double min, double max):factor(fac),mincap(min),maxcap(max){}
      virtual double compute(double target, double current) = 0;
  };

  struct Proportional: public controlelement{

      Proportional(double fac, double min, double max):controlelement(fac, min, max){
      }

      //standard offset format: target-current. This class assumes the offset is in the correct direction already
      double compute(double target, double current){
          double rawval = (target-current);
          double returnval = factor*rawval;
          return (returnval <= maxcap) ? ((returnval >= mincap) ? returnval : mincap) : maxcap;
      }
  };

  struct Integral: public controlelement{
      double last = 0;
      Integral(double fac, double min, double max):controlelement(fac, min, max){}

      //standard offset format: target-current. This class assumes the offset is in the correct direction already
      double compute(double target, double current){
          if((int)target == (int)current) last = 0;
          double rawval = (target-current);
          last += rawval;
          double returnval = last*factor;
          return (returnval <= maxcap) ? ((returnval >= mincap) ? returnval : mincap) : maxcap;
      }
  };

  struct Derivative: public controlelement{
      double past = 0;
      Derivative(double fac, double min, double max):controlelement(fac, min, max){}

      //standard offset format: target-current. This class assumes the offset is in the correct direction already
      double compute(double target, double current){
          double rawval = target-current;
          double returnval = factor * (rawval-past);
          past = rawval;
          return (returnval <= maxcap) ? ((returnval >= mincap) ? returnval : mincap) : maxcap;
      }
  };

  //Modular control loop, computes values for a set of control elements
  struct control_loop{
      std::vector<controlelement*> elementset;
      double maxcap;
      double mincap;
      //if you dont like caps just set them really high, like +-INT_MAX or something
      control_loop(std::vector<controlelement*> val, double min, double max):elementset(val), mincap(min), maxcap(max){}
      double update(double target, double current){
          double returnval = 0;
          //no enhanced for to minimize risk of sketchy copying issues
          for (int i = 0; i < elementset.size(); i++){
              returnval += elementset[i]->compute(target,current);
          }
          return (returnval <= maxcap) ? ((returnval >= mincap) ? returnval : mincap) : maxcap;
      }
  };

#endif