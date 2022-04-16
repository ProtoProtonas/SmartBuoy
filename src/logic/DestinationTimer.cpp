#include "DestinationTimer.h"
#include "../assistance/Global.h"

DestinationTimer::DestinationTimer()
{
    // constructor
}

bool DestinationTimer::isItTimeToGoHome()
{
    bool timeToGoHome = false;
    if(_currentMillis - _timeWhenBuoyDestinationWasReached > global.timeInBuoyPositionMillis)
    {
        timeToGoHome = true;
    }
    return timeToGoHome;
}

void DestinationTimer::updateTime(unsigned long int currentMillis)
{
    _currentMillis = currentMillis;
}

void DestinationTimer::updateTimeWhenBuoyPositionWasReached()
{
    if(_destinationReachedTimeSetFlag == false)
    {
        _timeWhenBuoyDestinationWasReached = _currentMillis;
        _destinationReachedTimeSetFlag = true;
    }
}
