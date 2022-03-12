#include "MotorController.h"

#include <math.h>

MotorController::MotorController()
{
  // constructor
}

double MotorController::_degreesToRadians(double degreeInput)
{
  return degreeInput * atan(1) / 45;
}

void MotorController::updateMotorsByHeading(double compassHeading)
{
  headingBetweenMotor1AndNorth = compassHeading - offsetBetweenCompassAndMotors;
  motor1Speed = sin(_degreesToRadians(headingBetweenMotor1AndNorth));
  motor2Speed = cos(_degreesToRadians(headingBetweenMotor1AndNorth));

  _motorDriver.setMotor1(motor1Speed);
  _motorDriver.setMotor2(motor2Speed);
}

void MotorController::cutMotors()
{
  _motorDriver.stopMotors();
}
