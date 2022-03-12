#include "MotorDriver.h"

#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

class MotorController
{
  public:
  
    // constructor
    MotorController();

    // class variables

    // public methods
    void updateMotorsByHeading(double compassHeading);
    void cutMotors();

  private:
    // private constants
    double offsetBetweenCompassAndMotors = 0.0;

    // private methods

    // private objects
    MotorDriver _motorDriver;

};

#endif
