

#ifndef COMPASS_H
#define COMPASS_H

#include <stdint.h>
#include <SoftwareSerial.h>


class Compass
{
  public:
  
    // constructor
    Compass();

    // class variables
    uint32_t heading_;

    // public methods
    bool readHeadingFromSensor();
    void updateHeadingVariables();

  private:
    // private constants
    const uint8_t _softwareSerialRXPin = 5;
    const uint8_t _softwareSerialTXPin = 4;
    bool _updateSuccess = true;
    uint16_t _hundreds, _tens, _units, _fraction;

    // private objects
    SoftwareSerial _compassSoftwareSerial;
};

#endif
