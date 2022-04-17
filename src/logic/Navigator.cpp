#include "../assistance/Global.h"
#include "Navigator.h"
#include <math.h>


Navigator::Navigator()
{
    // constructor
    _currentTargetLatitude  = global.destinationLatitude;
    _currentTargetLongitude = global.destinationLongitude;
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

void Navigator::updateDistanceToTarget(unsigned long int currentMillis)
{
    _gps.updateCoordinates();
    _currentLatitude = _gps.getAveragedLatitude();
    _currentLongitude = _gps.getAveragedLongitude();

    distanceToTarget_ = _findDistance(_currentLatitude, _currentLongitude, _currentTargetLatitude, _currentTargetLongitude);

    // handle changing target coordinates and how long to stay in buoy position
    _destinationTimer.updateTime(currentMillis);
    if(distanceToTarget_ < global.targetDistanceError)
    {
        _destinationTimer.updateTimeWhenBuoyPositionWasReached();
    }

    if(_destinationTimer.isItTimeToGoHome())
    {
        _currentTargetLatitude  = global.homeLatitude;
        _currentTargetLongitude = global.homeLongitude;
    }
}

void Navigator::updateHeadingToTarget()
{
    _compassUpdateSuccessful = _compass.readHeadingFromSensor();
    if(_compassUpdateSuccessful)
    {
        _compassHeadingToMagneticNorth = static_cast<double>(_compass.getAveragedCompassHeading());
        headingToTarget_ = _findBearing(_currentLatitude, _currentLongitude, _currentTargetLatitude, _currentTargetLongitude);
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
