

#ifndef GPS_H
#define GPS_H

#include <SoftwareSerial.h>
#include <stdint.h>
#include <TinyGPS++.h>
#include "Average.h"


class GPS
{
  public:
  
    // constructor
    GPS();

    // class variables
    double instantaneousDeviceLatitude_;
    double instantaneousDeviceLongitude_;
    bool isGPSActive_ = false;

    // public methods
    void updateCoordinates();
    double getAveragedLatitude();
    double getAveragedLongitude();

  private:
    // private constants
    const uint8_t _softwareSerialRXPin = 2;
    const uint8_t _softwareSerialTXPin = 0;

    // private objects
    SoftwareSerial _GPSSoftwareSerial;
    TinyGPSPlus _tinyGpsDecoder;
    MovingAverage currentLatitudeAverager;
    MovingAverage currentLongitudeAverager;
};

#endif
