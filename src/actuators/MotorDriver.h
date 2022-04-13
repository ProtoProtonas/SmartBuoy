

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <stdint.h>


class MotorDriver
{
  public:
  
    // constructor
    MotorDriver();

    // class variables

    // public methods
    void setMotor1(double speedAndDirection);
    void setMotor2(double speedAndDirection);

    void stopMotors();

  private:
    // private constants

    uint16_t       _Motor1Speed         = 0;
    bool           _Motor1Direction     = false;
    uint16_t       _Motor2Speed         = 0;
    bool           _Motor2Direction     = false;
    
    const uint8_t  _Motor1DirectionPin  = 14; // EN1
    const uint8_t  _Motor1PWMPin        = 12; // EN2
    const uint8_t  _Motor2DirectionPin  = 13; // EN3
    const uint8_t  _Motor2PWMPin        = 15; // EN4
    
    const bool     _Motor1IsForward     = true; // hardcoded constant for motor direction
    const bool     _Motor2IsForward     = false; // hardcoded constant for motor direction

    // private methods
    void _setMotor1Speed(uint16_t newSpeed);
    void _setMotor1Direction(bool isForward);
    
    void _setMotor2Speed(uint16_t newSpeed);
    void _setMotor2Direction(bool isForward);

    void _updateMotor1Output();
    void _updateMotor2Output();
    
    void _stopMotor1();
    void _stopMotor2();

    // private objects

};

#endif
