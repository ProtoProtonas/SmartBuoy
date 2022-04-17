#include "GPS.h"
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include "../assistance/PinDefines.h"

GPS::GPS() :
    _GPSSoftwareSerial(GPS_SOFTWARE_SERIAL_RX_PIN, GPS_SOFTWARE_SERIAL_TX_PIN)
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
                isGPSLocked_ = true;
            }
            else
            {
                isGPSLocked_ = false;
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
