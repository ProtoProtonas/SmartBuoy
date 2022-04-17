#include "MotorController.h"
#include "../assistance/Global.h"

#include <math.h>

MotorController::MotorController()
{
  // constructor
}

void MotorController::updateMotorsByHeading(double compassHeading)
{
    headingBetweenMotor1AndNorth = compassHeading - global.offsetBetweenCompassAndMotors;
    motor1Speed = sin(global.degreesToRadians(headingBetweenMotor1AndNorth));
    motor2Speed = cos(global.degreesToRadians(headingBetweenMotor1AndNorth));

    _motorDriver.setMotor1(motor1Speed);
    _motorDriver.setMotor2(motor2Speed);
}

void MotorController::cutMotors()
{
    _motorDriver.stopMotors();
}
