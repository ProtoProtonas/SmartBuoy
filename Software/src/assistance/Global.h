

#ifndef GLOBAL_H
#define GLOBAL_H

class Global
{
    public:

        // constructor
        Global();

        // methods
        double degreesToRadians(double degreeInput);
        double radiansToDegrees(double radianInput);

        // variables
        /* USER ADJUSTABLE */
        const double targetDistanceError = 2.0;

        const double homeLatitude = 0.0;
        const double homeLongitude = 0.0;
        const double destinationLatitude = 10.0;
        const double destinationLongitude = 10.0;

        const unsigned long timeInBuoyPosition = 15; // minutes
        const unsigned long timeInBuoyPositionMillis = timeInBuoyPosition * 60 * 1000; // milliseconds



        /* CALIBRATION */
        double offsetBetweenCompassAndMotors = 0.0;
};

extern Global global;

#endif
