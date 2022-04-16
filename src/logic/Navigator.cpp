#include "../assistance/Global.h"
#include "Navigator.h"
#include <math.h>


Navigator::Navigator()
{
  // constructor
}

double Navigator::_findBearing(double latitudePoint1, double longitudePoint1, double latitudePoint2, double longitudePoint2)
{
    double deltaLongitude = longitudePoint2 - longitudePoint1;
    double firstArgument = sin(deltaLongitude) * cos(latitudePoint2);
    double secondArgument = cos(latitudePoint1) * sin(latitudePoint2) - cos(deltaLongitude) * cos(latitudePoint2) * sin(latitudePoint1);
    if(longitudePoint1 > longitudePoint2)
    {
        return global.radiansToDegrees(atan2(firstArgument, secondArgument));
    }
    return global.radiansToDegrees(atan2(firstArgument, secondArgument));
}

double Navigator::_findDistance(double latitudePoint1, double longitudePoint1, double latitudePoint2, double longitudePoint2)
{
    double deltaLatitude = latitudePoint2 - latitudePoint1;
    double deltaLongitude = longitudePoint2 - longitudePoint1;
    double a = pow( sin(deltaLatitude / 2), 2) + cos(latitudePoint1) * cos(latitudePoint2) * pow( sin(deltaLongitude / 2), 2);
    double c = 2 * atan2( sqrt(a), sqrt(1-a) );
    return earthRadius * c;
}


void Navigator::updateDistanceToTarget()
{
  _gps.updateCoordinates();
  _currentLatitude = _gps.getAveragedLatitude();
  _currentLongitude = _gps.getAveragedLongitude();
  
  distanceToTarget_ = _findDistance(_currentLatitude, _currentLongitude, global.destinationLatitude, global.destinationLongitude);
}

void Navigator::updateHeadingToTarget()
{
  _compassUpdateSuccessful = _compass.readHeadingFromSensor();
  if(_compassUpdateSuccessful)
  {
    _compassHeadingToMagneticNorth = static_cast<double>(_compass.heading_);
    headingToTarget_ = _findBearing(_currentLatitude, _currentLongitude, global.destinationLatitude, global.destinationLongitude);
    headingToTarget_ = headingToTarget_ + _compassHeadingToMagneticNorth;
  }
}

double Navigator::getDistanceToTarget()
{
  return distanceToTarget_;
}

double Navigator::getHeadingToTarget()
{
  return headingToTarget_;
}

bool Navigator::isGPSLocked()
{
  return _gps.isGPSLocked_;
}
