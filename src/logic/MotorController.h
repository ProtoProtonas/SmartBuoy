#include "../actuators/MotorDriver.h"


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
    
    // TODO - move to provate. Public just for debugging
    double motor1Speed = 0.0;
    double motor2Speed = 0.0;

  private:
    // private variables
    // čia
    double offsetBetweenCompassAndMotors = 0.0;
    double headingBetweenMotor1AndNorth = 0.0;

    // private methods
    double _degreesToRadians(double degreeInput);

    // private objects
    MotorDriver _motorDriver;

};

#endif
