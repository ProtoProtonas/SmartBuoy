#include "MotorDriver.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h" 
#include "pins_arduino.h"
#endif

#define MAX_ALLOWED_SPEED 256 // 0 to 1023
#define MAX_POSSIBLE_SPEED 1023

MotorDriver::MotorDriver()
{
  // constructor
  pinMode(_Motor1DirectionPin, OUTPUT);
  pinMode(_Motor2DirectionPin, OUTPUT);
}

void MotorDriver::setMotor1(double speedAndDirection)
{
  _setMotor1Direction(speedAndDirection > 0);
  _setMotor1Speed(uint16_t( abs( speedAndDirection*MAX_ALLOWED_SPEED ) ) );
  _updateMotor1Output();
}

void MotorDriver::setMotor2(double speedAndDirection)
{
  _setMotor2Direction(speedAndDirection > 0);
  _setMotor2Speed(uint16_t( abs( speedAndDirection*MAX_ALLOWED_SPEED ) ) );
  _updateMotor2Output();  
}

void MotorDriver::_setMotor1Speed(uint16_t newSpeed)
{
  if(newSpeed > MAX_POSSIBLE_SPEED)
  {
    _Motor1Speed = MAX_POSSIBLE_SPEED;
  }
  else
  {
    _Motor1Speed = newSpeed;
  }
}

void MotorDriver::_setMotor1Direction(bool isForward)
{
  _Motor1Direction = isForward;
}

void MotorDriver::_setMotor2Speed(uint16_t newSpeed)
{
  if(newSpeed > MAX_POSSIBLE_SPEED)
  {
    _Motor2Speed = MAX_POSSIBLE_SPEED;
  }
  else
  {
    _Motor2Speed = newSpeed;
  }
}

void MotorDriver::_setMotor2Direction(bool isForward)
{
  _Motor2Direction = isForward;
}

void MotorDriver::_updateMotor1Output()
{
  if(_Motor1Direction != _Motor1IsForward)
  {
    analogWrite(_Motor1PWMPin, _Motor1Speed);
  }
  else
  {
    analogWrite(_Motor1PWMPin,  MAX_ALLOWED_SPEED - _Motor1Speed);
  }
  digitalWrite(_Motor1DirectionPin,(_Motor1Direction == _Motor1IsForward));
}

void MotorDriver::_updateMotor2Output()
{
  if(_Motor2Direction != _Motor2IsForward)
  {
    analogWrite(_Motor2PWMPin, _Motor2Speed);
  }
  else
  {
    analogWrite(_Motor2PWMPin,  MAX_ALLOWED_SPEED - _Motor2Speed);
  }
  digitalWrite(_Motor2DirectionPin, (_Motor2Direction == _Motor2IsForward));
}

void MotorDriver::_stopMotor1()
{
  _Motor1Direction = true;
  _Motor1Speed = 0;
  _updateMotor1Output();
}

void MotorDriver::_stopMotor2()
{
  _Motor2Direction = true;
  _Motor2Speed = 0;
  _updateMotor2Output();
}

void MotorDriver::stopMotors()
{
  _stopMotor1();
  _stopMotor2();
}
