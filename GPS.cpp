#include "GPS.h"
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

GPS::GPS() :
  _GPSSoftwareSerial(_softwareSerialRXPin, _softwareSerialTXPin)
{
  // constructor
  _GPSSoftwareSerial.begin(9600);
}

void GPS::updateCoordinates()
{
  while(_GPSSoftwareSerial.available() > 0)
  {
    if(_tinyGpsDecoder.encode(_GPSSoftwareSerial.read()))
    {
      if(_tinyGpsDecoder.location.isValid())
      {
        instantaneousDeviceLatitude_ = _tinyGpsDecoder.location.lat();
        instantaneousDeviceLongitude_ = _tinyGpsDecoder.location.lng();
        
        currentLatitudeAverager.updateWithNewValue(instantaneousDeviceLatitude_);
        currentLongitudeAverager.updateWithNewValue(instantaneousDeviceLongitude_);
        isGPSActive_ = true;
      }
      else
      {
        isGPSActive_ = false;
      }
    }
  }
}

double GPS::getAveragedLatitude()
{
  return currentLatitudeAverager.getAverage();
}

double GPS::getAveragedLongitude()
{
  return currentLongitudeAverager.getAverage();
}
