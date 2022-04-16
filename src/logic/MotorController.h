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

    private:
        // private variables
        double headingBetweenMotor1AndNorth = 0.0;

        double motor1Speed = 0.0;
        double motor2Speed = 0.0;

        // private methods

        // private objects
        MotorDriver _motorDriver;

};

#endif
