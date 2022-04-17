

#ifndef COMPASS_H
#define COMPASS_H

#include <stdint.h>
#include <SoftwareSerial.h>
#include "../assistance/Averager.h"


class Compass
{
    public:

        // constructor
        Compass();

        // class variables

        // public methods
        bool readHeadingFromSensor();
        void updateHeadingVariables();
        int getAveragedCompassHeading();

    private:
        // private constants
        bool _updateSuccess = true;
        int _hundreds, _tens, _units, _fraction;
        int _instantaneousHeading;
        short _averagerWindowLength = 5;

        // private objects
        SoftwareSerial _compassSoftwareSerial;
        Averager<int> _compassHeadingAverager;
};

#endif
