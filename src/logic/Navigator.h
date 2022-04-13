#include "../sensors/GPS.h"
#include "../sensors/Compass.h"

#ifndef NAVIGATOR_H
#define NAVIGATOR_H

class Navigator
{
  public:
  
    // constructor
    Navigator();

    // class variables
    double distanceToTarget_ = 999.999;
    double headingToTarget_ = 0.0;

    // public methods
    double getDistanceToTarget();
    double getHeadingToTarget();
    bool isGPSLocked();
    
    void updateDistanceToTarget();
    void updateHeadingToTarget();

  private:
    // private variables
    double _currentTargetLatitude;
    double _currentTargetLongitude;

    double _homeLatitude = 0.0;
    double _homeLongitude = 0.0;
    double _currentLatitude;
    double _currentLongitude;
    double _destinationLatitude = 10.0;
    double _destinationLongitude = 10.0;

    bool _compassUpdateSuccessful;
    bool _gpsUpdateSuccessful;

    uint16_t _compassHeadingToMagneticNorth = 0;    

    // private methods
    double _degreesToRadians(double degreeInput);
    double _radiansToDegrees(double radianInput);
    double _findBearing(double latitudePoint1, double longitudePoint1, double latitudePoint2, double longitudePoint2);
    double _findDistance(double latitudePoint1, double longitudePoint1, double latitudePoint2, double longitudePoint2);

    // private objects
    GPS _gps;
    Compass _compass;

    // private constants
    const double earthRadius = 6371000.0;

};

#endif
