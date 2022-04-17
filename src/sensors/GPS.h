

#ifndef GPS_H
#define GPS_H

#include <SoftwareSerial.h>
#include <stdint.h>
#include <TinyGPS++.h>
#include "../assistance/Averager.h"


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
        const short _averagerWindowLength = 20;

        // private objects
        SoftwareSerial _GPSSoftwareSerial;
        TinyGPSPlus _tinyGpsDecoder;
        Averager<double> currentLatitudeAverager;
        Averager<double> currentLongitudeAverager;
};

#endif
