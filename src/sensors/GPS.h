

#ifndef GPS_H
#define GPS_H

#include <SoftwareSerial.h>
#include <stdint.h>
#include <TinyGPS++.h>
#include "../assistance/Average.h"


class GPS
{
    public:
  
        // constructor
        GPS();

        // class variables
        double instantaneousDeviceLatitude_;
        double instantaneousDeviceLongitude_;
        bool isGPSLocked_ = false;

        // public methods
        void updateCoordinates();
        double getAveragedLatitude();
        double getAveragedLongitude();

    private:
        // private constants

        // private objects
        SoftwareSerial _GPSSoftwareSerial;
        TinyGPSPlus _tinyGpsDecoder;
        MovingAverage currentLatitudeAverager;
        MovingAverage currentLongitudeAverager;
};

#endif
