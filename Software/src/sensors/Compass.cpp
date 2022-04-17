#include "Compass.h"
#include "../assistance/PinDefines.h"

Compass::Compass() :
    _compassSoftwareSerial(COMPASS_SOFTWARE_SERIAL_RX_PIN, COMPASS_SOFTWARE_SERIAL_TX_PIN),
    _compassHeadingAverager(_averagerWindowLength)
{
    // constructor
    _compassSoftwareSerial.begin(9600);  
}

bool Compass::readHeadingFromSensor()
{
    _updateSuccess = false;

    _compassSoftwareSerial.write('1');
    if(_compassSoftwareSerial.available())
    {
        // do not read garbage as hundreds cannot be more than 3 (359 degrees max)
        _hundreds = 4;
        while(_hundreds > 3)
        {
            _hundreds =    _compassSoftwareSerial.read() - 0x30;
        }
        _tens =            _compassSoftwareSerial.read() - 0x30;
        _units =           _compassSoftwareSerial.read() - 0x30;
        _updateSuccess = ( _compassSoftwareSerial.read() == 0x2E ); // should be decimal point
        _fraction =        _compassSoftwareSerial.read() - 0x30;
    }

    updateHeadingVariables();

    return _updateSuccess;
}

void Compass::updateHeadingVariables()
{
    if(_updateSuccess)
    {
        _instantaneousHeading = 1000*_hundreds + 100*_tens + 10*_units + _fraction + 5; // +5 for rounding
        _instantaneousHeading = _instantaneousHeading / 10;
        _compassHeadingAverager.updateWithNewValue(_instantaneousHeading);
    }
}

int Compass::getAveragedCompassHeading()
{
    return _compassHeadingAverager.getAverage();
}
