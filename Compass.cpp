#include "Compass.h"

Compass::Compass() :
  _compassSoftwareSerial(_softwareSerialRXPin, _softwareSerialTXPin)
{
  // constructor
  _compassSoftwareSerial.begin(9600);  
}

bool Compass::readHeadingFromSensor()
{
  _updateSuccess = false;
  
  _compassSoftwareSerial.write('1');
  if(_compassSoftwareSerial.available())
  {
    _hundreds = 4;
    while(_hundreds > 3)
    {
      _hundreds =      _compassSoftwareSerial.read() - 0x30;
    }
    _tens =            _compassSoftwareSerial.read() - 0x30;
    _units =           _compassSoftwareSerial.read() - 0x30;
    _updateSuccess = ( _compassSoftwareSerial.read() == 0x2E );
    _fraction =        _compassSoftwareSerial.read() - 0x30;
  }
  
  updateHeadingVariables();
  
  return _updateSuccess;
}

void Compass::updateHeadingVariables()
{
  //heading_ = 1000*_hundreds + 100*_tens + 10*_units + _fraction;
  heading_ = 100*_hundreds + 10*_tens + _units;
}
